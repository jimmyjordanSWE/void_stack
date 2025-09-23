#include "void_stack.h"
#include <stdio.h>
#include <stdlib.h>

/* todo implement missing functions

IMPLEMENT:
    init()
    destroy_stack()
    is_empty()
    clear()

todo add error handling with enums
use void_stack_result_t as return type and then get data out from the functions
by passing in a pointer. claude: "This is the standard pattern for professional
C APIs where you need both return data and error information."
 */

size_t void_stack_get_stack_depth(const void_stack *_list) {
  if (!_list)
    return 0;
  return _list->depth;
}

void_stack_result_t void_stack_push(void_stack *_stack, const void *_payload) {
  if (!_stack)
    return VOID_STACK_ERROR_NULL_POINTER;

  node *new_node = malloc(sizeof(node)); /* Create new node */
  if (new_node == NULL)
    return VOID_STACK_ERROR_MEMORY;

  new_node->payload = _payload;  /* Set new nodes data */
  new_node->next = _stack->head; /* set the old head to the new nodes next */
  _stack->depth++;               /* Keep track of number of nodes in stack */
  _stack->head = new_node;       /* Set new node as new head in list */
  return VOID_STACK_SUCCESS;
}

const void *void_stack_peek(const void_stack *_list) {
  if (!_list || !_list->head)
    return NULL;

  return _list->head->payload;
}

void *void_stack_pop(void_stack *_list) {
  if (!_list || _list->depth == 0 || !_list->head)
    return NULL;

  void *free_this_node =
      _list->head; /* Save the pointers before we free its memory */
  void *address_to_payload =
      (void *)_list->head
          ->payload; /* ok to cast to void from const void because we are
                        returning the data to the original caller  */

  _list->head = _list->head->next; /* set the new head */
  _list->depth--;

  free(free_this_node);

  return address_to_payload;
}
