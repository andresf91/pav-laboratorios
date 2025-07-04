#ifndef DTFINANCIERA_H
#define DTFINANCIERA_H

class DTfinanciera{
private:
    bool tieneDescuento;
    float porcentajeDescuento;
public:
    DTfinanciera(bool, float);
    bool getTieneDescuento();
    float getPorcentajeDescuento();
};

#endif