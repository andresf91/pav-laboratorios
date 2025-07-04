#include "dtFecha.h"

DTfecha::DTfecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

int DTfecha::getDia() {
    return this->dia;
}

int DTfecha::getMes() {
    return this->mes;
}

int DTfecha::getAnio() {
    return this->anio;
}