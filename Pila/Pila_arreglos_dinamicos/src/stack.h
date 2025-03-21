#ifndef __STACK_H__
#define __STACK_H__
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef int Data;

typedef struct {
    Data *data;
    int top;
    int len;
} Stack;

Stack stack_create(int len);
void stack_push(Stack*, Data);
Data stack_pop(Stack*);
bool stack_is_empty(Stack*);
void stack_delete(Stack *);
void stack_empty(Stack*);
void stack_print(Stack *);

#endif // __STACK_H__