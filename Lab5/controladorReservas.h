#ifndef CONTROLADORRESERVAS_H
#define CONTROLADORRESERVAS_H

#include "Ireservas.h"
#include "dtFuncion2.h"
#include "dtFecha.h"
#include "dtTiempo.h"
#include "tipoPago.h"
#include "funcion.h"
#include "dtFuncion.h"
#include "dtPelicula.h"
#include "manejadorPeliculas.h"
#include "manejadorFinancieras.h"
#include "manejadorUsuarios.h"
#include "manejadorCines.h"
#include "sesion.h"
#include "credito.h"
#include "debito.h"
#include <chrono>
#include <string>
#include <iostream>
#include <set>
using namespace std;

class ControladorReservas : public Ireservas{
private: 
    static ControladorReservas* instancia;
    Funcion* funcion;
    string titulo;
    string urlPoster;
    string sinopsis;
    TipoPago tipo;
    int nroCine;
    int nroFuncion;
    int cantAsientos;
    string nombreBanco = "";
    string nombreFinanciera = "";
    float precioTotal;
    set<int> nrosFunciones;
    ControladorReservas();
    ~ControladorReservas();
public:
    void listarPeliculas();
    void seleccionarPelicula(string titulo);
    void mostrarSinopsisYPoster();
    void listarCines();
    void elegirCine(int nroCine);
    void elegirFuncion(int nroFuncion);
    void ingresarAsientos(int cantAsientos);
    void ingresarBanco(string nombreBanco);
    void obtDescuentoFinanciera(string financiera);
    float obtenerPrecioTotal();
    void confirmarReserva();
    void cancelarReserva2();
    void reintentarConOtraPelicula();
    void cancelarYLiberarTitulo();
    void cancelarReserva();
    void detallesPelicula();
    void cancelarYSalirVerInformacionPelicula();
    void seleccionarCine2(int nroCine);//hasta aca llegamos
    void listarFunciones();
    void infoOtraPelicula();
    void cancelarYSalirVerInformacionPelicula1();
    void cancelarYSalirVerInformacionPelicula2();
    void eliminarPelicula();
    void cancelarYSalirEliminarPelicula();
    bool esHorarioPrevio(DTtiempo horario1, DTtiempo horario2);
    bool esPrevia(DTfecha fecha1, DTfecha fecha2);
    void setTitulo(string);
    void setFuncion(Funcion*);
    void setNombreBanco(string);
    void setNroCine(int);
    void setNroFuncion(int);
    void setTipoReserva(TipoPago);
    void setPrecioTotal(float);
    void agregarAlSetNroFunciones(int);
    set<int> getNrosFunciones();
    string getTitulo();
    Funcion* getFuncion();
    string getUrlPoster();
    string getSinopsis();
    int getNroCine();
    float getPrecioTotal();
    TipoPago getTipo();
    int getNroFuncion();
    int getCantAsientos();
    string getNombreBanco();
    string getNombreFinanciera();
    static ControladorReservas* getControladorReservas();
    static void destroyControladorReservas();
};

#endif