#include "menu.h"
#include "habitacion.h"
#include "informes.h"
#include "seguridad.h"

void menuCatalogos(const char* usuario) {
    int opcion;
    do {
        cout << "\n--- CATALOGOS ---\n";
        cout << "1. Añadir Habitacion\n2. Eliminar Habitacion\n3. Modificar info\n4. Consultar\n5. Volver\n> ";
        cin >> opcion;
        switch (opcion) {
            case 1: altaHabitacion(usuario); break;
            case 2: bajaHabitacion(usuario); break;
            case 3: modificarHabitacion(usuario); break;
            case 4: consultarHabitaciones(usuario); break;
        }
    } while (opcion != 5);
}

void menuPrincipal(const Usuario& usuario) {
    int opcion;
    do {
        cout << "\n=== SISTEMA CORPORATIVO ===\n";
        cout << "Usuario: " << usuario.nombreCompleto << " | Carné: " << usuario.carnet << endl;
        cout << "1. Catálogos\n2. Informes\n3. Seguridad\n4. Salir\n> ";
        cin >> opcion;
        switch (opcion) {
            case 1: menuCatalogos(usuario.usuario); break;
            case 2: generarInforme(); break;
            case 3: consultarBitacora(); break;
        }
    } while (opcion != 4);
}
