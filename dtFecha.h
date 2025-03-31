#ifndef DTFECHA_H
#define DTFECHA_H

class Fecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
        Fecha(int, int, int);
        int getDia();
        int getMes();
        int getAnio(); 
        void imprimirFecha();
        //bool esPrevia (Fecha* fecha1, Fecha* fecha2);
        ~Fecha();
};

#endif