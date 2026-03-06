#include "stack.h"

// Answer 1: Initialize stack
void stack_init(stack *s) {
    s->top = 0;
}

// Answer 1: Check if stack is empty
int stack_empty(stack *s) {
    return s->top == 0;
}

// Answer 1: Check if stack is full
int stack_full(stack *s) {
    return s->top == MAX_STACK;
}

// Answer 1: Push element
void push(stack_entry item, stack *s) {
    s->entry[s->top++] = item;
}

// Answer 1: Pop element
void pop(stack_entry *item, stack *s) {
    *item = s->entry[--s->top];
}

// Answer 3 & 9: Return stack size
int stack_size(stack *s) {
    return s->top;
}

// Answer 5: Return first element entered
stack_entry stack_bottom(stack *s) {
    return s->entry[0];
}

// Answer 6: Return copy of last element
stack_entry stack_top(stack *s) {
    return s->entry[s->top - 1];
}

// Answer 7: Destroy stack
void stack_destroy(stack *s) {
    s->top = 0;
}

// Answer 8: Copy stack to another
void stack_copy(stack *source, stack *destination) {
    destination->top = source->top;
    for(int i = 0; i < source->top; i++) {
        destination->entry[i] = source->entry[i];
    }
}