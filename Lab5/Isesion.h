#ifndef ISESION_H
#define ISESION_H

#include <string>
using namespace std;

class DTfecha;
class DTtiempo;
class DTcine;
class DTsalaConFunciones;


class Isesion{
public:
    virtual void ingresarUsuario(string nickname) = 0;
    virtual bool ingresarClave(string password) = 0;
    virtual void confirmarInicioDeSesion() = 0;
    virtual void cancelarInicioDeSesion() = 0;
    virtual void cerrarSesion() = 0;
};

#endif