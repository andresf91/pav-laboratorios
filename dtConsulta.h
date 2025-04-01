#ifndef DTCONSULTA_H
#define DTCONSULTA_H

#include <string>
#include "dtFecha.h"
using namespace std;

class dtConsulta{
private:
	dtFecha fechaConsulta;
	string motivo;
public:
	dtConsulta(dtFecha, string);
	dtFecha getFechaConsulta();
	string getMotivo();
};

#endif