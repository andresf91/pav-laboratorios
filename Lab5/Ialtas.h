#ifndef ALTAS_H
#define ALTAS_H

#include <set>
#include <string>
using namespace std;

#include "dtFecha.h"
#include "dtTiempo.h"
#include "dtCine.h"
#include "dtSalaConFunciones.h"


class Ialtas{
public:
    virtual void agregarUnCine(string direccion) = 0;
    virtual void agregarCapacidad(int capacidad) = 0;
    virtual void confirmarAlta() = 0;
    virtual void cancelarYReintentarAltaCine() = 0;
    virtual void cancelarYSalirDeAltaCine() = 0;
    virtual void listarPeliculas() = 0;
    virtual void seleccionarPelicula(string titulo) = 0;
    virtual void listarCines() = 0;
    virtual void seleccionarCine(int nroCine) = 0;
    virtual void seleccionarSala(int nroSala) = 0;
    virtual void ingresarDetallesFuncion(DTfecha fecha, DTtiempo hora) = 0;
    virtual void terminarDeAgregarFunciones() = 0;
    virtual bool ingresarUsuario(string nickname, string clave) = 0;
    virtual void ingresarUrl(string urlFoto) = 0;
    virtual void confirmarAltaUsuario() = 0;
    virtual void cancelarYReintentarAltaUsuario() = 0;
    virtual void cancelarAlta() = 0;
    virtual bool ingresarPelicula(string titulo, string sinopsis, string urlPoster) = 0;
    virtual void confirmarAltaPeli() = 0;
    virtual void reintentarConOtroTitulo() = 0;
    virtual void cancelarAltaPeli() = 0;
    //virtual ~Ialtas() = 0;
};

#endif