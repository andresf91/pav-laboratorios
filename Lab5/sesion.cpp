#include "sesion.h"

Sesion* Sesion::instancia = nullptr;

Sesion::Sesion() {}

Sesion* Sesion::getInstancia() {
    if (instancia == nullptr){
        instancia = new Sesion();
    }
    return instancia;
}

string Sesion::getNickname() {
    return this->nickname;
}

void Sesion::setNickname(string nickname) {
    this->nickname = nickname;
}

void Sesion::destroyInstancia() {
    if (instancia != nullptr) {
        delete instancia;
        instancia = nullptr;
    }
}

Sesion::~Sesion() {}