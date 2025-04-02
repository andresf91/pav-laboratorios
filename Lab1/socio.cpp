#include "socio.h"
#include "dtFecha.h"
#include "consulta.h"
#include <stdexcept> // Para std::runtime_error

Socio::Socio() : ci(""), nombre(""), fechaIngreso(dtFecha(1,1,2025)), numMascotas(0), numConsultas(0){}

Socio::Socio(std::string _ci, std::string _nombre, dtFecha _fecha): ci(_ci), nombre(_nombre), fechaIngreso(_fecha), numMascotas(0), numConsultas(0) {}

string Socio::getCi(){
	return this->ci;
}

string Socio::getNombre(){
	return this->nombre;
}

Mascota** Socio::getMascotas(){  // Retorna el arreglo
 return this->mascotas; 
 }

int Socio::getNumMascotas(){
  return numMascotas;
}

Consulta** Socio::getConsultas(){ // Retorna el arreglo
 return this->consultas;
}

int Socio::getNumConsultas(){
	return numConsultas;
}

void Socio::push_back(Mascota* mascota){
    Mascota* ptrMascota= mascota;
    if (numMascotas < MAX_MASCOTAS) {
        mascotas[numMascotas] = ptrMascota;
        numMascotas++;
    } else {
        throw std::runtime_error("No hay espacio para más mascotas");
    }
}

void Socio::agregarConsulta(Consulta* consulta) { // <<--- Usa Socio::
    if (numConsultas < MAX_CONSULTAS) {
        consultas[numConsultas] = consulta;
        numConsultas++;
    } else {
        throw std::runtime_error("No hay espacio para más consultas");
    }
}

// Destructor para liberar la memoria
Socio::~Socio() {
    // Liberar memoria de las mascotas y consultas
    for (int i = 0; i < numMascotas; i++) {
        delete mascotas[i];
    }
    for (int i = 0; i < numConsultas; i++) {
        delete consultas[i];
    }
}