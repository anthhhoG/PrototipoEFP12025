#include "habitacion.h"
#include "seguridad.h"

void altaHabitacion(const char* usuario) {
    Habitacion h;
    cout << "ID Habitacion: "; cin >> h.idHabitacion;
    cout << "ID Tipo Habitacion: "; cin >> h.idTipoHabitacion;
    cout << "ID Tipo Cama: "; cin >> h.idTipoCama;
    cout << "Precio: "; cin >> h.precio;
    h.estatus = 'A';

    ofstream archivo("habitaciones.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<char*>(&h), sizeof(Habitacion));
    archivo.close();

    registrarBitacora(usuario, "Alta", "habitacion");
}

void bajaHabitacion(const char* usuario) {
    char id[15];
    cout << "ID de la habitacion a eliminar: "; cin >> id;
    Habitacion h;
    fstream archivo("habitaciones.dat", ios::in | ios::out | ios::binary);

    while (archivo.read(reinterpret_cast<char*>(&h), sizeof(Habitacion))) {
        if (strcmp(h.idHabitacion, id) == 0) {
            h.estatus = 'I';
            archivo.seekp(-sizeof(Habitacion), ios::cur);
            archivo.write(reinterpret_cast<char*>(&h), sizeof(Habitacion));
            break;
        }
    }
    archivo.close();
    registrarBitacora(usuario, "Baja", "habitacion");
}

void modificarHabitacion(const char* usuario) {
    char id[15];
    cout << "ID de la habitacion a modificar: "; cin >> id;
    Habitacion h;
    fstream archivo("habitaciones.dat", ios::in | ios::out | ios::binary);

    while (archivo.read(reinterpret_cast<char*>(&h), sizeof(Habitacion))) {
        if (strcmp(h.idHabitacion, id) == 0) {
            cout << "Nuevo ID Tipo Habitacion: "; cin >> h.idTipoHabitacion;
            cout << "Nuevo ID Tipo Cama: "; cin >> h.idTipoCama;
            cout << "Nuevo Precio: "; cin >> h.precio;
            archivo.seekp(-sizeof(Habitacion), ios::cur);
            archivo.write(reinterpret_cast<char*>(&h), sizeof(Habitacion));
            break;
        }
    }
    archivo.close();
    registrarBitacora(usuario, "Modificacion", "habitacion");
}

void consultarHabitaciones(const char* usuario) {
    Habitacion h;
    ifstream archivo("habitaciones.dat", ios::binary);
    while (archivo.read(reinterpret_cast<char*>(&h), sizeof(Habitacion))) {
        cout << "ID: " << h.idHabitacion << ", TipoHab: " << h.idTipoHabitacion
             << ", TipoCama: " << h.idTipoCama << ", Precio: " << h.precio
             << ", Estatus: " << h.estatus << endl;
    }
    archivo.close();
    registrarBitacora(usuario, "Consulta", "habitacion");
}
