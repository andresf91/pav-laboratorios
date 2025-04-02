#ifndef GATO_H
#define GATO_H
#include "mascota.h"
#include "dtMascota.h"
#include "dtGato.h"

class Gato: public Mascota{
    private:
        TipoMascota _tipo = GATO;
        TipoPelo tipoPelo;
    public:
        Gato(string, Genero, float, Socio*, TipoPelo);
        Gato(string, Genero, float, TipoPelo);
		Gato(dtGato*, Socio*);
        Gato(Gato*);
        Gato(dtMascota*, TipoPelo);
        void infoMascota();
        float getRacionDiaria();
        TipoPelo getTipoPelo(); // Getter
        void setTipoPelo(TipoPelo); // Setter
        ~Gato(); // Desctructor
};
#endif