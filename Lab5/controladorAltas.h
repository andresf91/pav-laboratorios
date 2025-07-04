#ifndef CONTROLADORALTAS_H
#define CONTROLADORALTAS_H

#include "Ialtas.h"
#include "cine.h"
#include "funcion.h"
#include "dtCine.h"
#include "manejadorCines.h"
#include "manejadorPeliculas.h"
#include "manejadorUsuarios.h"
#include <iostream>
#include <vector>

class ControladorAltas: public Ialtas {
private:
    static ControladorAltas* instancia;
    Cine* cine;
    //Funcion* funcion;
    string direccion;
    string titulo;
    string sinopsis;
    string nickname;
    string clave;
    string urlFoto = "";
    string urlPoster;
    int nroCine;
    int nroSala;
    vector<int> capacidadesDeSalas;
    ControladorAltas();
    ~ControladorAltas();
public:
    void agregarUnCine(string direccion);
    void agregarCapacidad(int capacidad);
    void confirmarAlta();
    void cancelarYReintentarAltaCine();
    void cancelarYSalirDeAltaCine();
    void listarPeliculas();
    void seleccionarPelicula(string titulo);
    void listarCines();
    void seleccionarCine(int nroCine);
    void seleccionarSala(int nroSala);
    void ingresarDetallesFuncion(DTfecha fecha, DTtiempo hora);
    void terminarDeAgregarFunciones();
    bool ingresarUsuario(string nickname, string clave);
    void ingresarUrl(string urlFoto);
    void confirmarAltaUsuario();
    void cancelarYReintentarAltaUsuario();
    void cancelarAlta();
    bool ingresarPelicula(string titulo, string sinopsis, string urlPoster);
    void confirmarAltaPeli();
    void reintentarConOtroTitulo();
    void cancelarAltaPeli();
    Cine* getCine();
    string getDireccion();
    string getTitulo();
    string getSinopsis();
    string getNickname();
    string getClave();
    string getUrlFoto();
    string getUrlPoster();
    int getNroCine();
    int getNroSala();
    vector<int> getCapacidadesDeSalas();
    void setCine(Cine *);
    void setDireccion(string);
    void setTitulo(string);
    void setSinopsis(string);
    void setNickname(string);
    void setClave(string);
    void setUrlFoto(string);
    void setUrlPoster(string);
    void setNroCine(int);
    void setNroSala(int);
    static ControladorAltas* getControladorAltas();
    static void destroyControladorAltas();
};

#endif