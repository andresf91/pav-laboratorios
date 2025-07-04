#include "puntaje.h"

Puntaje::Puntaje(int _valor, Usuario* _usuario) {
    this->valor = _valor;
    this->usuario = _usuario;
}

int Puntaje::getPuntaje() {
    return this->valor;
}

void Puntaje::setPuntaje(int _valor) {
    this->valor = _valor;
}

Puntaje::~Puntaje(){}