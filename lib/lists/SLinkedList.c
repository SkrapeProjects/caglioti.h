#include "SLinkedList.h"
#include <stdlib.h>

int sLinkedList_GetListSize(SLinkedList list)
{
    int i = 0;
    while (list->next != NULL)
    {
        list = list->next;
        ++ i;
    }
    return i;
}

SLinkedNode* sLinkedList_GetEntry(SLinkedList list, int index)
{
    SLinkedNode *head = list;
    int i;
    for (i = 0; i <= index; i ++)
    {
        if (head->next == NULL)
            return NULL;
        head = head->next;  
    }
    return head;
}

void sLinkedList_InsertAtIndex(SLinkedList list, ListDataType value, int index)
{
    SLinkedNode *entry;
    if (index > sLinkedList_GetListSize(list))
        return;
    else
        entry = sLinkedList_GetEntry(list, index - 1);
    SLinkedNode *newEntry = malloc(sizeof(SLinkedNode));
    newEntry->value = value;
    newEntry->next = entry->next;
    entry->next = newEntry;
}

void sLinkedList_RemoveIndex(SLinkedList list, int index)
{
    SLinkedNode *prevEntry, *toRemove;
    if (index > sLinkedList_GetListSize(list) - 1)
        return;
    else
    {
        prevEntry = sLinkedList_GetEntry(list, index - 1);
        toRemove = sLinkedList_GetEntry(list, index);
    }
    prevEntry->next = toRemove->next;
    free(toRemove);
}

void sLinkedList_PushBack(SLinkedList list, ListDataType value)
{
    sLinkedList_InsertAtIndex(list, value, sLinkedList_GetListSize(list));
}

void sLinkedList_PushFront(SLinkedList list, ListDataType value)
{
    sLinkedList_InsertAtIndex(list, value, 0);
}

SLinkedList sLinkedList_InitList()
{
    SLinkedNode *list = malloc(sizeof(SLinkedNode));
    list->next = NULL;
    return list;
}

int sLinkedList_Compare(SLinkedList list, int index1, int index2)
{
    if (index2 >= sLinkedList_GetListSize(list))
        return 0;
    if (index1 != index2 && sLinkedList_GetEntry(list, index1)->value == sLinkedList_GetEntry(list, index2)->value)
        return 1;
    else
        return sLinkedList_Compare(list, index1, index2 + 1);
}

int sLinkedList_ContainsRepetitions(SLinkedList list)
{
    int i;
    for (i = 0; i < sLinkedList_GetListSize(list); i ++)
        if (sLinkedList_Compare(list, i, 0))
            return 1;
    return 0;
}