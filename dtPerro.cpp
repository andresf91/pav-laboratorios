#include "dtPerro.h"
#include <iostream>

using namespace std;

void dtPerro::infoMascota(){
	dtMascota::infoMascota();
	cout << "Tiene vacuna del Cachorro: ";
	if (getVacuna())
	{
		cout << "Si" << endl;
	}else{
		cout << "No" << endl;
	}
}

// PERRO

dtPerro::dtPerro(string _nombre, Genero _genero,RazaPerro _raza, bool _vacuna):dtMascota(_nombre, _genero){
    this->raza = _raza;
	this->vacuna = _vacuna;
}

bool dtPerro::getVacuna(){
	return this->vacuna;
}

RazaPerro dtPerro::getRaza(){
	return this->raza;
}

dtPerro::~dtPerro(){}
