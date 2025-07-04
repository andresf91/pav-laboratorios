#include "fabricaControladores.h"

FabricaControladores* FabricaControladores::fabricaControladores = nullptr;
Ialtas* FabricaControladores::controladorAltas = nullptr;
IpuntajesYComentarios* FabricaControladores::controladorPuntajesYComentarios = nullptr;
Ireservas* FabricaControladores::controladorReservas = nullptr;
Isesion* FabricaControladores::controladorSesion = nullptr;

FabricaControladores::FabricaControladores(){}

FabricaControladores* FabricaControladores::getFabrica() {
    if (fabricaControladores == nullptr){
        fabricaControladores = new FabricaControladores();
    }
    return fabricaControladores;
}

Ialtas* FabricaControladores::getControladorAltas() {
    if (controladorAltas == nullptr) {
        controladorAltas = ControladorAltas::getControladorAltas();
    }
    return controladorAltas;
}
/*
IpuntajesYComentarios* FabricaControladores::getControladorPuntajesYComentarios() {
    if (controladorPuntajesYComentarios == nullptr) {
        controladorPuntajesYComentarios = ControladorPuntajesYComentarios::getControladorPuntajesYComentarios();
    }
    return controladorPuntajesYComentarios;
}
*/
Ireservas* FabricaControladores::getControladorReservas() {
    if (controladorReservas == nullptr) {
        controladorReservas = ControladorReservas::getControladorReservas();
    }
    return controladorReservas;
}

Isesion* FabricaControladores::getControladorSesion() {
    if (controladorSesion == nullptr) {
        controladorSesion = ControladorSesion::getControladorSesion();
    }
    return controladorSesion;
}

FabricaControladores::~FabricaControladores(){}

void FabricaControladores::destroyFabrica() {
    if (fabricaControladores != nullptr) {
        delete fabricaControladores;
        fabricaControladores = nullptr;
    }
}