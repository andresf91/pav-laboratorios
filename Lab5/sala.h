#ifndef SALA_H
#define SALA_H

#include "funcion.h"
#include "dtSalaConFunciones.h"
#include "dtFuncion2.h"
#include <vector>
using namespace std;

class Cine;

class Sala{
private:
    Cine* cine;
    int nroSala;
    int capacidad;
    vector<Funcion*> funciones;
public:
    Sala(int, int, Cine*);
    vector<DTfuncion2> getDTf2(string titulo);
    int getNroSala();
    int getCapacidad();
    void agregarFuncion(Funcion*);
    DTsalaConFunciones getDTScf();
    vector<Funcion*> getFunciones();
    ~Sala();
};

#endif