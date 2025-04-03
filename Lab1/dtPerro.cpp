#include "dtPerro.h"
#include "dtMascota.h"
#include <iostream>

using namespace std;


// PERRO

dtPerro::dtPerro(string _nombre, Genero _genero, float _peso,RazaPerro _raza, bool _vacuna):dtMascota(_nombre, _genero, _peso){
    this->raza = _raza;
	this->vacuna = _vacuna;
	this->_tipoMascota = PERRO;
}

dtPerro::dtPerro(string _nombre, Genero _genero, float _peso, TipoMascota _tipo):dtMascota(_nombre, _genero,_peso){
	this->_tipoMascota =_tipo;
	//this->_tipoMascota = PERRO;
};

bool dtPerro::getVacuna(){
	return this->vacuna;
}

RazaPerro dtPerro::getRaza(){
	return this->raza;
}

dtPerro::~dtPerro(){}
