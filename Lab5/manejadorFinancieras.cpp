#include "manejadorFinancieras.h"
#include <iostream>

ManejadorFinancieras* ManejadorFinancieras::instancia = nullptr;

ManejadorFinancieras::ManejadorFinancieras() {}

ManejadorFinancieras* ManejadorFinancieras::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ManejadorFinancieras();
    }
    return instancia;
}

void ManejadorFinancieras::agregarFinanciera(Financiera* financiera) {
    if (financiera != nullptr && !existeFinanciera(financiera->getNombre())) {
        financieras[financiera->getNombre()] = financiera;
    }
}

Financiera* ManejadorFinancieras::obtenerFinanciera(string nombre) {
    auto it = financieras.find(nombre);
    if (it != financieras.end()) {
        return it->second;
    }
    return nullptr;
}

bool ManejadorFinancieras::existeFinanciera(string nombre) {
    return financieras.find(nombre) != financieras.end();
}

void ManejadorFinancieras::eliminarFinanciera(string nombre) {
    auto it = financieras.find(nombre);
    if (it != financieras.end()) {
        delete it->second; // Liberar memoria del usuario
        financieras.erase(it);
    }
}

ManejadorFinancieras::~ManejadorFinancieras() {
    for (auto& par : financieras) {
        delete par.second;
    }
    financieras.clear();
}

void ManejadorFinancieras::destroyInstancia() {
    if (instancia != nullptr) {
        delete instancia;
        instancia = nullptr;
    }
}