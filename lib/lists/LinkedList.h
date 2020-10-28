#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ListT;

typedef struct __Node {
    ListT *dataPointer;
    struct __Node *next;
    struct __Node *prev;
    int index;
} Node;

typedef struct {
    Node *lastNode;
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
void linkedList_Add(LinkedList*, ListT);

/**
 * Aggiunge un elemento a una lista dinamica alla posizione indicata dall'indice
 * @param Lista la lista a cui aggiungere l'elemento
 * @param Indice l'indice dove dell'elemento
 * @param Dato il dato da inserire
*/
void linkedList_Insert(LinkedList*, int, ListT);

/**
 * Rimuove un elemento da una lista dinamica
 * @param Lista la lista da cui rimuovere l'elemento
 * @param Indice l'indice dell'elemento nella lista
*/
void linkedList_Remove(LinkedList*, int);

/**
 * Trova un elemento in una lista dinamica
 * @param Lista la lista in cui cercare l'elemento
 * @param Indice l'indice dell'elemento nella lista
 * 
 * @return il puntatore all'elemento
*/
Node* linkedList_Find(LinkedList*, int);

/**
 * Cerca il puntatore al dato in un elemento contenuto in una lista dinamica
 * @param Lista la lista in cui cercare l'elemento
 * @param Indice l'indice dell'elemento nella lista
 * 
 * @return il puntatore al dato contenuto nell'elemento
*/
ListT* linkedList_Get(LinkedList*, int);

/**
 * Ottiene il dato contenuto in un elemento di una lista dinamica
 * @param Lista la lista in cui cercare l'elemento
 * @param Indice l'indice dell'elemento nella lista
 * 
 * @return il dato al dato contenuto nell'elemento
*/
ListT linkedList_GetValue(LinkedList*, int);

/**
 * Ottiene il dato contenuto in un elemento di una lista dinamica
 * @param Lista la lista in cui inserire l'elemento
 * @param Indice l'indice in cui inserire l'elemento nella lista
 * @param Dato il dato da inserire
*/
void linkedList_SetValue(LinkedList*, int, ListT);

/**
 * Stampa i valori degli elementi di una lista dinamica
 * @param Lista la lista da stampare
*/
void linkedList_Print(LinkedList*);

#endif