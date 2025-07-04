#ifndef PUNTAJE_H
#define PUNTAJE_H

#include "usuario.h"

class Puntaje{
private:
    int valor;
    Usuario* usuario;
public:
    Puntaje(int, Usuario*);
    int getPuntaje();
    void setPuntaje(int);
    ~Puntaje();
};

#endif