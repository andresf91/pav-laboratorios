#include "gato.h"
#include "dtMascota.h"
#include <iostream>

Gato::Gato(string _nombre, Genero _genero, float _peso, Socio* _duenio, TipoPelo _tipoPelo):Mascota(_nombre, _genero, _peso){
	this->duenio = _duenio;
	this->tipoPelo = _tipoPelo;
}

Gato::Gato(string _nombre, Genero _genero, float _peso, TipoPelo _tipoPelo):Mascota(_nombre, _genero, _peso){
	this->tipoPelo = _tipoPelo;
}

Gato::Gato(dtGato* _gato, Socio* _socio): Mascota(_gato->getNombre(), _gato->getGenero(), _gato->getPeso()){
	this->racion = 0;
	this->duenio = _socio;
	this->tipoPelo = _gato->getTipoPelo();
}

Gato::Gato(dtMascota* _mascota, TipoPelo _tipo):Mascota(_mascota->getNombre(), _mascota->getGenero(), _mascota->getPeso()){
	this->tipoMascota = GATO;
	this->racion = 0;
	this->tipoPelo = _tipo;
}

Gato::Gato(Gato* _gato): Mascota(_gato->getNombre(), _gato->getGenero(), _gato->getPeso()){
	this->tipoPelo = _gato->tipoPelo;
}

void Gato::infoMascota(){
	Mascota::infoMascota();
	cout << "Tipo de pelo: " << getTipoPelo() << endl;
}

float Gato::getRacionDiaria(){
	float _racion = getPeso() * 0.015;
	setRacion(_racion);
	return _racion;
}

TipoPelo Gato::getTipoPelo(){
	return this->tipoPelo;
}

void Gato::setTipoPelo(TipoPelo _tipo){
	this->tipoPelo = _tipo;
}

Gato::~Gato(){}