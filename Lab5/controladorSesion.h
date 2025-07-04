#ifndef CONTROLADORSESION_H
#define CONTROLADORSESION_H

#include "Isesion.h"
#include "usuario.h"
#include "manejadorUsuarios.h"
#include "sesion.h"
#include <iostream>

class ControladorSesion : public Isesion{
private:
    static ControladorSesion* instancia;
    Usuario* usuario;
    string nickname;
    ControladorSesion();
    ~ControladorSesion();
public:
    void ingresarUsuario(string nickname);
    bool ingresarClave(string password);
    void confirmarInicioDeSesion();
    void cancelarInicioDeSesion(); // agregar un break en el main
    void cerrarSesion();
    Usuario* getUsuario();
    string getNickname();
    void setUsuario(Usuario*);
    void setNickname(string);
    static ControladorSesion* getControladorSesion();
    static void destroyControladorSesion();
};

#endif