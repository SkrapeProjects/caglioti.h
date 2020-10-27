#include "SequentialList.h"

void seqList_Initialize(ListaSequenziale* Lista) {
    Lista->Lunghezza = 0;
}

bool seqList_Add(ListaSequenziale* Lista, int NuovoElemento) {
    if (Lista->Lunghezza == MAX_LUNGHEZZA) {
        return false;
    }

    Lista->Sequenza[Lista->Lunghezza++] = NuovoElemento;
    return true;
}

bool seqList_InsertAtIndex(ListaSequenziale* Lista, int NuovoElemento, int IndiceNuovoElemento) {
    if (Lista->Lunghezza == MAX_LUNGHEZZA || IndiceNuovoElemento > Lista->Lunghezza) {
        return false;
    }

    if (ShiftSequenza(Lista, IndiceNuovoElemento, 1)) {
        Lista->Sequenza[IndiceNuovoElemento] = NuovoElemento;

        return true;
    }

    return false;
}

bool seqList_ShiftSequence(ListaSequenziale* Lista, int Indice, int NumeroPosizioni) {
    int i;

    if (Lista->Lunghezza + NumeroPosizioni >= MAX_LUNGHEZZA || Indice < 0 || Indice >= Lista->Lunghezza) {
        return false;
    }

    for (i = Lista->Lunghezza - 1; i >= Indice; i--) {
        Lista->Sequenza[i + NumeroPosizioni] = Lista->Sequenza[i];
    }

    return true;
}

int seqList_Get(ListaSequenziale* Lista, int i) {
    if (i >= Lista->Lunghezza) {
        return 0;
    }

    return Lista->Sequenza[i]; 
}