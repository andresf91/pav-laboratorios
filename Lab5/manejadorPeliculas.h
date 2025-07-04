#ifndef MANEJADORPELICULAS_H
#define MANEJADORPELICULAS_H

#include "pelicula.h"
#include <map>
#include <string>

class ManejadorPeliculas {
private:
    static ManejadorPeliculas* instancia;
    map<string, Pelicula*> peliculas;
    ManejadorPeliculas();
    ~ManejadorPeliculas();
public:
    static ManejadorPeliculas* getInstancia();
    static void destroyInstancia();
    map<string, Pelicula*> getPeliculas();
    void agregarPelicula(Pelicula* peli);
    Pelicula* obtenerPelicula(string titulo);
    bool existePelicula(string titulo);
    void eliminarPelicula(string titulo);
};

#endif // MANEJADORPELICULAS_H