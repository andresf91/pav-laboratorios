all: main.o socio.cpp mascota.o consulta.o dtFecha.o
	g++ -o prog main.o socio.cpp mascota.o consulta.o dtFecha.o
main.o: main.cpp
	g++ -c main.cpp
dtFecha.o:dtFecha.h dtFecha.cpp
	g++ -c dtFecha.cpp
consulta.o:consulta.h consulta.cpp
	g++ -c consulta.cpp
mascota.o:mascota.h mascota.cpp
	g++ -c mascota.cpp	
socio.o: socio.h socio.cpp
	g++ -c socio.cpp
clean:
	rm *.o prog
	rm *.exe