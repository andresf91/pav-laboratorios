#include "dtFuncion.h"

DTfuncion::DTfuncion(int nroFuncion, DTfecha fecha, DTtiempo horario) : fecha(fecha), horario(horario) {
    this->nroFuncion = nroFuncion;
}

int DTfuncion::getNroFuncion() {
    return nroFuncion;
}

DTfecha DTfuncion::getFecha() {
    return fecha;
}

DTtiempo DTfuncion::getHorario() {
    return horario;
}
