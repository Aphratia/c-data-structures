#ifndef DYNARR_H
#define DYNARR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct _Array {
  int *buffer;
  size_t len;
  size_t cap;
} Array;

Array *array_new(void);
void array_delete(Array *array);
void array_resize(Array *array);
void array_push(Array *array, int elem);
void array_set(Array *array, size_t idx, int elem);
int array_get(Array *array, size_t idx);
void array_copy(Array *dest, Array *src);
void array_print(Array *array);

#endif
