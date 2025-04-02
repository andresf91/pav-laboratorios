#include "dtMascota.h"
#include <iostream>


dtMascota::dtMascota(string _nombre, Genero _genero, float _peso){
    this->nombre = _nombre;
    this->genero = _genero;
    this->peso = _peso;
    this->racion = 0;
    this->tipo = OTRO;
}

dtMascota::dtMascota(dtMascota* _mascota){
	this->nombre = _mascota->nombre;
	this->genero = _mascota->genero;
	this->peso = _mascota->peso;
	this->racion = _mascota->racion;
	this->tipo = OTRO;
}

TipoMascota dtMascota::getTipoMascota(){
	return this->tipo;
}

string dtMascota::getNombre(){
	return this->nombre;
}

Genero dtMascota::getGenero(){
	return this->genero;
}

float dtMascota::getPeso(){
	return this->peso;
}
