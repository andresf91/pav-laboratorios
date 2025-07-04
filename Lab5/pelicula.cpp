#include "pelicula.h"

Pelicula::Pelicula(string _titulo, string _sinopsis) {
    this->titulo = _titulo;
    this->sinopsis = _sinopsis;
    this->posterUrl = "Sin poster.";
    this->puntajePromedio = 0.0;
}

Pelicula::Pelicula(string _titulo, string _sinopsis, string _posterUrl) {
    this->titulo = _titulo;
    this->sinopsis = _sinopsis;
    this->posterUrl = _posterUrl;
    this->puntajePromedio = 0.0;
}

DTpelicula Pelicula::getDTpelicula() {
    DTpelicula dtPeli(getUrl(), getSinopsis());
    return dtPeli;   
}

string Pelicula::getTitulo() {
    return this->titulo;
}

string Pelicula::getUrl() {
    return this->posterUrl;
}

string Pelicula::getSinopsis() {
    return this->sinopsis;
}

float Pelicula::getPuntajePromedio() {
    return this->puntajePromedio;
}

void Pelicula::setPosterUrl(string _posterUrl) {
    this->posterUrl = _posterUrl;
}

void Pelicula::setSinopsis(string _sinopsis) {
    this->sinopsis = _sinopsis;
}

void Pelicula::setPuntajePromedio(float _puntajePromedio) {
    this->puntajePromedio = _puntajePromedio;
}

void Pelicula::agregarPuntaje(Puntaje* puntaje){
    puntajes.push_back(puntaje);
}

void Pelicula::agregarComentario(Comentario* comentario){
    comentarios.push_back(comentario);
}

Pelicula::~Pelicula(){
    for (Puntaje* p : puntajes) {
        delete p;
        p = nullptr;
    }
    puntajes.clear();

    for (Comentario* c : comentarios) {
        delete c;
        c = nullptr;
    }
    comentarios.clear(); 
}