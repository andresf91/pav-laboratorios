#include "dtSalaConFunciones.h"

DTsalaConFunciones::DTsalaConFunciones(int nroSala, int capacidad, vector<DTfuncion> horariosO) {
    this->nroSala = nroSala;
    this->capacidad = capacidad;
    this->horariosO = horariosO;
}

int DTsalaConFunciones::getNroSala() {
    return nroSala;
}

int DTsalaConFunciones::getCapacidad() {
    return capacidad;
}

vector<DTfuncion> DTsalaConFunciones::getHorariosO() {
    return horariosO;
}
