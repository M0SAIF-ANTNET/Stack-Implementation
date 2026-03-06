#include <stdio.h>
#include "stack.h"

// Answer 4 & 15: Print stack without changing it (User Level)
void print_stack(stack *s) {
    stack temp;
    stack_entry x;
    stack_init(&temp);

    while(!stack_empty(s)) {
        pop(&x, s);
        printf("%c ", x);
        push(x, &temp);
    }

    while(!stack_empty(&temp)) {
        pop(&x, &temp);
        push(x, s);
    }
    printf("\n");
}

// Answer 10: Return first element (User Level)
stack_entry user_stack_bottom(stack *s) {
    return stack_bottom(s);
}

// Answer 11: Return copy of last element (User Level)
stack_entry user_stack_top(stack *s) {
    return stack_top(s);
}

// Answer 12: Destroy stack (User Level)
void user_stack_destroy(stack *s) {
    stack_destroy(s);
}

// Answer 13: Copy stack to another (User Level)
void user_stack_copy(stack *source, stack *dest) {
    stack_copy(source, dest);
}

// Answer 14: Return stack size (User Level)
int user_stack_size(stack *s) {
    return stack_size(s);
}

// Answer 16: Check balanced parentheses
int check_parentheses(char *expr) {
    stack s;
    stack_entry x;
    stack_init(&s);

    for(int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if(ch == '(' || ch == '{' || ch == '[') {
            push(ch, &s);
        } else if(ch == ')' || ch == '}' || ch == ']') {
            if(stack_empty(&s)) return 0;
            char top = stack_top(&s);
            pop(&x, &s);
            if((ch == ')' && top != '(') ||
               (ch == '}' && top != '{') ||
               (ch == ']' && top != '[')) return 0;
        }
    }
    return stack_empty(&s);
}

int main() {
    stack s;
    stack_entry x;
    int choice;
    char expr[100];

    stack_init(&s);

    while(1) {
        printf("\n1. Push\n2. Pop\n3. Stack Size\n4. Print Stack\n5. Bottom Element\n6. Top Element\n7. Destroy Stack\n8. Copy Stack\n9. Check Parentheses\n10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            if(!stack_full(&s)) {
                printf("Enter char to push: ");
                scanf(" %c", &x);
                push(x, &s);
            } else {
                printf("Stack full!\n");
            }
        } else if(choice == 2) {
            if(!stack_empty(&s)) {
                pop(&x, &s);
                printf("Popped: %c\n", x);
            } else {
                printf("Stack empty!\n");
            }
        } else if(choice == 3) {
            printf("Stack size: %d\n", stack_size(&s));
        } else if(choice == 4) {
            printf("Stack contents: ");
            print_stack(&s);
        } else if(choice == 5) {
            if(!stack_empty(&s))
                printf("Bottom element: %c\n", user_stack_bottom(&s));
        } else if(choice == 6) {
            if(!stack_empty(&s))
                printf("Top element: %c\n", user_stack_top(&s));
        } else if(choice == 7) {
            user_stack_destroy(&s);
            printf("Stack destroyed.\n");
        } else if(choice == 8) {
            stack copy;
            user_stack_copy(&s, &copy);
            printf("Stack copied. Copy contents: ");
            print_stack(&copy);
        } else if(choice == 9) {
            printf("Enter expression: ");
            scanf("%s", expr);
            if(check_parentheses(expr))
                printf("Balanced\n");
            else
                printf("Not balanced\n");
        } else if(choice == 10) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}