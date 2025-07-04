#ifndef DTFUNCION_H
#define DTFUNCION_H

#include "dtFecha.h"
#include "dtTiempo.h"

class DTfuncion{
private:
    int nroFuncion;
    DTfecha fecha;
    DTtiempo horario;
public:
    DTfuncion(int, DTfecha, DTtiempo);
    int getNroFuncion();
    DTfecha getFecha();
    DTtiempo getHorario();
};

#endif