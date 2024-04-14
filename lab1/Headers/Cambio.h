#ifndef CAMBIO_H
#define CAMBIO_H
#include <iostream>
#include "math.h"
using namespace std;

static class Cambio {
private:
	const float usd = 39.05;
public:
	//no se definen constructors ya que no es necesario
	float a_peso(float);
	float a_dolar(float);
};


#endif