#include "queue.h"

void create_queue(queue* qu){
    qu = (queue*)malloc(sizeof(queue));
    qu->data = (type*)malloc(MAX_SIZE * sizeof(type));
    if(qu->data == NULL){
        printf("run out of memory\n");
        return;
    }
    qu->front = 0;
    qu->rear = 0;
    qu->size = 0;
}

void destroy_queue(queue* qu){
    free(qu->data);
    qu->data = NULL;
    qu->front = 0;
    qu->rear = 0;
    qu->size = 0;
    free(qu);
}

void push_queue(queue* qu, type x){
    if(qu->size == MAX_SIZE){
        printf("Queue is full!\n");
        return;
    }
    qu->data[qu->rear] = x;
    qu->rear = (qu->rear + 1) % MAX_SIZE;
    qu->size++;
}

type pop_queue(queue* qu){
    if(empty_queue(qu)){
        printf("Queue is empty\n");
        return;
    }
    qu->data[qu->front] = 0;
    qu->front = (qu->front + 1) % MAX_SIZE;
    qu->size--; 
}

int size_queue(queue* qu){
    return qu->size;
}

bool empty_queue(queue* qu){
    return !qu->size;
}

type front_queue(queue* qu){
    return qu->data[qu->front];
}

type back_queue(queue* qu){
    return qu->data[qu->rear];
}