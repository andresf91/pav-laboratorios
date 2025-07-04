#ifndef MANEJADORFINANCIERAS_H
#define MANEJADORFINANCIERAS_H

#include "financiera.h"
#include <map>

class ManejadorFinancieras {
private:
    static ManejadorFinancieras* instancia;
    map<string, Financiera*> financieras;
    ManejadorFinancieras();
    ~ManejadorFinancieras();
public:
    static ManejadorFinancieras* getInstancia();
    static void destroyInstancia();
    void agregarFinanciera(Financiera* financiera);
    Financiera* obtenerFinanciera(string nickname);
    bool existeFinanciera(string nickname);
    void eliminarFinanciera(string nickname);
};

#endif // MANEJADORUSUARIOS_H