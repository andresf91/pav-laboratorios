#ifndef RESERVA_H
#define RESERVA_H
#include "dtReserva.h"

class Usuario;
class Funcion;

class Reserva{
private:
    Usuario* usuario;
    Funcion* funcion;
    int cantAsientos;
    float costoTotal;
public:
    Reserva(int, float, Usuario*, Funcion*);
    int getCantAsientos();
    float getCostoTotal();
    Usuario* getUsuario();
    Funcion* getFuncion();
    void setCantAsientos(int);
    void setCostoTotal(float);
    ~Reserva();
};

#endif