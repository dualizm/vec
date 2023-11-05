/**
 * @file vec.h
 * @author ezeire (ognieff@yandex.ru)
 * @brief Simple vector implementation
 * @version 0.2
 * @date 2023-10-22
 *
 * @copyright Copyright (c) 2023 ezeire
 *
 */

#pragma once
#include "wtfc.h"

struct vec;

/**
 * @typedef void * vec_item
 * @brief A generic item type used in the vector.
 */
typedef void *vec_item;

/**
 * @struct  mut_vec
 * @brief A mutable vector structure.
 */
typedef struct vec *mut_vec;

/**
 * @struct  vec
 * @brief An immutable vector structure.
 */
typedef struct vec const *vec;

/**
 * @struct  vec_interface
 * @brief Interface for creating a vector
 */
typedef struct vec_interface {
  mut_usz item_size; /**< he size of the item. */
  void (*destroy)(
      vec_item item); /**< A function pointer to destroy the item. */
} const vec_interface;

/**
 * @struct  svec_mdi
 * @brief Structure to hold metadata information for a vector.
 */
struct _svec_mdi {
  mut_usz length;    /**< Length of the vector. */
  mut_usz alloc;     /**< Allocated memory for the vector. */
  mut_usz type_size; /**< Size of each element in the vector. */
};

// allocation functions

/**
 * @brief Initializes a new vector.
 *
 * @param interface The interface for the vector items.
 * @return Returns a new vector.
 */
mut_vec vec_init(vec_interface interface);

/**
 * @brief Destroys a vector and frees its memory.
 *
 * @param self The vector to destroy.
 */
void vec_destroy(void *self);

/**
 * @brief Creates a slice of a vector.
 *
 * @param self The vector.
 * @param first_index The index of the first element in the slice.
 * @param second_index The index of the last element in the slice.
 * @return Returns a new vector containing the slice, or NULL if the indices are
 * invalid.
 */
mut_vec vec_slice(vec self, usz first_index, usz second_index);

/**
 * @brief Creates a copy of a vector.
 *
 * @param self The vector to copy.
 * @return Returns a new vector that is a copy of the original vector.
 */
mut_vec vec_copy(vec self);

/**
 * @brief Applies a function to each item in the vector.
 *
 * @param self The vector to apply the function to.
 * @param apply The function to apply to each item.
 * @return A new vector with the applied function.
 */
vec vec_map(vec self, void (*apply)(vec_item item));

/**
 * @brief Applies a function to each pair of items from two vectors.
 *
 * @param self The first vector.
 * @param other The second vector.
 * @param apply The function to apply to each pair of items.
 * @return A new vector with the applied function.
 */
vec vec_map2(vec self, vec other,
             void (*apply)(vec_item item_a, vec_item item_b));

// information functions

/**
 * @brief Check if the vector is empty.
 *
 * @param self The vector to check.
 * @return True if the vector is empty, false otherwise.
 */
bool vec_empty(vec self);

/**
 * @brief Get the length of the vector.
 *
 * @param self The vector to get the length of.
 * @return The length of the vector.
 */
mut_usz vec_length(vec self);

/**
 * @brief Prints the elements of a vector.
 *
 * This function prints the elements of a vector using the provided print
 * function.
 *
 * @param self The vector to be printed.
 * @param print The function used to print each element of the vector.
 */
void vec_print(vec self, void (*print)(vec_item item));

/**
 * @brief Prints the elements of a vector with a newline at the end.
 *
 * This function prints the elements of a vector using the provided print
 * function, and adds a newline character at the end.
 *
 * @param self The vector to be printed.
 * @param print The function used to print each element of the vector.
 */
void vec_println(vec self, void (*print)(vec_item item));

// modification functions

/**
 * @brief Applies a function to each item in a vector.
 *
 * @param self The vector.
 * @param apply The function to apply to each item.
 */
void vec_foreach(vec self, void (*apply)(vec_item item));

/**
 * @brief Applies a function to each pair of elements from two vectors.
 *
 * @param self The first vector.
 * @param other The second vector.
 * @param apply The function to apply to each pair of elements.
 */
void vec_foreach2(vec self, vec other,
                  void (*apply)(vec_item item_a, vec_item item_b));

/**
 * @brief Removes the last element from the vector.
 *
 * @param self The vector.
 * @return True if the element was successfully removed, false otherwise.
 */
bool vec_pop(mut_vec self);

/**
 * @brief Sets the value of an element at a specific index in the vector.
 *
 * @param self The vector.
 * @param index The index of the element to set.
 * @param item The new value for the element.
 * @return True if the element was successfully set, false otherwise.
 */
bool vec_set(mut_vec self, usz index, vec_item item);

/**
 * @brief Modifies an element at a specific index in the vector using a
 * function.
 *
 * @param self The vector.
 * @param index The index of the element to modify.
 * @param apply The function to apply to the element.
 * @return True if the element was successfully modified, false otherwise.
 */
bool vec_modify(mut_vec self, usz index, void (*apply)(vec_item item));

/**
 * @brief Adds an element to the end of the vector.
 *
 * @param self The vector.
 * @param item The element to add.
 */
void vec_push(mut_vec self, vec_item item);

/**
 * @brief Initializes an svec data structure.
 *
 * This function initializes an svec data structure with the specified size.
 *
 * @param size The size of each element in the svec.
 * @return A pointer to the initialized svec data structure.
 */
void *_svec_init(usz size);

/**
 * @brief Pushes a value into a dynamic array.
 *
 * This function pushes a value into a dynamic array represented by the
 * `svec_ptr` pointer. If there is enough space in the array, the value is
 * copied into the array. Otherwise, the array is reallocated to double its size
 * and the value is copied into the new space.
 *
 * @param svec_ptr A pointer to the dynamic array.
 * @param value The value to be pushed into the array.
 */
void _svec_push(void *svec_ptr, void *value);

/**
 * @brief Macro for initializing an svec data structure.
 *
 * This macro is a convenient way to initialize an svec data structure with the
 * specified type.
 *
 * @param TYPE The type of each element in the svec.
 * @return A pointer to the initialized svec data structure.
 */
#define svec_init(TYPE) _svec_init(sizeof(TYPE))

/**
 * @brief Pushes a value onto the vector.
 *
 * @param SVEC_PTR The pointer to the vector.
 * @param VALUE The value to push onto the vector.
 */
#define svec_push(SVEC_PTR, VALUE)                                             \
  do {                                                                         \
    void *temp_ptr = ((void *)(VALUE));                                        \
    _svec_push((SVEC_PTR), &temp_ptr);                                         \
  } while (0)

/**
 * @brief Pops a value from the vector.
 *
 * @param SVEC_PTR The pointer to the vector.
 */
#define svec_pop(SVEC_PTR)                                                     \
  do {                                                                         \
    struct _svec_mdi *data = (void *)(SVEC_PTR);                               \
    if (data->length == 0) {                                                   \
      break;                                                                   \
    }                                                                          \
    data->length -= 1;                                                         \
  } while (0)

/**
 * @brief Returns the length of the vector.
 *
 * @param SVEC_PTR The pointer to the vector.
 * @return The length of the vector.
 */
#define svec_length(SVEC_PTR) ((struct _svec_mdi *)(void *)(SVEC_PTR))->length

/**
 * @brief Check if the given svec is empty.
 *
 * @param SVEC_PTR Pointer to the svec structure.
 * @return true if the svec is empty, false otherwise.
 */
#define svec_empty(SVEC_PTR) ((struct _svec_mdi *)(SVEC_PTR))->length == 0

/**
 * @brief Returns the value at the specified index in the vector.
 *
 * @param SVEC_PTR The pointer to the vector.
 * @param INDEX The index of the value to retrieve.
 * @return The value at the specified index.
 */
#define svec_at(SVEC_PTR, INDEX)                                               \
  ((char *)(SVEC_PTR) +                                                        \
   sizeof(                                                                     \
       struct _svec_mdi))[(INDEX) *                                            \
                          ((struct _svec_mdi *)(void *)(SVEC_PTR))->type_size]

/**
 * @brief Calculate the size of a svec by type.
 *
 * This macro calculates the size of a svec based on the provided type.
 *
 * @param TYPE The type of the vector elements.
 * @return The size of the vector in bytes.
 */
#define svec_size_by_type(TYPE) ((usz)sizeof(TYPE) * sizeof(struct _svec_mdi))
