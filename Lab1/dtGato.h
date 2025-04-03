#ifndef DTGATO_H
#define DTGATO_H

#include "dtMascota.h"

class dtGato: public dtMascota{
    private:
    TipoPelo tipo;
    TipoMascota _tipoMascota;
    public:
    dtGato(string, Genero, float, TipoPelo);
    dtGato(string, Genero, float, TipoMascota);
    TipoPelo getTipoPelo(); // Getter
    ~dtGato();
};

#endif