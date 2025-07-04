#include "manejadorCines.h"

ManejadorCines* ManejadorCines::instancia = nullptr;

ManejadorCines::ManejadorCines() {
    this->cantCinesCreados = 1;
}

ManejadorCines* ManejadorCines::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ManejadorCines();
    }
    return instancia;
}

map<string, Cine*> ManejadorCines::getCines() {
    return this->cines;
}

void ManejadorCines::agregarCine(Cine* cine) {
    if (cine != nullptr && !existeCine(cine->getDireccion())) {
        cines[cine->getDireccion()] = cine;
    }
}

Cine* ManejadorCines::obtenerCine(string direccion) {
    auto it = cines.find(direccion);
    if (it != cines.end()) {
        return it->second;
    }
    return nullptr;
}

bool ManejadorCines::existeCine(string direccion) {
    return cines.find(direccion) != cines.end();
}

void ManejadorCines::eliminarCine(string direccion) {
    auto it = cines.find(direccion);
    if (it != cines.end()) {
        delete it->second; // Liberar memoria del cine
        cines.erase(it);
    }
}

int ManejadorCines::getCantCinesCreados() {
    return this->cantCinesCreados;
}

void ManejadorCines::setCantCinesCreados(int cant) {
    this->cantCinesCreados = cant;
}

ManejadorCines::~ManejadorCines() {
    for (auto& par : cines) {
        delete par.second;
    }
    cines.clear();
}

void ManejadorCines::destroyInstancia() {
    if (instancia != nullptr) {
        delete instancia;
        instancia = nullptr;
    }
}