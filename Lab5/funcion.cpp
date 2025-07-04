#include "funcion.h"

Funcion::Funcion(int _nroFuncion, DTfecha _fecha, DTtiempo _horario, Pelicula* _pelicula, Sala* _sala): fecha(_fecha), horario(_horario){
    this->nroFuncion = _nroFuncion;
    this->pelicula = _pelicula;
    this->sala = _sala;
}

bool Funcion::esFuncionDePelicula(string titulo) {
    if (getPelicula()->getTitulo() == titulo){
        return true;
    }else{
        return false;
    }
}

DTfuncion2 Funcion::getDTf2() {
    DTfuncion2 dtf2(getNroFuncion(), getFecha(), getHorario(), getCostoPorAsiento());
    return dtf2;
}

Pelicula* Funcion::getPelicula() {
    return this->pelicula;
}

int Funcion::getNroFuncion() {
    return this->nroFuncion;
}

float Funcion::getCostoPorAsiento() {
    return this->costoPorAsiento;
}

DTfecha Funcion::getFecha() {
    return this->fecha;
}

DTtiempo Funcion::getHorario() {
    return this->horario;
}

DTfuncion Funcion::getdtFuncion(){
    DTfuncion funcion=DTfuncion(getNroFuncion(),getFecha(),getHorario());
    return funcion;
}

void Funcion::setNroFuncion(int _nroFuncion) {
    this->nroFuncion = _nroFuncion;
}

void Funcion::setcostoPorAsiento(float _costoPorAsiento) {
    this->costoPorAsiento = _costoPorAsiento;
}

void Funcion::setFecha(DTfecha _fecha) {
    this->fecha = _fecha;
}

void Funcion::setHorario(DTtiempo _horario) {
    this->horario = _horario;
}

Funcion::~Funcion() {}