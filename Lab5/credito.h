#ifndef CREDITO_H
#define CREDITO_H
#include <string>
#include "reserva.h"

using namespace std;

class Credito: public Reserva{
private:
    float descuento;
    string financiera;
public:
    Credito(int, float, Usuario* usr, Funcion* func, float, string);
    float getDescuento();
    string getFinanciera();
    DTreserva getDTR();
    void setDescuento(float);
    void setFinanciera(string);
    ~Credito();
};

#endif