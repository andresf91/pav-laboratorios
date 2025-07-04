#ifndef DTFECHA_H
#define DTFECHA_H

class DTfecha{
private:
    int dia;
    int mes;
    int anio;
public:
    DTfecha(int, int, int);
    int getDia();
    int getMes();
    int getAnio();
};

#endif