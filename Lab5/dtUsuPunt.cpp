#include "dtUsuPunt.h"

// Constructor
DTusuPunt::DTusuPunt(string nickname, int puntaje) {
    this->nickname = nickname;
    this->puntaje = puntaje;
}

string DTusuPunt::getNickname() {
    return nickname;
}

int DTusuPunt::getPuntaje() {
    return puntaje;
}