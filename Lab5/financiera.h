#ifndef FINANCIERA_H
#define FINANCIERA_H

#include "dtFinanciera.h"
#include <string>
using namespace std;

class Financiera{
private:
    string nombre;
    float descuento;
public:
    Financiera(string, float);
    string getNombre();
    float getDescuento();
    DTfinanciera getDTF();
};

#endif