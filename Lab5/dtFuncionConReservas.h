#ifndef DTFUNCIONCONRESERVAS_H
#define DTFUNCIONCONRESERVAS_H

#include <vector>
using namespace std;
#include "dtFuncion.h"
#include "dtReserva.h"

class DTfuncionConReservas{
private:
    DTfuncion funcion;
    vector<DTreserva> reservas;
public:
    DTfuncionConReservas(DTfuncion, vector<DTreserva>);
    DTfuncion getFuncion();
    vector<DTreserva> getReservas();
};

#endif