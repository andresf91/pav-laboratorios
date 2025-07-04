#include "debito.h"

Debito::Debito(int _cantAsientos, float _costoTotal, Usuario* usr, Funcion* func, string _nombreBanco): Reserva(_cantAsientos, _costoTotal, usr, func) {
    this->nombreBanco = _nombreBanco;
}

string Debito::getNombreBanco(){
    return this->nombreBanco;
}

DTreserva Debito::getDTR() {
    return DTreserva(getCantAsientos(), getCostoTotal(), DEBITO);
}

void Debito::setNombreBanco(string _nombreBanco){
    this->nombreBanco = _nombreBanco;
}

Debito::~Debito(){
    Reserva::~Reserva();
}