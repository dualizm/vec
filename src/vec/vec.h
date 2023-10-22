/**
 * @file vec.h
 * @author ezeire (ognieff@yandex.ru)
 * @brief Simple vector implementation
 * @version 0.1
 * @date 2023-10-22
 * 
 * @copyright Copyright (c) 2023 ezeire
 * 
 */

#pragma once
#include "wtfc.h"

struct vec;

/**
 * @typedef void *vec_item
 * @brief A generic item type used in the vector.
 */
typedef void *vec_item;

/**
 * @struct mut_vec
 * @brief A mutable vector structure.
 */
typedef struct vec *mut_vec;

/**
 * @struct vec
 * @brief An immutable vector structure.
 */
typedef struct vec const *vec;

/**
 * @struct ivec_item
 * @brief Interface for creating a vector
 * @var ivec_item::item_size The size of the item.
 * @var ivec_item::print A function pointer to print the item.
 * @var ivec_item::destroy A function pointer to destroy the item.
 */
struct ivec_item {
  mut_usize item_size;
  void (*print)(vec_item item);
  void (*destroy)(vec_item item);
};

// allocation functions

/**
 * @brief Initializes a new vector.
 *
 * @param interface The interface for the vector items.
 * @return Returns a new vector.
 */
mut_vec vec_init(struct ivec_item interface);

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
 * @return Returns a new vector containing the slice, or NULL if the indices are invalid.
 */
mut_vec vec_slice(vec self, usize first_index, usize second_index);

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
vec vec_map2(vec self, vec other, void (*apply)(vec_item item_a, vec_item item_b));

// information functions

/**
 * @brief Check if the vector is empty.
 *
 * @param self The vector to check.
 * @return True if the vector is empty, false otherwise.
 */
bool vec_empty(vec self);

/**
 * @brief Get the size of the vector.
 *
 * @param self The vector to get the size of.
 * @return The size of the vector.
 */
usize vec_size(vec self);

/**
 * @brief Print the elements of the vector.
 *
 * @param self The vector to print.
 */
void vec_print(vec self);

/**
 * @brief Print the elements of the vector followed by a newline.
 *
 * @param self The vector to print.
 */
void vec_println(vec self);

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
void vec_foreach2(vec self, vec other, void (*apply)(vec_item item_a, vec_item item_b));

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
bool vec_set(mut_vec self, usize index, vec_item item);

/**
 * @brief Modifies an element at a specific index in the vector using a function.
 *
 * @param self The vector.
 * @param index The index of the element to modify.
 * @param apply The function to apply to the element.
 * @return True if the element was successfully modified, false otherwise.
 */
bool vec_modify(mut_vec self, usize index, void (*apply)(vec_item item));

/**
 * @brief Adds an element to the end of the vector.
 *
 * @param self The vector.
 * @param item The element to add.
 * @return True if the element was successfully added, false otherwise.
 */
bool vec_push(mut_vec self, vec_item item);
