#include "dtComentario.h"

DTcomentario::DTcomentario(int nroComentario, string contenido) {
    this->nroComentario = nroComentario;
    this->contenido = contenido;
}

int DTcomentario::getNroComentario() {
    return nroComentario;
}

string DTcomentario::getContenido() {
    return contenido;
}
