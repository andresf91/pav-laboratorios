#ifndef DTRESERVA_H
#define DTRESERVA_H

#include "tipoPago.h"

class DTreserva{
private:
    int cantAsientos;
    float costoTotal;
    TipoPago tipo;
public:
    DTreserva(int, float, TipoPago);
    int getCantAsientos();
    float getCostoTotal();
    TipoPago getTipoPago();
};

#endif