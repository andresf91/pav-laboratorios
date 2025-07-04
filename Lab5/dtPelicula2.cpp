#include "dtPelicula2.h"

DTpelicula2::DTpelicula2(string titulo, string urlPoster) {
    this->titulo = titulo;
    this->urlPoster = urlPoster;
}

string DTpelicula2::getUrlPoster() {
    return this->urlPoster;
}

string DTpelicula2::getTitulo() {
    return this->titulo;
}