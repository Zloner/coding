#include <stdlib.h>
#include "link.h"

LinkList InitLinkList(){
    LinkList l = (LNode*)malloc(sizeof(LNode));
    l->data = 0;
    l->next = NULL;
    return l;
}

void PushBackNode(const LinkList l, type x){
    LNode* p = l;
    while (p->next != NULL){
        p = p->next;
    }
    LNode* tmp = (LNode*)malloc(sizeof(LNode));
    tmp->data = x;
    tmp->next = NULL;
    p->next = tmp;
}

void InsertNode(const LinkList l, type x, int index){
    LNode * p = l;
    int count = 0, flag = 0;

    while(count < index - 1){
        p = p->next;
        count++;
        if (p->next == NULL){
            flag = 1;
            break;
        }
    }
    //insert
    if(!flag){
        LNode* tmp = (LNode*)malloc(sizeof(LNode));
        tmp->data = x;
        LNode* pnext = p->next;
        p->next = tmp;
        tmp->next = pnext;
    }
    //pushback
    else{
        LNode* tmp = (LNode*)malloc(sizeof(LNode));
        tmp->data = x;
        tmp->next = NULL;
        p->next = tmp;
    }
}

void DeleteNode_index(const LinkList l, int index){
    int count = 0; 
    LNode* p = l;
    while(count < index - 1){
        p = p->next;
        count++;
        if(p->next == NULL)
            return;
    }

    LNode* pnt = p->next;
    p->next = p->next->next;
    free(pnt);
}

void DeleteNode_data(const LinkList l, type data){
    LNode* p = l->next;
    LNode* before = l;
    while(p->data == data){
        if(p->next == NULL)
            return;
        p = p->next;
        before = before->next;
    }
    before->next = p->next;
    free(p);
}

LinkList ReverseList(LinkList pHead){
    if (pHead->next == NULL || pHead == NULL) {
        return pHead;
    }

    LinkList p, q;
    p = pHead;

    while (p) {
        if (p->next->next == NULL) {
            q = p->next;
            break;
        }
        p = p->next;
    }

    q->next = NULL;
    p->next = NULL;

    while (pHead) {
        p = pHead;
        pHead = pHead->next;
        p->next = q->next;
        q->next = p;
    }
    return q;
}

LinkList reverseBetween(LinkList head, int m, int n){
    if(head->next == NULL||head == NULL)
        return head;
    
    LinkList h = (LinkList)malloc(sizeof(LNode));

    h->next=head;
    LinkList p, temp, cur = h;

    for(int i = 0; i < m-1; i++)
        cur = cur->next;

    temp = cur;
    LinkList q;
    cur = cur->next;
    q = cur;

    for(int i = 0; i < n-m+1; i++)
    {
        p = cur;
        cur = cur->next;
        p->next = temp->next;
        temp->next = p;
    }
    q->next = cur;
    return h;
}

LinkList Merge(LinkList pHead1, LinkList pHead2){

    LinkList rhead = (LinkList)malloc(sizeof(LNode)); 
    rhead->data = 0;
    LinkList p = rhead;

    while (pHead1 && pHead2) {  
        if (pHead1->data <= pHead2->data) {
            p->next = pHead1;    
            pHead1 = pHead1->next;
        } 
        else {
            p->next = pHead2;
            pHead2 = pHead2->next;
        }
        p = p->next; 
    }
    
    p->next = pHead1 ? pHead1 : pHead2;  
    return rhead;
}

LinkList sortInList(LinkList head){
    LNode *p1, *p2, *p3;
    int tmp;
 
    for(p1 = head; p1 != NULL; p1 = p1->next){
        for(p2 = p1; p2 != NULL; p2 = p2->next){
            if(p1->data > p2->data){
            tmp = p2->data;
            p2->data = p1->data;
            p1->data = tmp;
            }
        }
    }
    return head;
}