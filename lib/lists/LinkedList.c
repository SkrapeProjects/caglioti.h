#include <LinkedList.h>
/**
 *  PRIVATE FUNCTIONS
 */

Node* linkedList_FindRecursive(Node *node, int index, int dir)
{
    if (node->index == index)
        return node;
    else if (dir)
        return linkedList_FindRecursive(node->next, index, dir);
    else
        return linkedList_FindRecursive(node->prev, index, dir);
}

void linkedList_PrintRecursive(Node *node, int maxIndex)
{
    printf("%c ", *node->dataPointer);
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
    newNode->prev = list->currentNode;
    newNode->next = NULL;
    if (list->currentNode != NULL)
        list->currentNode->next = newNode;
    list->currentNode = newNode;
}

Node* linkedList_Find(LinkedList *list, int index)
{
    if (list->currentNode->index > index)
        return linkedList_FindRecursive(list->currentNode->prev, index, 0);
    else
        return linkedList_FindRecursive(list->currentNode->next, index, 1);
}

ListT* linkedList_Get(LinkedList *list, int index)
{
    return linkedList_Find(list, index)->dataPointer;
}

ListT linkedList_GetValue(LinkedList *list, int index)
{
    return *linkedList_Find(list, index)->dataPointer;
}

void linkedList_SetValue(LinkedList *list, int index, ListT value)
{
    Node *node = linkedList_Find(list, index);
    node->dataPointer = malloc(sizeof(ListT));
    *node->dataPointer = value;
}

void linkedList_Remove(LinkedList *list, int index)
{
    Node *node = linkedList_Find(list, index);
    Node *originalNode = node;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    list->currentNode = node->next;
    int i;
    for (i = node->next->index; i < list->size; i ++)
    {
        node = node->next;
        node->index --;
    }
    list->size --;
    free(originalNode);
}

LinkedList* linkedList_New()
{
    LinkedList *linkedList = malloc(sizeof(LinkedList));
    linkedList->size = 0;
    linkedList->currentNode = NULL;
    return linkedList;
}

void linkedList_Print(LinkedList *list)
{
    Node *start = linkedList_Find(list, 0);
    linkedList_PrintRecursive(start, list->size - 1);
    printf("\n");
}