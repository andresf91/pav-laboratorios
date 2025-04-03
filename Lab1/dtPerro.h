#ifndef DTPERRO_H
#define DTPERRO_H

#include "dtMascota.h"
#include "dtPerro.h"
#include "defMascotas.h"


class dtPerro: public dtMascota{
    private:
    RazaPerro raza;
    bool vacuna;
    TipoMascota _tipoMascota;
    public:
    dtPerro(string, Genero, float, RazaPerro, bool);
    dtPerro(string, Genero, float, TipoMascota);
    TipoMascota getTipoMascota();
    RazaPerro getRaza();
    bool getVacuna();
    ~dtPerro();
};

#endif