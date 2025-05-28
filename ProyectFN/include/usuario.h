#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Usuario {
    char usuario[30];
    char contrasena[30];
    char nombreCompleto[50];
    char carnet[20];
};

bool autenticarUsuario(Usuario &usuario);
void registrarUsuario();

#endif
