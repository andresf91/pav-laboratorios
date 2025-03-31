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
        Fecha fechaConsulta;
        string motivo;
        Socio* socio; // Socio al que pertenece
    public:
        // Consulta(); // Constructor por defecto
        Consulta(Fecha, string, Socio*); // Constructor por pasaje de parámetros
        Consulta(const Consulta&); // Constructor de copia
        // Getters
        Fecha& getFecha();
        string getMotivo();
        Socio* getSocio();
        void imprimirConsulta();
        // Setters
        void setMotivo(string);
        ~Consulta(); // Destructor
};

#endif