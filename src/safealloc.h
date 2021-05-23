#ifndef SAFEALLOC_H
#define SAFEALLOC_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void *safe_malloc(size_t size);
void *safe_calloc(size_t nmemb, size_t size);
void *safe_realloc(void *ptr, size_t size);
void *safe_reallocarray(void *ptr, size_t nmemb, size_t size);

#endif
