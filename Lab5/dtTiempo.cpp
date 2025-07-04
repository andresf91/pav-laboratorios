#include "dtTiempo.h"

DTtiempo::DTtiempo(int hora, int minuto) {
    this->hora = hora;
    this->minuto = minuto;
}

int DTtiempo::getHora() {
    return this->hora;
}

int DTtiempo::getMinuto() {
    return this->minuto;
}