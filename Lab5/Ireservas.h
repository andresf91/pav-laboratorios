#ifndef IRESERVAS_H
#define IRESERVAS_H

#include "dtPelicula.h"
#include "dtCine.h"
#include "dtFuncion.h"
#include "dtFinanciera.h"
#include "dtFuncionConReservas.h"
#include <set>
#include <string>
using namespace std;

class Ireservas{
public:
    virtual void listarPeliculas() = 0;
    virtual void seleccionarPelicula(string titulo) = 0;
    virtual void mostrarSinopsisYPoster() = 0;
    virtual void listarCines() = 0;
    virtual void elegirCine(int nroCine) = 0;
    virtual void elegirFuncion(int nroFuncion) = 0;
    virtual void ingresarAsientos(int cantAsientos) = 0;
    virtual void ingresarBanco(string nombreBanco) = 0;
    virtual void obtDescuentoFinanciera(string financiera) = 0;
    virtual float obtenerPrecioTotal() = 0;
    virtual void confirmarReserva() = 0;
    virtual void cancelarReserva2() = 0;
    virtual void reintentarConOtraPelicula() = 0;
    virtual void cancelarYLiberarTitulo() = 0;
    virtual void cancelarReserva() = 0;
    virtual void detallesPelicula() = 0;
    virtual void cancelarYSalirVerInformacionPelicula() = 0;
    virtual void seleccionarCine2(int nroCine) = 0;
    virtual void listarFunciones() = 0;
    virtual void infoOtraPelicula() = 0;
    virtual void cancelarYSalirVerInformacionPelicula1() = 0;
    virtual void cancelarYSalirVerInformacionPelicula2() = 0;
    virtual void eliminarPelicula() = 0;
    virtual void cancelarYSalirEliminarPelicula() = 0;
    //virtual ~Ireservas() = 0;
};

#endif