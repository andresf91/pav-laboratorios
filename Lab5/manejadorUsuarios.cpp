#include "manejadorUsuarios.h"
#include <iostream>

ManejadorUsuarios* ManejadorUsuarios::instancia = nullptr;

ManejadorUsuarios::ManejadorUsuarios() {
    // Crear el usuario administrador por defecto al inicializar el manejador
    Usuario* admin = new Usuario("admin", "admin123");
    usuarios["admin"] = admin;
}

ManejadorUsuarios* ManejadorUsuarios::getInstancia() {
    if (instancia == nullptr) {
        instancia = new ManejadorUsuarios();
    }
    return instancia;
}

void ManejadorUsuarios::agregarUsuario(Usuario* usuario) {
    if (usuario != nullptr && !existeUsuario(usuario->getNickname())) {
        usuarios[usuario->getNickname()] = usuario;
    }
}

Usuario* ManejadorUsuarios::obtenerUsuario(string nickname) {
    auto it = usuarios.find(nickname);
    if (it != usuarios.end()) {
        return it->second;
    }
    return nullptr;
}

bool ManejadorUsuarios::existeUsuario(string nickname) {
    return usuarios.find(nickname) != usuarios.end();
}

void ManejadorUsuarios::eliminarUsuario(string nickname) {
    auto it = usuarios.find(nickname);
    if (it != usuarios.end()) {
        delete it->second; // Liberar memoria del usuario
        usuarios.erase(it);
    }
}

ManejadorUsuarios::~ManejadorUsuarios() {
    for (auto& par : usuarios) {
        delete par.second;
    }
    usuarios.clear();
}

void ManejadorUsuarios::destroyInstancia() {
    if (instancia != nullptr) {
        delete instancia;
        instancia = nullptr;
    }
}