#include "dtPelicula.h"

DTpelicula::DTpelicula(string urlPoster, string sinopsis) {
    this->urlPoster = urlPoster;
    this->sinopsis = sinopsis;
}

string DTpelicula::getUrlPoster() {
    return this->urlPoster;
}

string DTpelicula::getSinopsis() {
    return this->sinopsis;
}