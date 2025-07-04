#ifndef IPUNTAJESYCOMENTARIOS_H
#define IPUNTAJESYCOMENTARIOS_H

#include "dtPelicula2.h"
#include "dtPuntajesYComentarios.h"
#include "dtComentario.h"
#include <set>
#include <string>
using namespace std;

class IpuntajesYComentarios{
public:
    virtual void listarPeliculas2() = 0;
    virtual void seleccionarPelicula(string titulo) = 0;
    virtual void infoPuntajesYComentarios() = 0;
    virtual void listarPeliculas() = 0;
    virtual void listarComentarios() = 0;
    virtual void comentarioNuevo(string texto) = 0;
    virtual void elegirComentario(int nroComentario) = 0;
    virtual void responderComentario(string texto) = 0;
    virtual bool continuarRespondiendo() = 0;
    virtual bool elegirPeliAPuntuar(string titulo) = 0;
    virtual int obtenerPuntaje() = 0;
    virtual void actualizarPuntaje(int puntaje) = 0;
    virtual void puntuarPelicula(int puntaje) = 0;
};

#endif