#ifndef MANEJADORUSUARIOS_H
#define MANEJADORUSUARIOS_H

#include "usuario.h"
#include <map>

class ManejadorUsuarios {
private:
    static ManejadorUsuarios* instancia;
    map<string, Usuario*> usuarios;
    ManejadorUsuarios();
    ~ManejadorUsuarios();
public:
    static ManejadorUsuarios* getInstancia();
    static void destroyInstancia();
    void agregarUsuario(Usuario* usuario);
    Usuario* obtenerUsuario(string nickname);
    bool existeUsuario(string nickname);
    void eliminarUsuario(string nickname);
};

#endif // MANEJADORUSUARIOS_H