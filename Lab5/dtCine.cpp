#include "dtCine.h"

DTcine::DTcine(int nroCine, string direccion) {
    this->nroCine = nroCine;
    this->direccion = direccion;
}

int DTcine::getNroCine() {
    return nroCine;
}

string DTcine::getDireccion() {
    return direccion;
}
