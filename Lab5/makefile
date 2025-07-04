all: cine.o sala.o comentario.o controladorAltas.o controladorReservas.o controladorSesion.o credito.o debito.o dtCine.o dtComentario.o dtFecha.o dtFinanciera.o dtFuncion.o dtFuncion2.o dtFuncionConReservas.o dtPelicula.o dtPelicula2.o dtPuntajesYComentarios.o dtReserva.o dtSalaConFunciones.o dtTiempo.o dtUsuComent.o dtUsuPunt.o fabricaControladores.o financiera.o funcion.o manejadorCines.o manejadorFinancieras.o manejadorPeliculas.o manejadorUsuarios.o pelicula.o puntaje.o reserva.o sesion.o usuario.o main.o
	g++ -g -o prog cine.o sala.o comentario.o controladorAltas.o controladorReservas.o controladorSesion.o credito.o debito.o dtCine.o dtComentario.o dtFecha.o dtFinanciera.o dtFuncion.o dtFuncion2.o dtFuncionConReservas.o dtPelicula.o dtPelicula2.o dtPuntajesYComentarios.o dtReserva.o dtSalaConFunciones.o dtTiempo.o dtUsuComent.o dtUsuPunt.o fabricaControladores.o financiera.o funcion.o manejadorCines.o manejadorFinancieras.o manejadorPeliculas.o manejadorUsuarios.o pelicula.o puntaje.o reserva.o sesion.o usuario.o main.o

cine.o: cine.cpp cine.h pelicula.h sala.h dtCine.h
	g++ -g -c cine.cpp

sala.o: sala.cpp sala.h funcion.h dtSalaConFunciones.h dtFuncion2.h
	g++ -g -c sala.cpp

comentario.o: comentario.cpp comentario.h
	g++ -g -c comentario.cpp

controladorPuntajesYComentarios.o: controladorPuntajesYComentarios.cpp controladorPuntajesYComentarios.h IpuntajesYComentarios.h
	g++ -g -c controladorPuntajesYComentarios.cpp

controladorAltas.o: controladorAltas.cpp controladorAltas.h Ialtas.h cine.h funcion.h dtCine.h manejadorCines.h manejadorPeliculas.h manejadorUsuarios.h
	g++ -g -c controladorAltas.cpp

controladorReservas.o: controladorReservas.cpp controladorReservas.h Ireservas.h dtFuncion.o dtFuncion2.h dtFecha.o dtTiempo.o tipoPago.h funcion.h dtPelicula.h manejadorPeliculas.h manejadorFinancieras.h manejadorUsuarios.h manejadorCines.h sesion.h credito.h debito.h
	g++ -g -c controladorReservas.cpp

controladorSesion.o: controladorSesion.cpp controladorSesion.h Isesion.h usuario.h manejadorUsuarios.h sesion.h
	g++ -g -c controladorSesion.cpp

credito.o: credito.cpp credito.h reserva.h
	g++ -g -c credito.cpp

debito.o: debito.cpp debito.h reserva.h
	g++ -g -c debito.cpp

dtCine.o: dtCine.cpp dtCine.h
	g++ -g -c dtCine.cpp

dtComentario.o: dtComentario.cpp dtComentario.h
	g++ -g -c dtComentario.cpp

dtFecha.o: dtFecha.cpp dtFecha.h
	g++ -g -c dtFecha.cpp

dtFinanciera.o: dtFinanciera.cpp dtFinanciera.h
	g++ -g -c dtFinanciera.cpp

dtFuncion.o: dtFuncion.cpp dtFuncion.h dtFecha.h dtTiempo.h
	g++ -g -c dtFuncion.cpp

dtFuncion2.o: dtFuncion2.cpp dtFuncion2.h dtFuncion.h dtFecha.h dtTiempo.h
	g++ -g -c dtFuncion2.cpp

dtFuncionConReservas.o: dtFuncionConReservas.cpp dtFuncionConReservas.h dtFuncion.h dtReserva.h
	g++ -g -c dtFuncionConReservas.cpp

dtPelicula.o: dtPelicula.cpp dtPelicula.h
	g++ -g -c dtPelicula.cpp

dtPelicula2.o: dtPelicula2.cpp dtPelicula2.h
	g++ -g -c dtPelicula2.cpp

dtPuntajesYComentarios.o: dtPuntajesYComentarios.cpp dtPuntajesYComentarios.h
	g++ -g -c dtPuntajesYComentarios.cpp

dtReserva.o: dtReserva.cpp dtReserva.h tipoPago.h
	g++ -g -c dtReserva.cpp

dtSalaConFunciones.o: dtSalaConFunciones.cpp dtSalaConFunciones.h dtFuncion.h
	g++ -g -c dtSalaConFunciones.cpp

dtTiempo.o: dtTiempo.cpp dtTiempo.h
	g++ -g -c dtTiempo.cpp

dtUsuComent.o: dtUsuComent.cpp dtUsuComent.h
	g++ -g -c dtUsuComent.cpp

dtUsuPunt.o: dtUsuPunt.cpp dtUsuPunt.h
	g++ -g -c dtUsuPunt.cpp

fabricaControladores.o: fabricaControladores.h fabricaControladores.cpp Ialtas.h IpuntajesYComentarios.h Ireservas.h Isesion.h controladorAltas.h controladorReservas.h controladorSesion.h
	g++ -g -c fabricaControladores.cpp

financiera.o: financiera.h financiera.cpp dtFinanciera.h
	g++ -g -c financiera.cpp

funcion.o: funcion.cpp funcion.h dtFecha.h dtTiempo.h dtFuncion.h dtFuncion2.h pelicula.h
	g++ -g -c funcion.cpp

manejadorCines.o: manejadorCines.cpp manejadorCines.h cine.h
	g++ -g -c manejadorCines.cpp

manejadorFinancieras.o: manejadorFinancieras.cpp manejadorFinancieras.h financiera.h
	g++ -g -c manejadorFinancieras.cpp

manejadorPeliculas.o: manejadorPeliculas.cpp manejadorPeliculas.h pelicula.h
	g++ -g -c manejadorPeliculas.cpp

manejadorUsuarios.o: manejadorUsuarios.cpp manejadorUsuarios.h usuario.h
	g++ -g -c manejadorUsuarios.cpp

pelicula.o: pelicula.cpp pelicula.h comentario.h puntaje.h dtPelicula.h
	g++ -g -c pelicula.cpp

puntaje.o: puntaje.cpp puntaje.h usuario.h
	g++ -g -c puntaje.cpp

reserva.o: reserva.cpp reserva.h usuario.h funcion.h dtReserva.h
	g++ -g -c reserva.cpp

sesion.o: sesion.cpp sesion.h
	g++ -g -c sesion.cpp

usuario.o: usuario.cpp usuario.h reserva.h comentario.h
	g++ -g -c usuario.cpp

main.o: main.cpp
	g++ -g -c main.cpp

clean:
	rm -f *.o prog