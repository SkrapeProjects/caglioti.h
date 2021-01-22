#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

typedef int ListDataType;

typedef struct __SLinkedNode {
    ListDataType value;
    struct __SLinkedNode* next;
} SLinkedNode;

typedef SLinkedNode *SLinkedList;

int sLinkedList_GetListSize(SLinkedList);
SLinkedNode* sLinkedList_GetEntry(SLinkedList, int);
void sLinkedList_InsertAtIndex(SLinkedList, ListDataType, int);
void sLinkedList_RemoveIndex(SLinkedList, int);
void sLinkedList_PushBack(SLinkedList, ListDataType);
void sLinkedList_PushFront(SLinkedList, ListDataType);
SLinkedList sLinkedList_InitList();
int sLinkedList_Compare(SLinkedList, int, int);
int sLinkedList_ContainsRepetitions(SLinkedList);

#endif