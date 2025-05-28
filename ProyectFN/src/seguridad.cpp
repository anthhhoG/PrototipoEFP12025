#include "seguridad.h"

void registrarBitacora(const char* usuario, const char* accion, const char* aplicacion) {
    Bitacora b;
    strncpy(b.nombreUsuario, usuario, 30);
    strncpy(b.accion, accion, 30);
    strncpy(b.aplicacion, aplicacion, 30);

    time_t now = time(0);
    strftime(b.fechaHora, 20, "%Y-%m-%d %H:%M", localtime(&now));

    ofstream archivo("bitacora.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<char*>(&b), sizeof(Bitacora));
    archivo.close();
}

void consultarBitacora() {
    Bitacora b;
    ifstream archivo("bitacora.dat", ios::binary);
    while (archivo.read(reinterpret_cast<char*>(&b), sizeof(Bitacora))) {
        cout << b.fechaHora << " | " << b.nombreUsuario << " | " << b.accion << " | " << b.aplicacion << endl;
    }
    archivo.close();
}
