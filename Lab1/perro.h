#ifndef PERRO_H
#define PERRO_H

#include "mascota.h"
#include "dtMascota.h"
#include "dtPerro.h"


class Perro: public Mascota{
    private:
        TipoMascota _tipo = PERRO;
        RazaPerro raza;
        bool vacuna;
    public:
        // Perro(); Constructor por defecto
        Perro(string, Genero, float, Socio*, RazaPerro, bool);
        Perro(string, Genero, float, RazaPerro, bool);
        Perro(dtPerro*, Socio*);
        void infoMascota();
        float getRacionDiaria();
        // Getters
        bool getVacuna();
        RazaPerro getRaza();
        // Setters
        void setVacuna(bool);
        void setRaza(RazaPerro);
        ~Perro(); // Destructor
};

#endif