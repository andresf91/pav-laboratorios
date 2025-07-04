#include "dtPuntajesYComentarios.h"

DTpuntajesYComentarios::DTpuntajesYComentarios(string titulo, float puntajePromedio, int cantPuntuaciones, set<DTusuComent> comentarios, set<DTusuPunt> puntajes) {
    this->titulo = titulo;
    this->puntajePromedio = puntajePromedio;
    this->cantPuntuaciones = cantPuntuaciones;
    this->comentarios = comentarios;
    this->puntajes = puntajes;
}

string DTpuntajesYComentarios::getTitulo() {
    return titulo;
}

float DTpuntajesYComentarios::getPuntajePromedio() {
    return puntajePromedio;
}

int DTpuntajesYComentarios::getCantPuntuaciones() {
    return cantPuntuaciones;
}

set<DTusuComent> DTpuntajesYComentarios::getComentarios() {
    return comentarios;
}

set<DTusuPunt> DTpuntajesYComentarios::getPuntajes() {
    return puntajes;
}
