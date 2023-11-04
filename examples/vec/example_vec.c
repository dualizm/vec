#include "vec.h"
#include <stdio.h>
#include <stdlib.h>

void print_i32(vec_item item) {
  mut_i32 *v = item;

  printf("%" PRIi32 " ", *v); 
}

void strange_modify_i32(vec_item item) {
  mut_i32 *v = item;

  *v += 42;
}

void vec_columns_plus_i32(vec_item item_a, vec_item item_b) {
  mut_i32 *v1 = item_a;
  mut_i32 *v2 = item_b;

  *v1 += *v2;
}

void vec_columns_sub_i32(vec_item item_a, vec_item item_b) {
  mut_i32 *v1 = item_a;
  mut_i32 *v2 = item_b;

  *v1 -= *v2;
}

vec_interface vec_i32_interface = {
    .item_size = sizeof(mut_i32), .destroy = free, .print = print_i32};

int main(void) {
  mut_vec v1 = vec_init(vec_i32_interface);
  for (mut_usz i = 0; i < 8; ++i) {
    mut_i32 *e = malloc(sizeof *e);
    if (e) {
      *e = rand() % 43 + 23;
      vec_push(v1, e);
    }
  }

  puts("Vec1 :");
  vec_println(v1);

  mut_vec v2 = vec_copy(v1);
  puts("Vec2 :");
  vec_foreach(v2, strange_modify_i32);
  vec_println(v2);

  puts("Vec sum:");
  vec_foreach2(v1, v2, vec_columns_plus_i32);
  vec_println(v1);

  vec_destroy(v2);
  vec_destroy(v1);
  return EXIT_SUCCESS;
}
