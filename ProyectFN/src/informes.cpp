#include <fstream>
#include <iostream>
#include "habitacion.h"
using namespace std;

void generarInforme() {
    Habitacion h;
    ifstream bin("habitaciones.dat", ios::binary);
    if (!bin) {
        cerr << "No se pudo abrir el archivo habitaciones.dat.\n";
        return;
    }

    ofstream txt("informe_habitaciones.txt");
    if (!txt) {
        cerr << "No se pudo crear el archivo de informe.\n";
        return;
    }

    int contador = 0;
    while (bin.read(reinterpret_cast<char*>(&h), sizeof(Habitacion))) {
        txt << "ID: " << h.idHabitacion
            << ", TipoHab: " << h.idTipoHabitacion
            << ", TipoCama: " << h.idTipoCama
            << ", Precio: " << h.precio
            << ", Estatus: " << h.estatus << endl;
        contador++;
    }

    bin.close();
    txt.close();

    if (contador > 0)
        cout << "Informe generado correctamente con " << contador << " habitaciones.\n";
    else
        cout << "No se encontraron habitaciones registradas para el informe.\n";
}
