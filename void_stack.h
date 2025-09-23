#ifndef VOID_STACK_H
#define VOID_STACK_H

#include <stdlib.h>

/* todo can this be hidden in the .c file? */
typedef enum {
  VOID_STACK_SUCCESS = 0,             /* Operation completed successfully */
  VOID_STACK_ERROR_NULL_POINTER = -1, /* NULL pointer passed as argument */
  VOID_STACK_ERROR_MEMORY = -2,       /* Memory allocation failure */
  VOID_STACK_ERROR_EMPTY = -3         /* Operation on empty stack */
} void_stack_result_t;

/* todo can this also be hidden in the .c file? */
typedef struct {
  void *next;
  const void *payload;
} node;

typedef struct {
  node *head;
  size_t depth;
} void_stack;

size_t void_stack_get_stack_depth(const void_stack *stack);

void_stack_result_t void_stack_push(void_stack *stack, const void *payload);

const void *void_stack_peek(const void_stack *stack);

void *void_stack_pop(void_stack *stack);

#endif /* VOID_STACK_H */