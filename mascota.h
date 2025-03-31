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
    Mascota(string, Genero, float); // Constructor por pasaje de parámetros.
    virtual float obtenerRacionDiaria(); // polimorfismo
   // virtual TipoMascota getTipo(); // OJO
    
    // Getters
    virtual TipoMascota getTipo() = 0;
    string getNombre();
    Genero getGenero();
    float getPeso();
    Socio* getSocio();
    void setDuenio(Socio*);
    void setRacion(float);
    void setPeso(float); // Setter
    ~Mascota(); // Desctructor
};

class Perro: public Mascota{
    private:
        TipoMascota _tipo = PERRO;
        RazaPerro raza;
        bool vacunaCachorro;
    public:
        // Perro(); Constructor por defecto
        Perro(string, Genero, float, Socio*, RazaPerro, bool);
        Perro(string, Genero, float, RazaPerro, bool);
        float obtenerRacionDiaria();
        TipoMascota getTipo();
        // Getters
        bool getVacuna();
        RazaPerro getRaza();
        // Setters
        void setVacuna(bool);
        void setRaza(RazaPerro);
        ~Perro(); // Destructor
};

class Gato: public Mascota{
    private:
        TipoMascota _tipo = GATO;
        TipoPelo tipoPelo;
    public:
        Gato(string, Genero, float, Socio*, TipoPelo);
        Gato(string, Genero, float, TipoPelo);
        float obtenerRacionDiaria();
        TipoMascota getTipo();
        TipoPelo getTipoPelo(); // Getter
        void setTipoPelo(TipoPelo); // Setter
        ~Gato(); // Desctructor
};

#endif