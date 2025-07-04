#include "credito.h"

Credito::Credito(int _cantAsientos, float _costoTotal, Usuario* usr, Funcion* func, float _descuento, string _financiera): Reserva(_cantAsientos, _costoTotal, usr, func) {
    this->descuento = _descuento;
    this->financiera = _financiera;
}

float Credito::getDescuento(){
    return this->descuento;
}

string Credito::getFinanciera(){
    return this->financiera;
}

DTreserva Credito::getDTR() {
    return DTreserva(getCantAsientos(), getCostoTotal(), CREDITO);
}

void Credito::setDescuento(float _descuento){
    this->descuento = _descuento;
}

void Credito::setFinanciera(string _financiera){
    this->financiera = _financiera;
}

Credito::~Credito(){
    Reserva::~Reserva();
}