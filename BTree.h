#ifndef __BRTEE_H__
#define __BRTEE_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    TNode* lchild, * rchild;
}TNode;

typedef TNode* TreeRoot;

#endif