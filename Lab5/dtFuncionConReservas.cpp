#include "dtFuncionConReservas.h"

DTfuncionConReservas::DTfuncionConReservas(DTfuncion funcion, vector<DTreserva> reservas) : funcion(funcion) {
    this->reservas = reservas;
}

DTfuncion DTfuncionConReservas::getFuncion() {
    return funcion;
}

vector<DTreserva> DTfuncionConReservas::getReservas() {
    return reservas;
}
