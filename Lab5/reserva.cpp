#include "reserva.h"

Reserva::Reserva(int _cantAsientos, float _costoTotal, Usuario* usr, Funcion* func){
    this->cantAsientos = _cantAsientos;
    this->costoTotal = _costoTotal;
    this->usuario = usr;
    this->funcion = func;
}

int Reserva::getCantAsientos(){
    return this->cantAsientos;
}

float Reserva::getCostoTotal(){
    return this->costoTotal;
}

Usuario* Reserva::getUsuario(){
    return this->usuario;
}

Funcion* Reserva::getFuncion(){
    return this->funcion;
}

void Reserva::setCantAsientos(int _cantAsientos){
    this->cantAsientos = _cantAsientos;
}

void Reserva::setCostoTotal(float _costoTotal){
    this->costoTotal = _costoTotal;
}

Reserva::~Reserva(){
    this->usuario = nullptr;
    this->funcion = nullptr;
}
