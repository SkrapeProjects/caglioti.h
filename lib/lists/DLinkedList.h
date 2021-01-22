#ifndef D_LINKED_LIST_H
#define D_LINKED_LIST_H

typedef struct __DLinkedNode {
    void *dataPointer;
    struct __DLinkedNode *next;
    struct __DLinkedNode *prev;
    int index;
} DLinkedNode;

typedef struct {
    DLinkedNode *lastNode;
    int dataSize;
    int size;
} DLinkedList;

/**
 * Inizializza una nuova lista dinamica 
 * @return il puntatore alla lista
*/
DLinkedList* dLinkedList_New(int);

/**
 * Aggiunge un elemento a una lista dinamica
 * @param Lista la lista a cui aggiungere l'elemento
 * @param Dato il dato da inserire
*/
void dLinkedList_Add(DLinkedList*, void*);

/**
 * Aggiunge un elemento a una lista dinamica alla posizione indicata dall'indice
 * @param Lista la lista a cui aggiungere l'elemento
 * @param Indice l'indice dove dell'elemento
 * @param Dato il dato da inserire
*/
void dLinkedList_Insert(DLinkedList*, int, void*);

/**
 * Rimuove un elemento da una lista dinamica
 * @param Lista la lista da cui rimuovere l'elemento
 * @param Indice l'indice dell'elemento nella lista
*/
void dLinkedList_Remove(DLinkedList*, int);

/**
 * Trova un elemento in una lista dinamica
 * @param Lista la lista in cui cercare l'elemento
 * @param Indice l'indice dell'elemento nella lista
 * 
 * @return il puntatore all'elemento
*/
DLinkedNode* dLinkedList_Find(DLinkedList*, int);

/**
 * Cerca il puntatore al dato in un elemento contenuto in una lista dinamica
 * @param Lista la lista in cui cercare l'elemento
 * @param Indice l'indice dell'elemento nella lista
 * 
 * @return il puntatore al dato contenuto nell'elemento
*/
void* dLinkedList_Get(DLinkedList*, int);

/**
 * Ottiene il dato contenuto in un elemento di una lista dinamica
 * @param Lista la lista in cui inserire l'elemento
 * @param Indice l'indice in cui inserire l'elemento nella lista
 * @param Dato il dato da inserire
*/
void dLinkedList_Set(DLinkedList*, int, void *);

#endif