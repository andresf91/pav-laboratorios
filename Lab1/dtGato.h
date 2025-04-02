#ifndef DTGATO_H
#define DTGATO_H

#include "dtMascota.h"
#include "defMascotas.h"

class dtGato: public dtMascota{
    private:
    TipoPelo tipo;
    TipoMascota _tipoMascota;
    public:
    dtGato(string, Genero, float, TipoPelo);
    TipoPelo getTipoPelo(); // Getter
    ~dtGato();
};

#endif