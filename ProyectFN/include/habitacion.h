#ifndef HABITACION_H
#define HABITACION_H

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Habitacion {
    char idHabitacion[15];
    char idTipoHabitacion[15];
    char idTipoCama[15];
    float precio;
    char estatus;
};

void altaHabitacion(const char* usuario);
void bajaHabitacion(const char* usuario);
void modificarHabitacion(const char* usuario);
void consultarHabitaciones(const char* usuario);

#endif
