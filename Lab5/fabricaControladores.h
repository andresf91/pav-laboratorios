#ifndef FABRICACONTROLADORES_H
#define FABRICACONTROLADORES_H

#include "Ialtas.h"
#include "IpuntajesYComentarios.h"
#include "Ireservas.h"
#include "Isesion.h"
#include "controladorAltas.h"
#include "controladorPuntajesYComentarios.h"
#include "controladorReservas.h"
#include "controladorSesion.h"

class FabricaControladores {
private:
    FabricaControladores();
    ~FabricaControladores();
    static FabricaControladores* fabricaControladores;
    static Ialtas* controladorAltas;
    static IpuntajesYComentarios* controladorPuntajesYComentarios;
    static Ireservas* controladorReservas;
    static Isesion* controladorSesion;

public:
    static FabricaControladores* getFabrica();
    static void destroyFabrica();
    Ialtas* getControladorAltas();
    //IpuntajesYComentarios* getControladorPuntajesYComentarios();
    Ireservas* getControladorReservas();
    Isesion* getControladorSesion();
};

#endif // FABRICACONTROLADORES_H