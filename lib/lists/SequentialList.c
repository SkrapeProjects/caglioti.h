#include "SequentialList.h"

void seqList_Initialize(SequentialList* Lista) {
    Lista->length = 0;
}

bool seqList_Add(SequentialList* Lista, int NuovoElemento) {
    if (Lista->length == MAX_LENGTH) {
        return false;
    }

    Lista->Sequenza[Lista->length++] = NuovoElemento;
    return true;
}

bool seqList_InsertAtIndex(SequentialList* Lista, int NuovoElemento, int IndiceNuovoElemento) {
    if (Lista->length == MAX_LENGTH || IndiceNuovoElemento > Lista->length) {
        return false;
    }

    if (ShiftSequenza(Lista, IndiceNuovoElemento, 1)) {
        Lista->Sequenza[IndiceNuovoElemento] = NuovoElemento;

        return true;
    }

    return false;
}

bool seqList_ShiftSequence(SequentialList* Lista, int Indice, int NumeroPosizioni) {
    int i;

    if (Lista->length + NumeroPosizioni >= MAX_LENGTH || Indice < 0 || Indice >= Lista->length) {
        return false;
    }

    for (i = Lista->length - 1; i >= Indice; i--) {
        Lista->Sequenza[i + NumeroPosizioni] = Lista->Sequenza[i];
    }

    return true;
}

int seqList_Get(SequentialList* Lista, int i) {
    if (i >= Lista->length) {
        return 0;
    }

    return Lista->Sequenza[i]; 
}