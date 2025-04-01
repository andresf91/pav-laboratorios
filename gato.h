#ifndef GATO_H
#define GATO_H
#include "mascota.h"
#include "dtGato.h"

class Gato: public Mascota{
    private:
        TipoMascota _tipo = GATO;
        TipoPelo tipoPelo;
    public:
        Gato(string, Genero, float, Socio*, TipoPelo);
        Gato(string, Genero, float, TipoPelo);
		Gato(dtGato*, Socio*);
        void infoMascota();
        float getRacionDiaria();
        TipoMascota getTipo();
        TipoPelo getTipoPelo(); // Getter
        void setTipoPelo(TipoPelo); // Setter
        ~Gato(); // Desctructor
};
#endif