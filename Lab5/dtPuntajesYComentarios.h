#ifndef DTPUNTAJESYCOMENTARIOS_H
#define DTPUNTAJESYCOMENTARIOS_H

#include "dtUsuComent.h"
#include "dtUsuPunt.h"
#include <set>
#include <string>
using namespace std;

class DTpuntajesYComentarios{
private:
    string titulo;
    float puntajePromedio;
    int cantPuntuaciones;
    set<DTusuComent> comentarios;
    set<DTusuPunt> puntajes;
public:
    DTpuntajesYComentarios(string, float, int, set<DTusuComent>, set<DTusuPunt>);
    string getTitulo();
    float getPuntajePromedio();
    int getCantPuntuaciones();
    set<DTusuComent> getComentarios();
    set<DTusuPunt> getPuntajes();
};

#endif