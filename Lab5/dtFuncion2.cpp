#include "dtFuncion2.h"


DTfuncion2::DTfuncion2(int nroFuncion, DTfecha fecha, DTtiempo horario, float cxa) : fecha(fecha), horario(horario){
    this->nroFuncion = nroFuncion;
    this->costoPorAsiento = cxa;
}

int DTfuncion2::getNroFuncion() {
    return this->nroFuncion;
}

DTfecha DTfuncion2::getFecha() {
    return this->fecha;
}

DTtiempo DTfuncion2::getHorario() {
    return this->horario;
}

float DTfuncion2::getCostoPorAsiento() {
    return this->costoPorAsiento;
}