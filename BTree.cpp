#include "BTree.h"

void InitBTree(TreeRoot root){
    root = (TreeRoot)malloc(sizeof(TNode));
    root->data = 0;
    root->lchild = NULL;
    root->rchild = NULL;
}

TNode* CreateNode(int x){
    TNode* n = (TNode*)malloc(sizeof(TNode));
    n->data = x;
    n->lchild = NULL;
    n->rchild = NULL;
    return n;
}

void AddNode(TreeRoot root, int data){
    TNode* p = root;
    while(p->lchild != NULL || p->rchild != NULL){
        if(data > p->data && p->rchild != NULL)
            p = p->rchild;
        else if(data <= p->data && p->lchild != NULL)
            p = p->lchild;
    }
    TNode* tmp = CreateNode(data);
    if(data > p->data)
        p->rchild = tmp;
    else if(data <= p->data)
        p->lchild = tmp;
}

TNode* FindNode(TreeRoot root, int data){
    TNode* p = root;
    while(p->data != data){
        if(data > p->data)
            p = p->rchild;
        else if(data <= p->data)
            p = p->lchild;
        if(p == NULL)
            break;
    }
    return p;
}

void DeleteNode(TreeRoot root, int data){
    TNode* p = FindNode(root, data);
    while(p->rchild != NULL){
        p->data = p->rchild->data;
        p = p->rchild;
    }
    free(p);
}

int Getsize(TreeRoot root){
    if(!root)
        return 0;
    int x = Getsize(root->lchild);
    int y = Getsize(root->rchild);
    return x + y + 1;
}

void preOrder(TreeRoot root, int * arr){
    if(!root)
        return;
    static int i = 0;
    arr[i++] = root->data;
    preOrder(root->lchild, arr);
    preOrder(root->rchild, arr);
}

void inOrder(TreeRoot root, int * arr){
    if(!root)
        return;
    static int i = 0;
    inOrder(root->lchild, arr);
    arr[i++] = root->data;
    inOrder(root->rchild, arr);
}

void posOrder(TreeRoot root, int * arr){
    if(!root)
        return;
    static int i = 0;
    posOrder(root->lchild, arr);
    posOrder(root->rchild, arr);
    arr[i++] = root->data;
}




