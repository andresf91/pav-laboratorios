#ifndef DTSALACONFUNCIONES_H
#define DTSALACONFUNCIONES_H

#include <vector>
#include "dtFuncion.h"
using namespace std;

class DTsalaConFunciones{
private:
    int nroSala;
    int capacidad;
    vector<DTfuncion> horariosO;
public:
    DTsalaConFunciones(int, int, vector<DTfuncion>);
    int getNroSala();
    int getCapacidad();
    vector<DTfuncion> getHorariosO();
};

#endif