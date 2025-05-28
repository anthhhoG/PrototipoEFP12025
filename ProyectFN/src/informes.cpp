#include <fstream>
#include "habitacion.h"

void generarInforme() {
    Habitacion h;
    ifstream bin("data/habitaciones.dat", ios::binary);
    ofstream txt("data/informe_habitaciones.txt");

    while (bin.read(reinterpret_cast<char*>(&h), sizeof(Habitacion))) {
        txt << "ID: " << h.idHabitacion
            << ", TipoHab: " << h.idTipoHabitacion
            << ", TipoCama: " << h.idTipoCama
            << ", Precio: " << h.precio
            << ", Estatus: " << h.estatus << endl;
    }

    bin.close();
    txt.close();
    cout << "Informe generado correctamente.\n";
}
