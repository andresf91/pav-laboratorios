#ifndef DTFECHA_H
#define DTFECHA_H

class dtFecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
        dtFecha(int, int, int);
        dtFecha(dtFecha*);
        dtFecha(dtFecha&);
        dtFecha(const dtFecha&); // Constructor por copia con const
        int getDia();
        int getMes();
        int getAnio(); 
        void imprimirFecha();
        //bool esPrevia (Fecha* fecha1, Fecha* fecha2);
        ~dtFecha();
};

#endif