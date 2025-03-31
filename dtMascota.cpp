#include "dtMascota.h"
#include <iostream>


dtMascota::dtMascota(string _nombre, Genero _genero){
    this->nombre = _nombre;
    this->genero = _genero;
    this->racion = 0;
}

void dtMascota::infoMascota(){
	cout << "Nombre: " << getNombre() << endl;
	cout << "Genero: " << getGenero() << endl;
	cout << "Peso: " << getPeso() << endl;
	cout << "Racion diaria: " << getRacionDiaria() << endl;
}

void dtGato::infoMascota(){
	dtMascota::infoMascota();
	cout << "Tipo de pelo: " << getTipoPelo() << endl;
}