#include "vec.h"
#include "wtfc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VEC_INITIAL_ALLOC_SIZE 8

#define OUT_OF_MEMORY                                                          \
  do {                                                                         \
    fprintf(stderr, "%s:%d - out of memory\n", __FILE__, __LINE__);            \
    exit(1);                                                                   \
  } while (0)

/**
 * @struct vec
 * @brief A dynamic array implementation.
 */
struct vec {
  struct vec_interface
      interface;   /**< Interface for working with vector elements */
  mut_usz length;  /**< The current length of the vector. */
  mut_usz alloc;   /**< The current allocated size of the vector. */
  void **elements; /**< The array of elements. */
};

/**
 * @brief Checks if there is space available in the vector.
 *
 * @param self The vector.
 * @return Returns true if there is space available, false otherwise.
 */
static bool _is_space(vec self) { return self->alloc != self->length; }

/**
 * @brief Resizes the vector if necessary.
 *
 * @param self The vector.
 * @return Returns true if the resize was successful, false otherwise.
 */
static void _resize(mut_vec self) {
  usz new_size = sizeof *self->elements * self->alloc * (self->length / 2);
  void **new_elements = realloc(self->elements, new_size);
  if (new_elements == NULL) {
    OUT_OF_MEMORY;
  }

  self->alloc *= self->length / 2;
  self->elements = new_elements;
}

// allocation functions
mut_vec vec_init(vec_interface interface) {
  void **elements = malloc(sizeof *elements * VEC_INITIAL_ALLOC_SIZE);
  if (elements == NULL) {
    OUT_OF_MEMORY;
  }

  mut_vec vector = malloc(sizeof *vector);
  if (vector == NULL) {
    OUT_OF_MEMORY;
  }

  *vector = (struct vec){.elements = elements,
                         .alloc = VEC_INITIAL_ALLOC_SIZE,
                         .length = 0,
                         .interface = interface};

  return vector;
}

void vec_destroy(void *self) {
  mut_vec v = self;
  vec_foreach(v, v->interface.destroy);
  free(v->elements);
  free(v);
}

mut_vec vec_slice(vec self, usz first_index, usz second_index) {
  if (first_index >= self->length || second_index > self->length ||
      first_index >= second_index) {
    return NULL;
  }

  mut_vec slice = vec_init(self->interface);
  for (mut_usz i = first_index; i < second_index; ++i) {
    vec_item new_item = malloc(self->interface.item_size);
    if (new_item) {
      memcpy(new_item, self->elements[i], self->interface.item_size);
      vec_push(slice, new_item);
    } else {
      OUT_OF_MEMORY;
    }
  }

  return slice;
}

mut_vec vec_copy(vec self) { return vec_slice(self, 0, self->length); }

vec vec_map(vec self, void (*apply)(vec_item item)) {
  mut_vec new_vec = vec_copy(self);
  vec_foreach(new_vec, apply);
  return new_vec;
}

vec vec_map2(vec self, vec other,
             void (*apply)(vec_item item_a, vec_item item_b)) {
  mut_vec new_vec = vec_copy(self);
  vec_foreach2(new_vec, other, apply);
  return new_vec;
}

// information functions
bool vec_empty(vec self) { return self->length == 0; }

mut_usz vec_length(vec self) { return self->length; }

void vec_print(vec self, void (*print)(vec_item item)) {
  vec_foreach(self, print);
}

void vec_println(vec self, void (*print)(vec_item item)) {
  vec_foreach(self, print);
  puts("");
}

// modification functions
void vec_foreach(vec self, void (*apply)(vec_item item)) {
  if (apply) {
    usz len = self->length;
    for (mut_usz i = 0; i < len; ++i) {
      apply(self->elements[i]);
    }
  }
}

void vec_foreach2(vec self, vec other,
                  void (*apply)(vec_item item_a, vec_item item_b)) {
  if (apply) {
    usz len = self->length;
    for (mut_usz i = 0; i < len; ++i) {
      apply(self->elements[i], other->elements[i]);
    }
  }
}

bool vec_pop(mut_vec self) {
  if (vec_empty(self))
    return false;

  self->interface.destroy(self->elements[self->length - 1]);
  --self->length;
  return true;
}

bool vec_set(mut_vec self, usz index, vec_item item) {
  if (index >= self->length || !item) {
    return false;
  }

  self->interface.destroy(self->elements[index]);
  self->elements[index] = item;
  return true;
}

bool vec_modify(mut_vec self, usz index, void (*apply)(vec_item item)) {
  if (index >= self->length) {
    return false;
  }

  apply(self->elements[index]);
  return true;
}

void vec_push(mut_vec self, vec_item item) {
  if (_is_space(self)) {
    self->elements[self->length] = item;
    ++self->length;
  } else {
    _resize(self);
    self->elements[self->length] = item;
    ++self->length;
  }
}

void *_svec_init(usz size) {
  struct _svec_mdi *data = malloc(size * VEC_INITIAL_ALLOC_SIZE + sizeof *data);
  if (data == NULL) {
    OUT_OF_MEMORY;
  }

  data->length = 0;
  data->alloc = VEC_INITIAL_ALLOC_SIZE;
  data->type_size = size;
  return data;
}

void _svec_push(void *svec_ptr, void *value) {
  struct _svec_mdi *data = svec_ptr;

  if ((data->alloc - data->length) > 0) {
    memcpy((char *)(data + 1) + data->length * data->type_size, value,
           data->type_size);
    data->length += 1;
  } else {
    void *new_data =
        realloc(svec_ptr, data->type_size * data->alloc * 2 + sizeof *data);

    if (new_data == NULL) {
      OUT_OF_MEMORY;
    }

    data = new_data;
    data->alloc *= 2;
    data->length += 1;
    svec_ptr = (void *)data;
    memcpy((char *)(data + 1) + (data->length - 1) * data->type_size, value,
           data->type_size);
  }
}
