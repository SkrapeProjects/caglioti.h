#ifndef SEQUENTIALLIST_H
#define SEQUENTIALLIST_H

#include "../Utils.h"

#define MAX_LENGTH 100

typedef int SeqListT;

typedef struct {
	SeqListT Sequenza[MAX_LENGTH];
	int length;
} SequentialList;

void seqList_Initialize(SequentialList*);
bool seqList_Add(SequentialList*, SeqListT);

/**
 * Funzione per l'inserimento di un elemento ad un certo indice
 * @param Lista la lista sequenziale in cui inserire l'elemento
 * @param NuovoElemento il nuovo elemento da inserire (TODO: suggerirei una generalizzazione)
 * @param IndiceNuovoElemento l'indice in cui verrà inserito il nuovo elemento
 * 
 * @return true se l'inserimento è andato a buon fine, false altrimenti
*/
bool seqList_InsertAtIndex(SequentialList*, SeqListT, int);

/**
 * Funzione per lo spostamento degli elementi in una sequenza a destra
 * TODO: anche a sinistra con numero negativo si potrebbe fare
 * @param Lista la lista sequenziale dove effettuare lo spostamento
 * @param Indice l'indice da cui far partire lo spostamento
 * @param NumeroPosizioni il numero di celle di cui "shiftare"
 * 
 * @return true se lo spostamento è andato a buon fine, false altrimenti
*/
bool seqList_ShiftSequence(SequentialList*, int, int);

SeqListT seqList_Get(SequentialList*, int);

#endif