#ifndef PAGA_H
#define PAGA_H

#include "Moneda.h"
#include <iostream>
#include <math.h>

class Paga {
private:
	float monto;
	Moneda moneda;
public:
	Paga();
	Paga(float, Moneda);
	Paga(const Paga &);
	~Paga();
	void setMonto(float);
	void setMoneda(Moneda);
	float getMonto();
	Moneda getMoneda();
	Paga a_dolar();
	Paga a_peso();
};

#endif