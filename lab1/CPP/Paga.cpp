#include "../Headers/Paga.h"

Paga::Paga() {
	monto = 0;
	moneda = Moneda::us;
}

Paga::Paga(float monto, Moneda moneda) {
	this->monto = monto;
	this->moneda = moneda;
}

Paga::Paga(const Paga &paga) {
	this->monto = paga.monto;
	this->moneda = paga.moneda;
}

Paga::~Paga() {

}

void Paga::setMonto(float monto) {
	this->monto = monto;
}

void Paga::setMoneda(Moneda moneda) {
	this->moneda = moneda;
}

float Paga::getMonto() {
	return monto;
}

Moneda Paga::getMoneda() {
	return moneda;
}

Paga Paga::a_dolar() {
	return a_peso(monto);
}
