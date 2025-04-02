#ifndef CONSULTA_H
#define CONSULTA_H
#include <string>
#include "dtFecha.h"
#include "socio.h"

using namespace std;

class Socio;
class Fecha;

class Consulta{
    private:
        dtFecha fechaConsulta;
        string motivo;
        Socio* socio; // Socio al que pertenece
    public:
        // Consulta(); // Constructor por defecto
        Consulta(dtFecha, string, Socio*); // Constructor por pasaje de parámetros
        //Consulta(Consulta&); // Constructor de copia
        // Getters
        dtFecha& getFecha();
        string getMotivo();
        Socio* getSocio();
        void imprimirConsulta();
        // Setters
        void setMotivo(string);
        ~Consulta(); // Destructor
};

#endif