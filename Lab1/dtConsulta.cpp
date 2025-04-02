#include "dtConsulta.h"

dtConsulta::dtConsulta(dtFecha _fecha, string _motivo):fechaConsulta(_fecha){
	this->motivo = _motivo;
}

dtFecha dtConsulta::getFechaConsulta(){
	return this->fechaConsulta;
}

string dtConsulta::getMotivo(){
	return this->motivo;
}