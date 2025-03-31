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

    public:
    dtMascota(string, Genero);
    virtual void infoMascota(); // polimorfismo
    virtual float getRacionDiaria();
    string getNombre();
    Genero getGenero();
    float getPeso();
};

#endif