#ifndef DTFUNCION2_H
#define DTFUNCION2_H

#include "dtFecha.h"
#include "dtTiempo.h"

class DTfuncion2{
private:
    int nroFuncion;
    DTfecha fecha;
    DTtiempo horario;
    float costoPorAsiento;
public:
    DTfuncion2(int, DTfecha, DTtiempo, float);
    int getNroFuncion();
    DTfecha getFecha();
    DTtiempo getHorario();
    float getCostoPorAsiento();
};

#endif