#include "comentario.h"

// Constructor para un comentario principal (sin padre)
Comentario::Comentario(int _nroComentario, string _texto, Usuario* _usuario) {
    this->nroComentario = _nroComentario;
    this->texto = _texto;
    this->usuario = _usuario;
    this->nroPadre = -1; // Se inicializa en -1 para indicar que no tiene padre
}

// Constructor para una respuesta a otro comentario (con padre)
Comentario::Comentario(int _nroComentario, string _texto, Usuario* _usuario, int _nroPadre) {
    this->nroComentario = _nroComentario;
    this->texto = _texto;
    this->usuario = _usuario;
    this->nroPadre = _nroPadre;
}

Usuario* Comentario::getUsuario() {
    return this->usuario;
}

DTcomentario Comentario::getDTcomentario() {
    return DTcomentario(this->nroComentario, this->texto);
}

int Comentario::getNroComentario() {
    return this->nroComentario;
}

string Comentario::getTexto() {
    return this->texto;
}

int Comentario::getNroPadre() {
    return this->nroPadre;
}

vector<Comentario*> Comentario::getRespuestas() {
    return this->respuestas;
}

void Comentario::agregarRespuesta(Comentario* _respuesta) {
    respuestas.push_back(_respuesta);
}

Comentario::~Comentario(){
    for (Comentario* c : respuestas) {
        delete c;
        c = nullptr;
    }
    respuestas.clear();
}