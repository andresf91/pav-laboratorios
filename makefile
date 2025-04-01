all: main.o socio.o mascota.o consulta.o dtFecha.o dtMascota.o dtPerro.o dtGato.o
    g++ -o prog main.o socio.o mascota.o consulta.o dtFecha.o dtMascota.o dtPerro.o dtGato.o

main.o: main.cpp
    g++ -c main.cpp

dtFecha.o: dtFecha.h dtFecha.cpp
    g++ -c dtFecha.cpp

consulta.o: consulta.h consulta.cpp
    g++ -c consulta.cpp

mascota.o: mascota.h mascota.cpp
    g++ -c mascota.cpp

socio.o: socio.h socio.cpp
    g++ -c socio.cpp

dtMascota.o: dtMascota.h dtMascota.cpp
    g++ -c dtMascota.cpp

dtPerro.o: dtPerro.h dtPerro.cpp
    g++ -c dtPerro.cpp

dtGato.o: dtGato.h dtGato.cpp
    g++ -c dtGato.cpp

mascota.o: mascota.h mascota.cpp
	g++ -c mascota.cpp

perro.o: perro.h perro.cpp
    g++ -c perro.cpp

gato.o: gato.h gato.cpp
    g++ -c gato.cpp

clean:
    rm -f *.o prog
    rm -f *.exe