#include "dtFecha.h"
#include <iostream>

using namespace std;

dtFecha::dtFecha(int _dia, int _mes, int _anio){
    this->dia = _dia;
    this->mes = _mes;
    this->anio = _anio;
}

dtFecha::dtFecha(dtFecha* _fecha){
	this->dia = _fecha->dia;
	this->mes = _fecha->mes;
	this->anio = _fecha->anio;
}

int dtFecha::getDia(){
    return this->dia;
}

int dtFecha::getMes(){
    return this->mes;
}

int dtFecha::getAnio(){
    return this->anio;
}

void dtFecha::imprimirFecha(){
    cout << getDia() << "/" << getMes() << "/" << getAnio() << endl;
}

dtFecha::~dtFecha(){}
