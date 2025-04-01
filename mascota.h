#ifndef MASCOTA_H
#define MASCOTA_H
#include <string>
#include "defMascotas.h"
#include "socio.h"

class Socio;

using namespace std;

class Mascota {
    protected:
        string nombre;
        Genero genero;
        float peso;
        float racion;
        Socio* duenio;
    public:
    //Mascota(); Constructor por defecto
    Mascota(string, Genero, float, Socio*); // Constructor por pasaje de parámetros.
    Mascota(string, Genero, float);
     // Constructor por pasaje de parámetros.
    virtual void infoMascota(); // polimorfismo
    virtual float getRacionDiaria();
    // Getters
    string getNombre();
    Genero getGenero();
    float getPeso();
    float getRacion();
    Socio* getSocio();
    void setDuenio(Socio*);
    void setRacion(float);
    void setPeso(float); // Setter
    ~Mascota(); // Desctructor
};

#endif