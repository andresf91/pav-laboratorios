#ifndef SESION_H
#define SESION_H

#include <string>
using namespace std;

class Sesion{
private:
    static Sesion* instancia;
    string nickname = "";
    Sesion();
    ~Sesion();
public:
    string getNickname();
    void setNickname(string);
    static Sesion* getInstancia();
    static void destroyInstancia();
};

#endif