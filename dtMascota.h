#ifndef DTMASCOTA_H
#define DTMASCOTA_H

#include <string>
#include "defMascotas.h"


using namespace std;

class dtMascota{
    private:
    string nombre;
    Genero genero;
    float peso;
    float racion;
    TipoMascota tipo;
    public:
    dtMascota(string, Genero, float);
    dtMascota(dtMascota*);
    virtual TipoMascota getTipoMascota();
    string getNombre();
    Genero getGenero();
    float getPeso();
};

#endif