#include "socio.h"
#include "consulta.h"
#include "dtFecha.h"
#include <iostream>

using namespace std;

Consulta::Consulta(Fecha _fecha, string _motivo, Socio* _socio):fechaConsulta(_fecha),motivo(_motivo),socio(_socio){}
Consulta::Consulta (const Consulta& c):fechaConsulta(c.fechaConsulta),motivo(c.motivo),socio(c.socio){}

Fecha& Consulta::getFecha(){
	return this->fechaConsulta;
}

string Consulta::getMotivo(){
	return this->motivo;
}

Socio* Consulta::getSocio(){
	return this->socio;
}



void Consulta::imprimirConsulta(){
	cout << "Fecha: ";
	fechaConsulta.imprimirFecha();
	cout << "Motivo: " << getMotivo() << endl;
}

void Consulta::setMotivo(string _motivo){
	this->motivo = _motivo;
}

Consulta::~Consulta(){}

