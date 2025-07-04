#include "financiera.h"

Financiera::Financiera(string nombre, float descuento) {
    this->nombre = nombre;
    this->descuento = descuento;
}

string Financiera::getNombre() {
    return this->nombre;
}

float Financiera::getDescuento() {
    return this->descuento;
}

DTfinanciera Financiera::getDTF() {
    bool tiene =false;
    if (getDescuento() != 0){
        tiene = true;
    }
    DTfinanciera dt(tiene, getDescuento());
    return dt;
}