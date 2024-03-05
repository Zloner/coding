#include "vector.h"

void create_vector(vector* v){

    v->capacity = INIT_CAPACITY;
    v->size = 0;
    v->data = (type*)malloc(v->capacity * sizeof(type));
    if(v->data == NULL){
        printf("run out of memory\n");
    }
    v->begin = v->data;
    v->end = v->data + 1;
}

long size_vector(vector* v){
    return v->size;
}

long capacity_vector(vector* v){
    return v->capacity;
}

type* begin_vector(vector* v){
    return v->begin;
}

type* end_vector(vector* v){
    return v->end;
}

void reserve_vector(vector* v, int n){
    if(n > v->capacity){
        v->data = (type*)realloc(v->data, sizeof(type) * n);
        v->capacity = n;
    }
    else{
        return;
    }
}

void resize_vector(vector* v, int n){
    if(n < v->size){
        for(int i = n; i < v->size; i++)
            v->data[i] = EMPTY_VALUE;
        
        v->size = n;
    }
    else if(n >= v->size && n <= v->capacity){
        for(int i = v->size; i < n; i++)
            v->data[i] = EMPTY_VALUE;

        v->size = n;
    }
    else if(n > v->capacity){
        reserve_vector(v, n);
        for(int i = v->size; i < n; i++)
            v->data[i] = EMPTY_VALUE;
        
        v->size = n;
    }
}

void push_vector(vector* v, int x){
    if(v->size == v->capacity){
        reserve_vector(v, 2*v->capacity);
    }
    v->data[v->size] = x;
    v->end++;
    v->size++;
}

void insert_vector(vector* v, int index, int x){
    if(v->size == v->capacity){
        reserve_vector(v, 2*v->capacity);
    }
    int i;
    for(i = v->size; i > index; i--)
        v->data[i] = v->data[i-1];
    v->data[i] = x;
    v->end++;
    v->size++;
}

void clear_vector(vector* v){
    for(int i = 0; i < v->size; i++)
        v->data[i] = EMPTY_VALUE;
    v->size = 0;

    v->begin = v->data;
    v->end = v->begin + 1;
}

void destroy_vector(vector* v){
    free(v->data);
    v->data = NULL;
    v->begin = NULL;
    v->end = NULL;

    v->size = 0;
    v->capacity = 0;
}

bool empty_vector(vector* v){
    return !v->size;
}