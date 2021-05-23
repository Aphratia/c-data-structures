#include "ll.h"

LinkedList *ll_new(void) {
  LinkedList *ll = safe_malloc(sizeof(LinkedList));
  ll->start = NULL;
  ll->end = NULL;
  ll->len = 0;
}

void ll_delete(LinkedList *ll) {
  LinkedNode *curr = ll->start;
  for(size_t i = 0; i < ll->len; i++) {
    LinkedNode *next = curr->next;
    if(next == NULL) printf("Got to the end in delete !\n");
    free(curr);
    curr = next;
  }
  free(ll);
}

void ll_push(LinkedList *ll, size_t idx, int elem) {
  if(idx > ll->len) {
    fprintf(stderr, "Error in ll_push: index=%ld, length=%ld\n", idx, ll->len);
    exit(EXIT_FAILURE);
  }
  if(idx == ll->len) {
    ll_push_end(ll, elem);
  } else if(idx == 0) {
    LinkedNode *node_new = safe_malloc(sizeof(LinkedNode));
    node_new->val = elem;
    node_new->next = ll->start;
    ll->start = node_new;
    ll->len++;
  } else {
    LinkedNode *node_idx = ll->start;
    LinkedNode *node_new = safe_malloc(sizeof(LinkedNode));
    for(size_t i = 0; i < idx-1; i++) node_idx = node_idx->next;
    node_new->val = elem;
    node_new->next = node_idx->next;
    node_idx->next = node_new;
    ll->len++;
  }
}

void ll_push_end(LinkedList *ll, int elem) {
  LinkedNode *node = safe_malloc(sizeof(LinkedNode));
  node->val = elem;
  node->next = NULL;
  if(ll->len == 0) {
    ll->start = node;
    ll->end = node;
    ll->len++;
  } else {
    ll->end->next = node;
    ll->end = node;
    ll->len++;
  }
}

void ll_pop(LinkedList *ll, size_t idx) {
  if(idx >= ll->len) {
    fprintf(stderr, "Error in ll_pop: index=%ld, length=%ld\n", idx, ll->len);
    exit(EXIT_FAILURE);
  }
  LinkedNode *curr = ll->start;
  if(idx == 0 && ll->len == 1) {
    ll->start = NULL;
    ll->end = NULL;
    ll->len = 0;
    free(curr);
  } else if(idx == 0) {
    ll->start = curr->next;
    ll->len--;
    free(curr);
  } else {
    LinkedNode *prev = curr;
    for(size_t i = 0; i < idx; i++) {
      prev = curr;
      curr = curr->next;
    }
    prev->next = curr->next;
    ll->len--;
    if(curr == ll->end) ll->end = prev;
    free(curr);
  }
}

void ll_set(LinkedList *ll, size_t idx, int elem) {
  if(idx >= ll->len) {
    fprintf(stderr, "Error in ll_get: index=%ld, length=%ld\n", idx, ll->len);
    exit(EXIT_FAILURE);
  }
  if(idx == ll->len-1) ll->end->val = elem;
  LinkedNode *curr = ll->start;
  for(size_t i = 0; i < idx-1; i++) curr = curr->next;
  curr->val = elem;
}

int ll_get(LinkedList *ll, size_t idx) {
  if(idx >= ll->len) {
    fprintf(stderr, "Error in ll_get: index=%ld, length=%ld\n", idx, ll->len);
    exit(EXIT_FAILURE);
  }
  if(idx == ll->len-1) return ll->end->val;
  LinkedNode *curr = ll->start;
  for(size_t i = 0; i < idx-1; i++) curr = curr->next;
  return curr->val;
}

void ll_print(LinkedList *ll) {
  printf("[");
  if(ll->len > 0) {
    LinkedNode *curr = ll->start;
    for(size_t idx = 0; idx < ll->len-1; idx++) {
      printf("%d, ", curr->val);
      curr = curr->next;
    }
    printf("%d", curr->val);
  }
  printf("]\n");
}
