#ifndef DTCINE_H
#define DTCINE_H

#include <string>
using namespace std;

class DTcine{
private:
    int nroCine;
    string direccion;
public:
    DTcine(int, string);
    int getNroCine();
    string getDireccion();
};

#endif