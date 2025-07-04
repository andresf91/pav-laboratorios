#ifndef CONTROLADORPUNTAJESYCOMENTARIOS_H
#define CONTROLADORPUNTAJESYCOMENTARIOS_H

#include "IpuntajesYComentarios.h"
#include "manejadorPeliculas.h"
#include "manejadorUsuarios.h"
#include "sesion.h"

class ControladorPuntajesYComentarios: public IpuntajesYComentarios {
private:
   static ControladorPuntajesYComentarios* instancia;
   string titulo;
   int nroComentario;
   bool respuesta; //respuesta a un comentario
   bool puntuada; //si la pelicula fue puntuada
   int puntaje; //puntaje de la pelicula
   ControladorPuntajesYComentarios();
   ~ControladorPuntajesYComentarios();
public:
   void listarPeliculas2();
   void seleccionarPelicula(string titulo);
   void infoPuntajesYComentarios();
   void imprimirComentario(Comentario* c, int nivel);
   void listarPeliculas();
   void listarComentarios();
   void comentarioNuevo(string texto);
   void elegirComentario(int nroComentario);
   void responderComentario(string texto);
   bool continuarRespondiendo();
   bool elegirPeliAPuntuar(string titulo);
   int obtenerPuntaje();
   void actualizarPuntaje(int puntaje);
   void puntuarPelicula(int puntaje);
   string getTitulo();
   int getNroComentario();
   bool getRespuesta();
   bool getPuntuada();
   void setTitulo();
   void setNroComentario();
   void setSetDTPelicula2();
   void setPuntajesYComentarios();
   void setSetTitulos();
   void setSetComentarios();
   void setRespuesta();
   void setPuntuada();
   static ControladorPuntajesYComentarios* getControladorPuntajesYComentarios();
   static void destroyControladorPuntajesYComentarios();
};

#endif