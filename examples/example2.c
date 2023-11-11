#include "vec.h"
#include "wtfc.h"
#include <stdio.h>
#include <stdlib.h>

void print_i32(vec_item item) {
  mut_i32 *v = item;

  printf("%" PRIi32 " ", *v);
}

void row_i32_print(vec_item item) {
  mut_i32 *v = item;

  usz len = svec_length(v);
  for (mut_usz i = 0; i < len; ++i) {
    printf("%" PRIi32 " ", svec_at(v, i));
  }
  puts("");
}

void strange_modify_row_i32(vec_item item) {
  mut_i32 *v = item;

  usz len = svec_length(v);
  for (mut_usz i = 0; i < len; ++i) {
    svec_at(v, i) += 42;
  }
}

void print_matrix(vec matrix) { vec_println(matrix, row_i32_print); }

vec_interface vec_row_i32_interface = {.item_size = svec_size_by_type(mut_i32),
                                       .destroy = free};

int main(void) {
  usz matrix_size = 18;
  mut_vec matrix = vec_init(vec_row_i32_interface);
  for (mut_usz i = 0; i < matrix_size; ++i) {

    mut_i32 *row = svec_init(mut_i32);
    for (mut_usz j = 0; j < matrix_size; ++j) {

      mut_i32 e = rand() % 2 == 0;
      svec_push(row, (iptr)e); // need to cast int ptr
    }

    vec_push(matrix, row);
  }

  puts("Matrix:");
  print_matrix(matrix);
  puts("Matrix modify:");
  vec_modify(matrix, 2, strange_modify_row_i32);
  print_matrix(matrix);

  puts("Matrix copy:");
  mut_vec matrix_copy = vec_copy(matrix);
  print_matrix(matrix);

  vec_destroy(matrix);
  vec_destroy(matrix_copy);
  return EXIT_SUCCESS;
}
