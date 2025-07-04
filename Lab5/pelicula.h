#ifndef PELICULA_H
#define PELICULA_H

#include "comentario.h"
#include "dtPelicula.h"
#include "puntaje.h"
#include <vector>
#include <string>
using namespace std;

class Pelicula{
private:
    int cantComentarios = 0;
    string titulo;
    string posterUrl;
    string sinopsis;
    float puntajePromedio;
    vector<Puntaje*> puntajes;
    vector<Comentario*> comentarios;
public:
    Pelicula(string, string);
    Pelicula(string, string, string);
    DTpelicula getDTpelicula();
    vector<Comentario*> getComentarios();
    vector<Puntaje*> getPuntajes();
    string getTitulo();
    string getUrl();
    string getSinopsis();
    float getPuntajePromedio();
    void setPosterUrl(string);
    void setSinopsis(string);
    void setPuntajePromedio(float);
    void agregarPuntaje(Puntaje*);
    void agregarComentario(Comentario*);
    ~Pelicula();
};

#endif