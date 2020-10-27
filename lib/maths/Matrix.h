#ifndef MATRICI_H
#define MATRICI_H

#include "../Utils.h"

#define MAX_MATRIX_DIM 128

typedef struct 
{
    float data[MAX_MATRIX_DIM][MAX_MATRIX_DIM];
    int rows;
    int cols;
} Matrix;

/**
 * Inizializza una matrice
 * @param NumeroColonne le colonne della matrice
 * @param NumeroRighe le righe della matrice
 * 
 * @return la matrice inizializzata
 */
Matrix matrix_CreateMatrix(int, int);

/**
 * Crea una copia di una matrice
 * @param Matrice matrice da copiare
 * 
 * @return la matrice copiata
 */
Matrix matrix_CopyMatrix(Matrix *);

/**
 * Imposta il valore in una cella della matrice
 * @param Matrice la matrice su cui effettuare l'azione
 * @param IndiceColonna l'indice della colonna della cella da modificare
 * @param IndiceRigha l'indice della riga della cella da modificare
 * @param Valore valore da inserire nella cella
 * 
 * @return true se l'operazione è stata effettuata con successo, false altrimenti
 */
bool matrix_SetValue(Matrix *, int, int, float);

/**
 * Scambia le righe di una matrice
 * @param Matrice la matrice su cui effettuare l'azione
 * @param IndicePrimaRiga l'indice della prima riga da scambiare
 * @param IndiceSecondaRiga l'indice della seconda riga da scambiare
 * 
 * @return true se l'operazione è stata effettuata con successo, false altrimenti
 */ 
bool matrix_SwapRows(Matrix *, int, int);

/**
 * Moltiplica una riga per un'altra
 * @param Matrice la matrice su cui effettuare l'azione
 * @param IndiceMoltiplicando indice della riga da moltiplicare
 * @param IndiceMoltiplicatore indice della riga che moltiplica
 * 
 * @return true se l'operazione è stata effettuata con successo, false altrimenti
 */
bool matrix_MultRowByRow(Matrix *, int, int);

/**
 * Somma una riga ad un'altra
 * @param Matrice la matrice su cui effettuare l'azione
 * @param IndiceAddendoPrimario indice della riga su cui viene effettuata l'addizione
 * @param IndiceAddendoSecondario indice della riga da sommare
 * 
 * @return true se l'operazione è stata effettuata con successo, false altrimenti
 */
bool matrix_AddRowToRow(Matrix *, int, int);

/**
 * Sottrai una riga ad un'altra
 * @param Matrice la matrice su cui effettuare l'azione
 * @param IndiceMinuendo indice della riga su cui viene effettuata la sottrazione
 * @param IndiceSottraendo indice della riga da sottrarre
 * 
 * @return true se l'operazione è stata effettuata con successo, false altrimenti
 */
bool matrix_SubRowFromRow(Matrix *, int, int);

/**
 * Somma due matrici
 * @param MatricePrimaria la matrice su cui viene effettuata l'operazione
 * @param MatriceSecondaria la matrice che viene sommata alla matrice primaria
 * 
 * @return true se l'operazione è stata effettuata con successo, false altrimenti
 */
bool matrix_Add(Matrix *, Matrix *);

/**
 * Somma due matrici
 * @param MatricePrimaria la matrice su cui viene effettuata l'operazione
 * @param MatriceSecondaria la matrice che viene sottratta alla matrice primaria
 * 
 * @return true se l'operazione è stata effettuata con successo, false altrimenti
 */
bool matrix_Sub(Matrix *a, Matrix *b);

/**
 * Prodotto tra matrici
 * @param MatriceMoltiplicando puntatore alla matrice da moltiplicare
 * @param MatriceMoltiplicatore puntatore alla matrice che funge da moltiplicatore
 * 
 * @return la matrice risultante se l'operazione è possibile (se le matrici sono conformabili), una matrice non valida (-1 colonne, -1 righe) se l'operazione è impossibile
 */
Matrix matrix_Mult(Matrix *, Matrix *);

/**
 * Moltiplica una matrice per uno scalare
 * @param MatriceMoltiplicando puntatore alla matrice da moltiplicare
 * @param ScalareMoltiplicatore valore dello scalare che moltiplica
 * 
 * @return void
 */
void matrix_MultByScalar(Matrix *, float);

#endif