#include "safealloc.h"

void *safe_malloc(size_t size) {
  void *ptr = malloc(size);
  if(errno) {
    perror("");
    exit(EXIT_FAILURE);
  }
  return ptr;
}

void *safe_calloc(size_t nmemb, size_t size) {
  void *ptr = calloc(nmemb, size);
  if(errno) {
    perror("");
    exit(EXIT_FAILURE);
  }
  return ptr;
}

void *safe_realloc(void *ptr, size_t size) {
  void *retptr = realloc(ptr, size);
  if(errno) {
    perror("");
    exit(EXIT_FAILURE);
  }
  return retptr;
}

void *safe_reallocarray(void *ptr, size_t nmemb, size_t size) {
  void *retptr = reallocarray(ptr, nmemb, size);
  if(errno) {
    perror("");
    exit(EXIT_FAILURE);
  }
  return retptr;
}
