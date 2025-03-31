#include "dtGato.h"

dtGato::dtGato(string _nombre, Genero _genero, TipoPelo _tipoPelo):dtMascota(_nombre, _genero){
	this->tipoPelo = _tipoPelo;
}

float dtGato::getRacionDiaria(){
	float _racion = getPeso() * 0.015;
	setRacion(_racion);
	return _racion;
}

TipoMascota dtGato::getTipo(){
    return _tipo; 
}



TipoPelo Gato::getTipoPelo(){
	return this->tipoPelo;
}

dtGato::~dtGato(){}