#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <vector>
#include <string>
#include "usuario.h"
#include "dtComentario.h"
using namespace std;


class Usuario;

class Comentario{
private:
    Usuario* usuario;
    int nroComentario;
    string texto;
    int nroPadre;
    vector<Comentario*> respuestas;
public:
    Comentario(int, string, Usuario*);
    Comentario(int, string, Usuario*, int);
    Usuario* getUsuario();
    DTcomentario getDTcomentario();
    int getNroComentario();
    string getTexto();
    int getNroPadre();
    void agregarRespuesta(Comentario*);
    vector<Comentario*> getRespuestas();
    ~Comentario();
};

#endif