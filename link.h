#ifndef __LINK_H__
#define __LINK_H__

#define type int

typedef struct LNode{
    type data;
    LNode* next;
}LNode;

typedef LNode* LinkList;

LinkList InitLinkList();
void PushBackNode(const LinkList l, type x);
void InsertNode(const LinkList l, type x, int index);
void DeleteNode_index(const LinkList l, int index);
void DeleteNode_data(const LinkList l, type data);
LinkList ReverseList(LinkList pHead);
LinkList reverseBetween(LinkList head, int m, int n);
LinkList Merge(LinkList pHead1, LinkList pHead2);
LinkList sortInList(LinkList head);

#endif