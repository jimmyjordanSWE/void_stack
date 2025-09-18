# void_stack

A simple stack implementation in C using void pointers.

⚠️ **Work in Progress** - Several functions are still missing.

## Usage

```c
#include "void_stack.h"

// Initialize
void_stack stack = {NULL, 0};

// Push data
int data = 42;
void_stack_push(&stack, &data);

// Pop data  
void *result = void_stack_pop(&stack);
printf("%d\n", *(int*)result);  // prints: 42
```

## Functions

- `void_stack_push()` - Add element
- `void_stack_pop()` - Remove element  
- `void_stack_peek()` - Look at top element
- `void_stack_get_stack_depth()` - Get stack size

## Important

- Stack stores **pointers**, not copies
- You manage your own data's memory
- Each push/pop allocates/frees internal nodes

## License

MIT License - Jimmy Jordan (2025)
