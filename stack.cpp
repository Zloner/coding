#include "stack.h"

void create_stack(stack* st){
    st = (stack*)malloc(sizeof(stack));
    st->data = (type*)malloc(sizeof(type) * MAX_SIZE);
    if(st->data == NULL){
        printf("run out of memory\n");
    }
    st->size = 0;
    st->top = 0;
}

void destroy_stack(stack* st){
    free(st->data);
    st->top = 0;
    st->size = 0;
    free(st);
}

void push_stack(stack* st, type x){
    if(st->size == MAX_SIZE){
        printf("stack is full\n");
        return;
    }
    st->data[st->top] = x;
    st->top++;
    st->size++;
}

void pop_stack(stack* st){
    if(empty_stack(st)){
        printf("stack is empty\n");
        return;
    }
    st->top--;
    st->size--;
}

int size_stack(stack* st){
    return st->size;
}

bool empty_stack(stack* st){
    return !st->size;
}

type top_stack(stack* st){
    return st->data[st->top-1];
}