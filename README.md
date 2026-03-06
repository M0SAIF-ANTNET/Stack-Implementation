## Overview

This project explores the **Stack data structure** at both **implementation** and **user level**.  
It is implemented in **C language** using an **array-based stack**. The project includes:

- `stack.h` → Header file with type definitions and function prototypes.
- `stack.c` → Implementation of the stack functions (Answers 1,3,5,6,7,8,9).
- `test.c` → User-level program with menu and additional functionalities (Answers 2,4,10,11,12,13,14,15,16).

The stack supports basic operations like `push`, `pop`, `check empty/full`, as well as advanced features like **printing without changing the stack**, **copying stacks**, and **checking balanced parentheses**.

---

## Files

### 1. `stack.h`
- Defines the **stack_entry type** (`char`) and the `stack` struct.
- Declares all **implementation-level functions**.
- Allows other files to include it and use the stack functions without knowing the internal details.

### 2. `stack.c`
- Implements the functions declared in `stack.h`.
- Functions include:
  - `stack_init` → Initialize the stack.
  - `stack_empty` / `stack_full` → Check if stack is empty/full.
  - `push` / `pop` → Add or remove elements.
  - `stack_size` → Return the current size of the stack.
  - `stack_bottom` / `stack_top` → Return first or last element.
  - `stack_destroy` → Empty the stack.
  - `stack_copy` → Copy one stack to another.

### 3. `test.c`
- Provides **user-level interface** with a menu-driven program.
- Functions include:
  - `print_stack` → Print contents without modifying the stack.
  - `user_stack_bottom` / `user_stack_top` → Access first or last element.
  - `user_stack_destroy` → Clear the stack.
  - `user_stack_copy` → Copy stack.
  - `user_stack_size` → Return stack size.
  - `check_parentheses` → Verify if parentheses, brackets, and braces are balanced.
- Implements the **menu** for interaction with the stack:
  1. Push
  2. Pop
  3. Stack Size
  4. Print Stack
  5. Bottom Element
  6. Top Element
  7. Destroy Stack
  8. Copy Stack
  9. Check Parentheses
  10. Exit

---

## How to Compile and Run

### Step 1: Compile the stack library
gcc -c stack.c
### Step 2: Compile and link with the test program
gcc test.c stack.o -o test
### Step 3: Run the program
./test or .\test
