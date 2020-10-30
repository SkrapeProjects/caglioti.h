#include "LinkedList.h"
/**
 *  PRIVATE FUNCTIONS
 */

Node* linkedList_FindRecursive(Node *node, int index)
{
    if (node->index == index)
        return node;
    else
        return linkedList_FindRecursive(node->prev, index);
}

void linkedList_LoadDataToNode(Node *node, int dataSize, void *data)
{
    int i;
    for (i = 0; i < dataSize; i ++)
        *((char *) node->dataPointer + i) = *((char *) data + i);
}

/* ---------------------------------------------- */

void linkedList_Add(LinkedList *list, void *data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->index = list->size ++;
    newNode->dataPointer = malloc(list->dataSize);
    linkedList_LoadDataToNode(newNode, list->dataSize, data);
    newNode->prev = list->lastNode;
    newNode->next = NULL;
    if (list->lastNode != NULL)
        list->lastNode->next = newNode;
    list->lastNode = newNode;
}

void linkedList_Insert(LinkedList *list, int index, void *data)
{
    if (index > list->size - 1 || index < 0)
        return;
    Node *newNode = malloc(sizeof(Node));
    Node *currentNode = linkedList_Find(list, index);
    newNode->index = currentNode->index;
    newNode->dataPointer = malloc(list->dataSize);
    linkedList_LoadDataToNode(newNode, list->dataSize, data);
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

Node* linkedList_Find(LinkedList *list, int index)
{
    if (index > list->size - 1 || index < 0)
        return NULL;
    linkedList_FindRecursive(list->lastNode, index);
}

void* linkedList_Get(LinkedList *list, int index)
{
    if (index > list->size - 1 || index < 0)
        return NULL;
    return linkedList_Find(list, index)->dataPointer;
}

void linkedList_Set(LinkedList *list, int index, void *value)
{
    if (index > list->size - 1 || index < 0)
        return;
    Node *node = linkedList_Find(list, index);
    linkedList_LoadDataToNode(node, list->dataSize, value);
}

void linkedList_Remove(LinkedList *list, int index)
{
    if (index > list->size - 1 || index < 0)
        return;
    Node *node = linkedList_Find(list, index);
    Node *originalNode = node;
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
    free(originalNode);
}

LinkedList* linkedList_New(int dataTypeSize)
{
    LinkedList *linkedList = malloc(sizeof(LinkedList));
    linkedList->size = 0;
    linkedList->dataSize = dataTypeSize;
    linkedList->lastNode = NULL;
    return linkedList;
}