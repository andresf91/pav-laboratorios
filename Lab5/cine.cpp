#include "cine.h"

Cine::Cine(int _nroCine, string _direccion){
    this->nroCine = _nroCine;
    this->direccion = _direccion;
}

vector<DTfuncion2> Cine::getDTf2(string titulo) {
    vector<DTfuncion2> vecDTF2;
    vector<DTfuncion2> vecAux;
    for (auto it : salas){
        vecAux = it->getDTf2(titulo);
        for (auto it2 : vecAux){
            vecDTF2.push_back(it2);
        }
    }
    return vecDTF2;
}

int Cine::getNroCine(){
    return this->nroCine;
}

string Cine::getDireccion(){
    return this->direccion;
}

Sala* Cine::getSala() {
    return this->sala;
}

int Cine::getNroSalasCreadas() {
    return this->nroSalasCreadas;
}

int Cine::getCantFuncionesCreadas(){
   return this->cantFuncionesCreadas; 
}

vector<DTsalaConFunciones> Cine::getDTscfs(){
    vector<DTsalaConFunciones> dtscfs;
    for (auto it : salas) {
        DTsalaConFunciones Dtscfs=it->getDTScf();
        dtscfs.push_back(Dtscfs);
    }
    return dtscfs;
}// arreglar para que imprima el set y no lo retorne

vector<Sala*> Cine::getSalas(){
    return this->salas;
}

void Cine::setCantFuncionesCreadas(int cantFun){
    this->cantFuncionesCreadas=cantFun;
}

void Cine::setNroSalasCreadas(int valor) {
    this->nroSalasCreadas = valor;
}

void Cine::setDireccion(string _direccion){
    this->direccion = _direccion;
}

DTcine Cine::getDTcine(){
    DTcine dt=DTcine(getNroCine(),getDireccion());

    return dt;
}

void Cine::crearUnaSala(int capacidad){
    this->sala = new Sala(getNroSalasCreadas(), capacidad, this);
    setNroSalasCreadas(getNroSalasCreadas() + 1);
}

void Cine::agregarSala(Sala* sala){
    salas.push_back(sala);
}

Cine::~Cine(){
    for (Sala* s : salas) {
        delete s;
        s = nullptr;
    }
    salas.clear();
}