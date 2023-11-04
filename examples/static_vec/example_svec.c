#include "vec.h"
#include <stdio.h>
#include <stdlib.h>

void info_svec(int *a) {
  usz len = svec_length(a);

  printf("svec data: ");
  for(mut_usz i = 0; i < len; ++i) {
    printf("%d ", svec_at(a, i));
  }
  puts("");
}

int main(void) {
  int *a = svec_init(int);
  svec_push(a, 20);
  svec_push(a, 66);

  printf("svec length: %lu\n", svec_length(a));
  printf("svec data: a[0] = %d, a[1] = %d\n", svec_at(a, 0), svec_at(a, 1));

  svec_pop(a);

  info_svec(a);

  svec_push(a, 42);
  svec_push(a, 42);
  svec_push(a, 42);

  svec_at(a, 2) = 10;

  info_svec(a);

  free(a);
  return EXIT_SUCCESS;
}
