#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 256
#define type int

typedef struct{
    type* data;
    int size;
    int front;
    int rear;
}queue;

void create_queue(queue* qu);
void destroy_queue(queue* qu);
void push_queue(queue* qu, type x);
int size_queue(queue* qu);
bool empty_queue(queue* qu);
type front_queue(queue* qu);
type back_queue(queue* qu);
type pop_queue(queue* qu);

#endif