#ifndef CINE_H
#define CINE_H

#include "pelicula.h"
#include "sala.h"
#include "dtCine.h"
#include <set>
#include <vector>
#include <string>
using namespace std;

class Cine{
private:
    int nroCine;
    string direccion;
    int nroSalasCreadas = 1;
    int cantFuncionesCreadas = 1;
    Sala* sala;
    vector<Sala*> salas;
public:
    Cine(int, string);
    vector<DTfuncion2> getDTf2(string titulo);
    int getNroCine();
    string getDireccion();
    Sala* getSala();
    int getNroSalasCreadas();
    int getCantFuncionesCreadas();
    vector<DTsalaConFunciones> getDTscfs();
    vector<Sala*> getSalas();
    void setCantFuncionesCreadas(int);
    void setNroSalasCreadas(int);
    void setDireccion(string);
    void agregarPelicula(Pelicula*);
    void crearUnaSala(int);
    void agregarSala(Sala*);
    DTcine getDTcine();
    ~Cine();
};

#endif