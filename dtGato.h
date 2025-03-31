#ifndef DTGATO_H
#define DTGATO_H

#include "dtMascota.h"
#include "defMascotas.h"

class dtGato: public dtMascota{
    private:
    TipoPelo tipo;

    public:
    dtGato(string, Genero, )
    void infoMascota();
    float getRacionDiaria();
    TipoMascota getTipo();
    TipoPelo getTipoPelo(); // Getter
};

#endif