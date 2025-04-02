#include "mascota.h"
#include "socio.h"
#include <iostream>


// MASCOTA

Mascota::Mascota(string _nombre,Genero _genero, float _peso, Socio* _duenio){
    this->nombre = _nombre;
    this->genero = _genero;
    this->peso = _peso;
    this->duenio = _duenio;
    this->racion = 0;
}

Mascota::Mascota(string _nombre,Genero _genero, float _peso){
    this->nombre = _nombre;
    this->genero = _genero;
    this->peso = _peso;
    this->duenio = nullptr;
    this->racion = 0;
}

void Mascota::infoMascota(){
	cout << "Nombre: " << getNombre() << endl;
	cout << "Genero: " << getGenero() << endl;
	cout << "Peso: " << getPeso() << endl;
	cout << "Racion diaria: " << getRacionDiaria() << endl;
}

float Mascota::getRacionDiaria(){
	return this->racion;
}

TipoMascota Mascota::getTipoMascota(){
	return this->tipoMascota;
}


string Mascota::getNombre(){
	return this->nombre;
}

Genero Mascota::getGenero(){
	return this->genero;
}

float Mascota::getPeso(){
	return this->peso;
}

float Mascota::getRacion(){
	return this->racion;
}

Socio* Mascota::getSocio(){
	return this->duenio;
}

void Mascota::setDuenio(Socio* _duenio){
	this->duenio = _duenio;
}

void Mascota::setPeso(float _peso){
	this->peso = _peso;
}

void Mascota::setRacion(float _racion){
	this->racion = _racion;
}

Mascota::~Mascota(){
	//setDuenio(nullptr);
	if(getSocio() != nullptr){
		delete getSocio();
	}

} // Error: Exception has occurred (Unknow signal)