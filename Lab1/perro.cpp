#include "mascota.h"
#include "perro.h"
#include <iostream>

Perro::Perro(string _nombre, Genero _genero, float _peso, Socio* _duenio, RazaPerro _raza, bool _vacuna):Mascota(_nombre, _genero, _peso){
	this->duenio = _duenio;
	this->raza = _raza;
	this->vacuna = _vacuna;
}

Perro::Perro(string _nombre, Genero _genero, float _peso,RazaPerro _raza, bool _vacuna):Mascota(_nombre, _genero, _peso){
    this->raza = _raza;
	this->vacuna = _vacuna;
}


Perro::Perro(dtPerro* _perro, Socio* _socio): Mascota(_perro->getNombre(), _perro->getGenero(), _perro->getPeso()){
	this->racion = 0;
	this->duenio = _socio;
	this->raza = _perro->getRaza();
	this->vacuna = _perro->getVacuna();
}

void Perro::infoMascota(){
	Mascota::infoMascota();
	cout << "Tiene vacuna del Cachorro: ";
	if (getVacuna())
	{
		cout << "Si" << endl;
	}else{
		cout << "No" << endl;
	}
}

float Perro::getRacionDiaria(){
	float _racion = getPeso() * 0.025;
	setRacion(_racion);
	return _racion;
}

bool Perro::getVacuna(){
	return this->vacuna;
}

RazaPerro Perro::getRaza(){
	return this->raza;
}

void Perro::setVacuna(bool _vacuna){
	this->vacuna = _vacuna;
}

void Perro::setRaza(RazaPerro _raza){
	this->raza = _raza;
}

Perro::~Perro(){}