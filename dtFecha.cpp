#include "dtFecha.h"
#include <iostream>

using namespace std;

Fecha::Fecha(int _dia, int _mes, int _anio){
    this->dia = _dia;
    this->mes = _mes;
    this->anio = _anio;
}

int Fecha::getDia(){
    return this->dia;
}

int Fecha::getMes(){
    return this->mes;
}

int Fecha::getAnio(){
    return this->anio;
}

void Fecha::imprimirFecha(){
    cout << getDia() << "/" << getMes() << "/" << getAnio() << endl;
}

Fecha::~Fecha(){}
