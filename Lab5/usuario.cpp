#include "usuario.h"

// Constructor 1: Inicializa nickname y contrasenia
Usuario::Usuario(string _nickname, string _contrasenia) {
    this->nickname = _nickname;
    this->contrasenia = _contrasenia;
    this->urlFoto = "Sin foto"; // Valor por defecto
}

// Constructor 2: Inicializa nickname, contrasenia y urlFoto
Usuario::Usuario(string _nickname, string _contrasenia, string _urlFoto) {
    this->nickname = _nickname;
    this->contrasenia = _contrasenia;
    this->urlFoto = _urlFoto;
}

string Usuario::getNickname() {
    return this->nickname;
}

string Usuario::getContrasenia() {
    return this->contrasenia;
}

string Usuario::getUrlFoto() {
    return this->urlFoto;
}

void Usuario::setNickname(string _nickname) {
    this->nickname = _nickname;
}

void Usuario::setContrasenia(string _contrasenia) {
    this->contrasenia = _contrasenia;
}

void Usuario::setUrlFoto(string _urlFoto) {
    this->urlFoto = _urlFoto;
}

void Usuario::agregarReserva(Reserva* _reserva) {
    reservas.push_back(_reserva);
}

void Usuario::agregarComentario(Comentario* _comentario) {
    comentarios.push_back(_comentario);
}

Usuario::~Usuario(){
    for (Comentario* c : comentarios) {
        delete c;
        c = nullptr;
    }
    comentarios.clear();
    for (Reserva* r : reservas) {
        delete r;
        r = nullptr;
    }
    reservas.clear();
}