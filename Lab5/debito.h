#ifndef DEBITO_H
#define DEBITO_H
#include <string>
#include "reserva.h"

using namespace std;

class Debito: public Reserva {
private:
    string nombreBanco;
public:
    Debito(int, float, Usuario*, Funcion*, string);
    string getNombreBanco();
    DTreserva getDTR();
    void setNombreBanco(string);
    ~Debito();
};

#endif