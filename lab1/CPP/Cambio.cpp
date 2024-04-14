#include "../Headers/Cambio.h"

float Cambio::a_peso(float monto) {
	return monto * usd;
}

float Cambio::a_dolar(float monto) {
	return monto / usd;
}