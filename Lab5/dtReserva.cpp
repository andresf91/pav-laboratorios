#include "dtReserva.h"

DTreserva::DTreserva(int cantAsientos, float costoTotal, TipoPago tipo) {
    this->cantAsientos = cantAsientos;
    this->costoTotal = costoTotal;
    this->tipo = tipo;
}

int DTreserva::getCantAsientos() {
    return cantAsientos;
}

float DTreserva::getCostoTotal() {
    return costoTotal;
}

TipoPago DTreserva::getTipoPago() {
    return tipo;
}
