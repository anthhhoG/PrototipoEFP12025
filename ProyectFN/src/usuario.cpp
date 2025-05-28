#include "usuario.h"

bool autenticarUsuario(Usuario &usuarioLogueado) {
    Usuario usuarioArchivo;
    char usuarioInput[30], contrasenaInput[30];
    bool autenticado = false;

    cout << "Usuario: ";
    cin >> usuarioInput;
    cout << "Contrasena: ";
    cin >> contrasenaInput;

    ifstream archivo("data/usuarios.dat", ios::binary);
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
