#include "dynarr.h"

Array *array_new(void) {
  Array *array = malloc(sizeof(Array));
  array->len = 0;
  array->cap = 1;
  array->buffer = calloc(array->cap, sizeof(int));
  if(errno) {
    perror("Error in array_new");
    exit(EXIT_FAILURE);
  }
  return array;
}

void array_delete(Array *array) {
  free(array->buffer);
}

void array_resize(Array *array) {
  array->cap *= 2;
  array->buffer = reallocarray(array->buffer, array->cap, sizeof(int));
  if(errno) {
    perror("Error in array_resize");
    exit(EXIT_FAILURE);
  }
}

void array_push(Array *array, int elem) {
  if(array->len == array->cap) array_resize(array);
  array->buffer[array->len] = elem;
  array->len++;
}

void array_set(Array *array, size_t idx, int elem) {
  if(idx >= array->len) {
    fprintf(stderr, "Error in array_set: index=%ld, length=%ld\n", idx, array->len);
    exit(EXIT_FAILURE);
  }
  array->buffer[idx] = elem;
}


int array_get(Array *array, size_t idx) {
  if(idx >= array->len) {
    fprintf(stderr, "Error in array_get: index=%ld, length=%ld\n", idx, array->len);
    exit(EXIT_FAILURE);
  }
  return array->buffer[idx];
}

void array_copy(Array *dest, Array *src) {
  dest->buffer = reallocarray(dest->buffer, src->cap, sizeof(int));
  if(errno) {
    perror("Error in array_copy");
    exit(EXIT_FAILURE);
  }
  dest->cap = src->cap;
  dest->len = src->len;
  memcpy(dest->buffer, src->buffer, src->len*sizeof(int));
}

void array_print(Array *array) {
  printf("[");
  if(array->len > 0) {
    for(size_t idx = 0; idx < array->len-1; idx++) printf("%d, ", array_get(array, idx));
    printf("%d", array_get(array, array->len-1));
  }
  printf("]\n");
}
