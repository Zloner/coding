#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 256
#define type int

typedef struct{
    type* data;
    int top;
    int size;
}stack;

void create_stack(stack* st);
void destroy_stack(stack* st);
void push_stack(stack* st, type x);
void pop_stack(stack* st);
int size_stack(stack* st);
bool empty_stack(stack* st);
type top_stack(stack* st);
void expand_stack(stack* st);

#endif