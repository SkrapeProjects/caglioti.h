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

/**
 * Inizializza una nuova lista dinamica 
 * @return il puntatore alla lista
*/
LinkedList* linkedList_New();

/**
 * Aggiunge un elemento a una lista dinamica
 * @param Lista la lista a cui aggiungere l'elemento
 * @param Dato il dato da inserire
*/
void linkedList_Add(LinkedList *list, ListT data);

/**
 * Rimuove un elemento da una lista dinamica
 * @param Lista la lista da cui rimuovere l'elemento
 * @param Indice l'indice dell'elemento nella lista
*/
void linkedList_Remove(LinkedList *list, int index);

/**
 * Trova un elemento in una lista dinamica
 * @param Lista la lista in cui cercare l'elemento
 * @param Indice l'indice dell'elemento nella lista
 * 
 * @return il puntatore all'elemento
*/
Node* linkedList_Find(LinkedList *list, int index);

/**
 * Cerca il puntatore al dato in un elemento contenuto in una lista dinamica
 * @param Lista la lista in cui cercare l'elemento
 * @param Indice l'indice dell'elemento nella lista
 * 
 * @return il puntatore al dato contenuto nell'elemento
*/
ListT* linkedList_Get(LinkedList *list, int index);

/**
 * Ottiene il dato contenuto in un elemento di una lista dinamica
 * @param Lista la lista in cui cercare l'elemento
 * @param Indice l'indice dell'elemento nella lista
 * 
 * @return il dato al dato contenuto nell'elemento
*/
ListT linkedList_GetValue(LinkedList *list, int index);

/**
 * Ottiene il dato contenuto in un elemento di una lista dinamica
 * @param Lista la lista in cui inserire l'elemento
 * @param Indice l'indice in cui inserire l'elemento nella lista
 * @param Dato il dato da inserire
*/
void linkedList_SetValue(LinkedList *list, int index, ListT value);

/**
 * Stampa i valori degli elementi di una lista dinamica
 * @param Lista la lista da stampare
*/
void linkedList_Print(LinkedList *list);

#endif