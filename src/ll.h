#ifndef LL_H
#define LL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "safealloc.h"

typedef struct _LinkedNode LinkedNode;

typedef struct _LinkedNode {
  int val;
  LinkedNode *next;
} LinkedNode;

typedef struct _LinkedList {
  LinkedNode *start;
  LinkedNode *end;
  size_t len;
} LinkedList;

LinkedList *ll_new(void);
void ll_delete(LinkedList *ll);
void ll_push(LinkedList *ll, size_t idx, int elem);
void ll_push_end(LinkedList *ll, int elem);
void ll_pop(LinkedList *ll, size_t idx);
void ll_set(LinkedList *ll, size_t idx, int elem);
int ll_get(LinkedList *ll, size_t idx);
void ll_print(LinkedList *ll);

#endif
