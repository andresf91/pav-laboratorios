#ifndef MANEJADORCINES_H
#define MANEJADORCINES_H

#include "cine.h"
#include <map>
#include <string>

class ManejadorCines {
private:
    static ManejadorCines* instancia;
    map<string, Cine*> cines;
    int cantCinesCreados;
    ManejadorCines();
    ~ManejadorCines();
public:
    static ManejadorCines* getInstancia();
    static void destroyInstancia();
    map<string, Cine*> getCines();
    void agregarCine(Cine* cine);
    Cine* obtenerCine(string);
    bool existeCine(string);
    void eliminarCine(string);
    int getCantCinesCreados();
    void setCantCinesCreados(int);
};

#endif // MANEJADORCINES_H