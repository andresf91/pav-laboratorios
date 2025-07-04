#ifndef FUNCION_H
#define FUNCION_H

#include "dtFecha.h"
#include "dtTiempo.h"
#include "dtFuncion.h"
#include "dtFuncion2.h"
#include "pelicula.h"
#include <string>
using namespace std;

class Pelicula;
class Sala;

class Funcion{
private:
    Pelicula* pelicula;
    Sala* sala;
    int nroFuncion;
    float costoPorAsiento = 200;
    DTfecha fecha;
    DTtiempo horario;
public:
    Funcion(int, DTfecha, DTtiempo, Pelicula*, Sala*);
    bool esFuncionDePelicula(string);
    DTfuncion2 getDTf2();
    Pelicula* getPelicula();
    int getNroFuncion();
    float getCostoPorAsiento();
    DTfecha getFecha();
    DTtiempo getHorario();
    DTfuncion getdtFuncion();
    void setNroFuncion(int);
    void setcostoPorAsiento(float);
    void setFecha(DTfecha);
    void setHorario(DTtiempo);
    ~Funcion();
};

#endif