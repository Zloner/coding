#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdio.h>
#include <stdlib.h>

#define type int
#define INIT_CAPACITY 5
#define EMPTY_VALUE 0

typedef struct{
    type * data;
    //int ele_size;
    long size;
    long capacity;
    type * begin;
    type * end;
}vector;

void create_vector(vector* v);
long size_vector(vector* v);
long capacity_vector(vector* v);
type* begin_vector(vector* v);
type* end_vector(vector* v);
void reserve_vector(vector* v, int n);
void resize_vector(vector* v, int n);
void push_vector(vector* v, int x);
void insert_vector(vector* v, int index, int x);
void clear_vector(vector* v);
void destroy_vector(vector* v);
bool empty_vector(vector* v);

#endif