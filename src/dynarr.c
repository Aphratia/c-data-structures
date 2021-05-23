#include "dynarr.h"

DynamicArray *dynarr_new(void) {
  DynamicArray *array = safe_malloc(sizeof(DynamicArray));
  array->len = 0;
  array->cap = 1;
  array->buffer = safe_calloc(array->cap, sizeof(int));
  return array;
}

void dynarr_delete(DynamicArray *array) {
  free(array->buffer);
  free(array);
}

void dynarr_resize(DynamicArray *array) {
  array->cap *= 2;
  array->buffer = safe_reallocarray(array->buffer, array->cap, sizeof(int));
}

void dynarr_push(DynamicArray *array, int elem) {
  printf("%ld, %ld\n", array->len, array->cap);
  if(array->len == array->cap) dynarr_resize(array);
  array->buffer[array->len] = elem;
  array->len++;
}

void dynarr_set(DynamicArray *array, size_t idx, int elem) {
  if(idx >= array->len) {
    fprintf(stderr, "Error in dynarr_set: index=%ld, length=%ld\n", idx, array->len);
    exit(EXIT_FAILURE);
  }
  array->buffer[idx] = elem;
}


int dynarr_get(DynamicArray *array, size_t idx) {
  if(idx >= array->len) {
    fprintf(stderr, "Error in dynarr_get: index=%ld, length=%ld\n", idx, array->len);
    exit(EXIT_FAILURE);
  }
  return array->buffer[idx];
}

void dynarr_copy(DynamicArray *dest, DynamicArray *src) {
  dest->buffer = safe_reallocarray(dest->buffer, src->cap, sizeof(int));
  dest->cap = src->cap;
  dest->len = src->len;
  memcpy(dest->buffer, src->buffer, src->len*sizeof(int));
}

void dynarr_print(DynamicArray *array) {
  printf("[");
  if(array->len > 0) {
    for(size_t idx = 0; idx < array->len-1; idx++) printf("%d, ", dynarr_get(array, idx));
    printf("%d", dynarr_get(array, array->len-1));
  }
  printf("]\n");
}
