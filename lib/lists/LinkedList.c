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

void linkedList_PrintRecursive(Node *node, int maxIndex)
{
    printf("%d ", *node->dataPointer);
    if (node->index < maxIndex)
        linkedList_PrintRecursive(node->next, maxIndex);
}

/* ---------------------------------------------- */

void linkedList_Add(LinkedList *list, ListT data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->index = list->size ++;
    newNode->dataPointer = malloc(sizeof(ListT));
    *newNode->dataPointer = data;
    newNode->prev = list->lastNode;
    newNode->next = NULL;
    if (list->lastNode != NULL)
        list->lastNode->next = newNode;
    list->lastNode = newNode;
}

void linkedList_Insert(LinkedList *list, int index, ListT data)
{
    if (index > list->size - 1 || index < 0)
        return;
    Node *newNode = malloc(sizeof(Node));
    Node *currentNode = linkedList_Find(list, index);
    newNode->index = currentNode->index;
    newNode->dataPointer = malloc(sizeof(ListT));
    *newNode->dataPointer = data;
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

ListT* linkedList_Get(LinkedList *list, int index)
{
    if (index > list->size - 1 || index < 0)
        return NULL;
    return linkedList_Find(list, index)->dataPointer;
}

ListT linkedList_GetValue(LinkedList *list, int index)
{
    if (index > list->size - 1 || index < 0)
        return 0;
    return *linkedList_Find(list, index)->dataPointer;
}

void linkedList_SetValue(LinkedList *list, int index, ListT value)
{
    if (index > list->size - 1 || index < 0)
        return;
    Node *node = linkedList_Find(list, index);
    node->dataPointer = malloc(sizeof(ListT));
    *node->dataPointer = value;
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

LinkedList* linkedList_New()
{
    LinkedList *linkedList = malloc(sizeof(LinkedList));
    linkedList->size = 0;
    linkedList->lastNode = NULL;
    return linkedList;
}

void linkedList_Print(LinkedList *list)
{
    Node *start = linkedList_Find(list, 0);
    linkedList_PrintRecursive(start, list->size - 1);
    printf("\n");
}