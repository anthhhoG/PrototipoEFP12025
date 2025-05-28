#include "usuario.h"
#include "menu.h"

int main() {
    Usuario usuario;
    int opcion;

    do {
        cout << "\n=== SISTEMA CORPORATIVO ===\n";
        cout << "1. Iniciar sesión\n";
        cout << "2. Registrar nuevo usuario\n";
        cout << "3. Salir\n";
        cout << "> ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "=== Inicio de Sesión ===\n";
                if (autenticarUsuario(usuario)) {
                    cout << "Bienvenido, " << usuario.nombreCompleto << endl;
                    menuPrincipal(usuario);
                } else {
                    cout << "Autenticación fallida.\n";
                }
                break;
            case 2:
                registrarUsuario();
                break;
            case 3:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 3);

    return 0;
}
