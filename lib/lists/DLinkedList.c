#include "DLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  PRIVATE FUNCTIONS
 */

DLinkedNode* dLinkedList_FindRecursive(DLinkedNode *node, int index)
{
    if (node->index == index)
        return node;
    else
        return dLinkedList_FindRecursive(node->prev, index);
}

void dLinkedList_LoadDataToNode(DLinkedNode *node, int dataSize, void *data)
{
    int i;
    for (i = 0; i < dataSize; i ++)
        *((char *) node->dataPointer + i) = *((char *) data + i);
}

/* ---------------------------------------------- */

void dLinkedList_Add(DLinkedList *list, void *data)
{
    DLinkedNode *newNode = malloc(sizeof(DLinkedNode));
    newNode->index = list->size ++;
    newNode->dataPointer = malloc(list->dataSize);
    dLinkedList_LoadDataToNode(newNode, list->dataSize, data);
    newNode->prev = list->lastNode;
    newNode->next = NULL;
    if (list->lastNode != NULL)
        list->lastNode->next = newNode;
    list->lastNode = newNode;
}

void dLinkedList_Insert(DLinkedList *list, int index, void *data)
{
    if (index > list->size - 1 || index < 0)
        return;
    DLinkedNode *newNode = malloc(sizeof(DLinkedNode));
    DLinkedNode *currentNode = dLinkedList_Find(list, index);
    newNode->index = currentNode->index;
    newNode->dataPointer = malloc(list->dataSize);
    dLinkedList_LoadDataToNode(newNode, list->dataSize, data);
    newNode->prev = currentNode->prev;
    newNode->next = currentNode;
    currentNode->prev->next = newNode;
    currentNode->prev = newNode;
    list->size ++;
    int i;
    for (i = currentNode->next->index; i < list->size; i ++)
    {
        currentNode->index ++;
        currentNode = currentNode->next;
    }
}

DLinkedNode* dLinkedList_Find(DLinkedList *list, int index)
{
    if (index > list->size - 1 || index < 0)
        return NULL;
    dLinkedList_FindRecursive(list->lastNode, index);
}

void* dLinkedList_Get(DLinkedList *list, int index)
{
    if (index > list->size - 1 || index < 0)
        return NULL;
    return dLinkedList_Find(list, index)->dataPointer;
}

void dLinkedList_Set(DLinkedList *list, int index, void *value)
{
    if (index > list->size - 1 || index < 0)
        return;
    DLinkedNode *node = dLinkedList_Find(list, index);
    dLinkedList_LoadDataToNode(node, list->dataSize, value);
}

void dLinkedList_Remove(DLinkedList *list, int index)
{
    if (index > list->size - 1 || index < 0)
        return;
    DLinkedNode *node = dLinkedList_Find(list, index);
    DLinkedNode *originalNode = node;
    if (index > 0)
        node->prev->next = node->next;
    if (index == list->size - 1)
        list->lastNode = node->prev;
    else {
        node->next->prev = node->prev;
        int i;
        for (i = node->next->index; i < list->size; i ++)
        {
            node = node->next;
            node->index --;
        }
    }
    list->size --;
    //free(originalNode->dataPointer);
    free(originalNode);
}

DLinkedList* dLinkedList_New(int dataTypeSize)
{
    DLinkedList *linkedList = malloc(sizeof(DLinkedList));
    linkedList->size = 0;
    linkedList->dataSize = dataTypeSize;
    linkedList->lastNode = NULL;
    return linkedList;
}