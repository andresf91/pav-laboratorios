#ifndef DTPERRO_H
#define DTPERRO_H

#include "dtMascota.h"
#include "dtPerro.h"
#include "defMascotas.h"


class dtPerro: public dtMascota{
    private:
    RazaPerro raza;
    bool vacuna;
    TipoMascota tipo;
    public:
    dtPerro(string, Genero, float, RazaPerro, bool);
    TipoMascota getTipoMascota();
    RazaPerro getRaza();
    bool getVacuna();
    ~dtPerro();
};

#endif