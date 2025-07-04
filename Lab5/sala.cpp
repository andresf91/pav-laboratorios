#include "sala.h"

Sala::Sala(int _nroSala, int _capacidad, Cine* _cine){
    this->nroSala = _nroSala;
    this->capacidad = _capacidad;
    this->cine = _cine;
}

vector<DTfuncion2> Sala::getDTf2(string titulo) {
    vector<DTfuncion2> vecDTF2;
    for (auto it : funciones){
        if (it->getPelicula()->getTitulo() == titulo){
            DTfuncion2 dtf2 = it->getDTf2();
            vecDTF2.push_back(dtf2);
        }
    }
    return vecDTF2;
}

int Sala::getNroSala(){
    return this->nroSala;
}

int Sala::getCapacidad(){
    return this->capacidad;
}

void Sala::agregarFuncion(Funcion* func){
    funciones.push_back(func);
}

DTsalaConFunciones Sala::getDTScf(){
    vector<DTfuncion> dtfunciones; 
    for(auto it : funciones){
        DTfuncion funcion=DTfuncion(it->getNroFuncion(),it->getFecha(),it->getHorario());
        dtfunciones.push_back(funcion); 
    }
    DTsalaConFunciones salaConFunciones=DTsalaConFunciones(getNroSala(),getCapacidad(),dtfunciones);
    return salaConFunciones;
}

vector<Funcion*> Sala::getFunciones() {
    return this->funciones;
}

Sala::~Sala(){
    this->cine = nullptr;
    for (Funcion* f : funciones) {
        delete f;
        f = nullptr;
    }
    funciones.clear();
}