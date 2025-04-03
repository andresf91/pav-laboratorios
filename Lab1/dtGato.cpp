#include "dtGato.h"

dtGato::dtGato(string _nombre, Genero _genero, float _peso, TipoPelo _tipoPelo):dtMascota(_nombre, _genero, _peso){
	this->tipo = _tipoPelo;
	this->_tipoMascota = GATO;
}

TipoPelo dtGato::getTipoPelo(){
	return this->tipo;
}

dtGato::dtGato(string _nombre, Genero _genero, float _peso,TipoMascota _tipoMasc):dtMascota(_nombre, _genero, _peso){	
	this->_tipoMascota = _tipoMasc;
};

dtGato::~dtGato(){}