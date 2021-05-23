#ifndef DYNARR_H
#define DYNARR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "safealloc.h"

typedef struct _DynamicArray {
  int *buffer;
  size_t len;
  size_t cap;
} DynamicArray;

DynamicArray *dynarr_new(void);
void dynarr_delete(DynamicArray *array);
void dynarr_resize(DynamicArray *array);
void dynarr_push(DynamicArray *array, int elem);
void dynarr_set(DynamicArray *array, size_t idx, int elem);
int dynarr_get(DynamicArray *array, size_t idx);
void dynarr_copy(DynamicArray *dest, DynamicArray *src);
void dynarr_print(DynamicArray *array);

#endif
