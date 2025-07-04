#include "dtFinanciera.h"

DTfinanciera::DTfinanciera(bool tieneD, float porcentajeD) {
    this->tieneDescuento = tieneD;
    this->porcentajeDescuento = porcentajeD;
}

bool DTfinanciera::getTieneDescuento() {
    return this->tieneDescuento;
}

float DTfinanciera::getPorcentajeDescuento() {
    return this->porcentajeDescuento;
}