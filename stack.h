#ifndef STACK_H
#define STACK_H

#define MAX_STACK 100

typedef char stack_entry;

typedef struct {
    int top;
    stack_entry entry[MAX_STACK];
} stack;

void stack_init(stack *s);
int stack_empty(stack *s);
int stack_full(stack *s);
void push(stack_entry item, stack *s);
void pop(stack_entry *item, stack *s);
int stack_size(stack *s);
stack_entry stack_bottom(stack *s);

stack_entry stack_top(stack *s);
void stack_destroy(stack *s);
void stack_copy(stack *source, stack *destination);

#endif