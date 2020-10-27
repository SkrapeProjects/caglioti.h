#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef char ListT;

typedef struct __Node {
    ListT *dataPointer;
    struct __Node *next;
    struct __Node *prev;
    int index;
} Node;

typedef struct {
    Node *currentNode;
    int size;
} LinkedList;

LinkedList* linkedList_New();
void linkedList_Add(LinkedList *list, ListT data);
void linkedList_Remove(LinkedList *list, int index);
Node* linkedList_Find(LinkedList *list, int index);
ListT* linkedList_Get(LinkedList *list, int index);
ListT linkedList_GetValue(LinkedList *list, int index);
void linkedList_SetValue(LinkedList *list, int index, ListT value);
void linkedList_Print(LinkedList *list);

#endif