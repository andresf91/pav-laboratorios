#ifndef DTPERRO_H
#define DTPERRO_H

#include "dtMascota.h"
#include "defMascotas.h"


class dtPerro: public dtMascota{
    private:
    RazaPerro raza;
    bool vacuna;
    
    public:
    dtPerro(string, Genero, RazaPerro, bool);
    void infoMascota();
    float getRacionDiaria();
    TipoMascota getTipo();
    bool getVacuna();
    RazaPerro getRaza();
    ~dtPerro();
};

#endif