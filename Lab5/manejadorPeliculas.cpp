#include "manejadorPeliculas.h"

ManejadorPeliculas* ManejadorPeliculas::instancia = nullptr;

ManejadorPeliculas::ManejadorPeliculas() {}

ManejadorPeliculas* ManejadorPeliculas::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ManejadorPeliculas();
    }
    return instancia;
}

void ManejadorPeliculas::agregarPelicula(Pelicula* peli) {
    if (peli != nullptr && !existePelicula(peli->getTitulo())) {
        peliculas[peli->getTitulo()] = peli;
    }
}

Pelicula* ManejadorPeliculas::obtenerPelicula(string titulo) {
    auto it = peliculas.find(titulo);
    if (it != peliculas.end()) {
        return it->second;
    }
    return nullptr;
}

bool ManejadorPeliculas::existePelicula(string titulo) {
    return peliculas.find(titulo) != peliculas.end();
}

void ManejadorPeliculas::eliminarPelicula(string titulo) {
    auto it = peliculas.find(titulo);
    if (it != peliculas.end()) {
        delete it->second; // Liberar memoria del cine
        peliculas.erase(it);
    }
}

map<string, Pelicula*> ManejadorPeliculas::getPeliculas() {
    return this->peliculas;
}

ManejadorPeliculas::~ManejadorPeliculas() {
    for (auto& par : peliculas) {
        delete par.second;
    }
    peliculas.clear();
}

void ManejadorPeliculas::destroyInstancia() {
    if (instancia != nullptr) {
        delete instancia;
        instancia = nullptr;
    }
}