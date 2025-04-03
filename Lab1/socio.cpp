#include "socio.h"
#include "dtFecha.h"
#include "consulta.h"
#include <stdexcept> // Para std::runtime_error

Socio::Socio() : ci(""), nombre(""), fechaIngreso(1,1,2025), numMascotas(0), numConsultas(0){
    for (int i = 0; i < MAX_MASCOTAS; ++i)
        mascotas[i] = nullptr;
    for (int i = 0; i < MAX_CONSULTAS; ++i)
        consultas[i] = nullptr;
}

Socio::Socio(std::string _ci, std::string _nombre, dtFecha _fecha): ci(_ci), nombre(_nombre), fechaIngreso(_fecha), numMascotas(0), numConsultas(0) {
    for (int i = 0; i < MAX_MASCOTAS; ++i)
        mascotas[i] = nullptr;
    for (int i = 0; i < MAX_CONSULTAS; ++i)
        consultas[i] = nullptr;
}

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
  return this->numMascotas;
}

Consulta** Socio::getConsultas(){ // Retorna el arreglo
 return this->consultas;
}

int Socio::getNumConsultas(){
	return numConsultas;
}

void Socio::push_back_perro(Perro* mascota){
   // Mascota* ptrMascota= mascota;
    if (this->getNumMascotas() < MAX_MASCOTAS) {
    
           Perro* nuevoPerro = new Perro(mascota);
            mascotas[numMascotas] = nuevoPerro;
   }
    numMascotas++;

}

void Socio::push_back_gato(Gato* mascota){
   // Mascota* ptrMascota= mascota;
    if (numMascotas < MAX_MASCOTAS) {
    
           Gato* nuevoGato = new Gato(mascota);
            mascotas[numMascotas] = nuevoGato;
   }
    numMascotas++;

}

void Socio::agregarConsulta(Consulta* consulta) { // <<--- Usa Socio::
    if (numConsultas < MAX_CONSULTAS) {
        consultas[numConsultas] = consulta;
        numConsultas++;
    } else {
        throw std::runtime_error("No hay espacio para más consultas");
    }
}

dtFecha Socio::getFecha() {
    return this->fechaIngreso;
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