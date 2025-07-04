#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H

#include <string>
using namespace std;

class DTcomentario{
private:
    int nroComentario;
    string contenido;
public:
    DTcomentario(int, string);
    int getNroComentario();
    string getContenido();
};

#endif