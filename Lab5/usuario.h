#ifndef USUARIO_H
#define USUARIO_H

#include "reserva.h"
#include "comentario.h"
#include <vector>
#include <string>
using namespace std;

class Comentario;

class Usuario{
private:
    string nickname;
    string contrasenia;
    string urlFoto;
    vector<Reserva*> reservas;
    vector<Comentario*> comentarios;
public:
    Usuario(string, string);
    Usuario(string, string, string);
    string getNickname();
    string getContrasenia();
    string getUrlFoto();
    void setNickname(string);
    void setContrasenia(string);
    void setUrlFoto(string);
    void agregarReserva(Reserva*);
    void agregarComentario(Comentario*);
    ~Usuario();
};

#endif