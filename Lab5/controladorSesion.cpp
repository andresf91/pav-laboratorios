#include "controladorSesion.h"

// Inicialización de la instancia estática
ControladorSesion* ControladorSesion::instancia = nullptr;

ControladorSesion::ControladorSesion() {}

void ControladorSesion::ingresarUsuario(string nickname) {
    string nick = nickname;
    ManejadorUsuarios* manejador = ManejadorUsuarios::getInstancia();
    do{
        if (manejador->obtenerUsuario(nick) == nullptr){
            cout << "Usuario no encontrado. Intente nuevamente." << endl;
            cout << "Ingrese nuevamente el nickname: " << endl;
            cin >> nick;
        }
    }while(manejador->obtenerUsuario(nick) == nullptr);
    setNickname(nick);
    this->usuario = manejador->obtenerUsuario(nick);
}

bool ControladorSesion::ingresarClave(string password){
        if (getUsuario()->getContrasenia() == password){
            Sesion::getInstancia()->setNickname(getNickname());
            return true;
        }else{
            cout << "Contraseña incorrecta." << endl;
            return false;
        }
}

void ControladorSesion::confirmarInicioDeSesion(){
        Sesion::getInstancia()->setNickname(getNickname());
        cout << endl << "Inicio de sesión exitoso. Bienvenido " << getNickname() << "!" << endl;
}

void ControladorSesion::cancelarInicioDeSesion(){
    this->usuario = nullptr;
}

void ControladorSesion::cerrarSesion(){
    cout << "Adios " << Sesion::getInstancia()->getNickname() << "!" <<endl;
    Sesion::getInstancia()->setNickname("");
}

Usuario* ControladorSesion::getUsuario(){
    return this->usuario; 
}

string ControladorSesion::getNickname(){
    return this-> nickname;
}

void ControladorSesion::setUsuario(Usuario* usuario){
    this-> usuario = usuario;
}

void ControladorSesion::setNickname(string nickname){
    this-> nickname = nickname;
}

ControladorSesion* ControladorSesion::getControladorSesion() {
    if (instancia == nullptr) {
        instancia = new ControladorSesion();
    }
    return instancia;
}

void ControladorSesion::destroyControladorSesion() {
    if (instancia != nullptr) {
        delete instancia;
        instancia = nullptr;
    }
}

ControladorSesion::~ControladorSesion() {
    this->usuario = nullptr;
}