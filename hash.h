#ifndef __HASH_H__
#define __HASH_H__

#include <stdio.h>
#include <stdlib.h>
#include "link.h"

#define MAX_SIZE 128

typedef struct{
    LinkList table[MAX_SIZE];
    int size;
}Hash;

void HashInit(Hash* hash);
void HashInsert(Hash* hash, type data);
void HashDelete(Hash* hash, type data);
LinkList HashFind(Hash* hash, type data);

#endif