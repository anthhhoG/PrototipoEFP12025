#include "usuario.h"
#include <filesystem> // Requiere C++17

using namespace std;

bool autenticarUsuario(Usuario &usuarioLogueado) {
    Usuario usuarioArchivo;
    char usuarioInput[30], contrasenaInput[30];
    bool autenticado = false;

    cout << "Usuario: ";
    cin >> usuarioInput;
    cout << "Contrasena: ";
    cin >> contrasenaInput;

    ifstream archivo("usuarios.dat", ios::binary);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo de usuarios.\n";
        return false;
    }

    while (archivo.read(reinterpret_cast<char*>(&usuarioArchivo), sizeof(Usuario))) {
        if (strcmp(usuarioArchivo.usuario, usuarioInput) == 0 &&
            strcmp(usuarioArchivo.contrasena, contrasenaInput) == 0) {
            usuarioLogueado = usuarioArchivo;
            autenticado = true;
            break;
        }
    }
    archivo.close();
    return autenticado;
}

void registrarUsuario() {


    Usuario nuevo;
    cout << "=== Registro de Usuario ===\n";

    cin.ignore(); // Limpiar búfer antes de getline
    cout << "Nombre completo: ";
    cin.getline(nuevo.nombreCompleto, 50);

    cout << "Carnet: ";
    cin.getline(nuevo.carnet, 20);

    cout << "Usuario (nombre corto): ";
    cin.getline(nuevo.usuario, 30);

    cout << "Contrasena: ";
    cin.getline(nuevo.contrasena, 30);

    ofstream archivo("usuarios.dat", ios::binary | ios::app);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo para guardar usuario.\n";
        return;
    }

    archivo.write(reinterpret_cast<char*>(&nuevo), sizeof(Usuario));
    archivo.close();

    cout << "Usuario registrado exitosamente.\n";
}
