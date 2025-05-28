#ifndef SEGURIDAD_H
#define SEGURIDAD_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
using namespace std;

struct Bitacora {
    char nombreUsuario[30];
    char accion[30];
    char aplicacion[30];
    char fechaHora[20];
};

void registrarBitacora(const char* usuario, const char* accion, const char* aplicacion);
void consultarBitacora();

#endif
