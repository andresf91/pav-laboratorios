#ifndef SOCIO_H
#define SOCIO_H
#include <string>
#include "dtFecha.h"

using namespace std;
#include "mascota.h"
#include "perro.h"
#include "gato.h"
#include "consulta.h"

#define MAX_MASCOTAS 10 // Tamaño máximo de mascotas por socio
#define MAX_CONSULTAS 20 // Tamaño máximo de consultas por socio

class Mascota;
class Gato;
class Perro;
class Consulta;

class Socio{
    private:
        string ci;
        string nombre;
        dtFecha fechaIngreso;
        Mascota* mascotas[MAX_MASCOTAS]; // Arreglo de mascotas
        int numMascotas; // Contador de mascotas registradas
        Consulta* consultas[MAX_CONSULTAS]; // Arreglo de consultas
        int numConsultas; // Contador de consultas registradas
        
    public:
        Socio();
        Socio(string, string, dtFecha); // Constructor por pasaje de parámetros
        // Getters
        string getCi();
        string getNombre();
        dtFecha getFecha();
        Mascota** getMascotas(); // Retorna el arreglo de Mascotas
        int getNumMascotas();
        Consulta** getConsultas(); // Retorna el arreglo de Consultas
        int getNumConsultas();
        void push_back_perro(Perro*);
        void push_back_gato(Gato*);
        void agregarConsulta(Consulta* consulta);
        ~Socio(); // Destructor
};

#endif