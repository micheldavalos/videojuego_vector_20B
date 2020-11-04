#include <iostream>
#include "videojuego.h"
using namespace std;

int main() {
    Videojuego v;
    string op;

    while (true)
    {
        cout << "1) Agregar Personaje" << endl;
        cout << "2) Mostrar" << endl;
        cout << "3) Respaldar" << endl;
        cout << "4) Recuperar" << endl;
        cout << "5) Insertar" << endl;
        cout << "6) Inicializar" << endl;
        cout << "7) Eliminar" << endl;
        cout << "8) Ordenar" << endl;
        cout << "9) Buscar" << endl;
        cout << "0) Salir" << endl;
        getline(cin, op);

        if (op == "1") {
            Personaje p;

            cin >> p;

            v.agregarPersonaje(p); 
            cin.ignore();
        } 
        else if (op == "2") {
            v.mostrar();
        }
        else if (op == "3") {
            v.respaldar();
        }
        else if (op == "4") {
            v.recuperar();
        }
        else if (op == "5") {
            Personaje p;
            cin >> p;

            size_t pos;
            cout << "posición: ";
            cin >> pos; cin.ignore();

            if (pos >= v.size()) {
                cout << "Posición no válida" << endl;
            }
            else {
                v.insertar(p, pos);
            }
        }
        else if (op == "6") {
            Personaje p;
            cin >> p;

            size_t n;
            cout << "n: ";
            cin >> n; cin.ignore();

            v.inicializar(p, n);
        }
        else if (op == "7") {
            size_t pos;
            cout << "posición: ";
            cin >> pos; cin.ignore();

            if (pos >= v.size()) {
                cout << "Posición no válida" << endl;
            }
            else {
                v.eliminar(pos);
            }
        }
        else if (op == "8") {
            v.ordenar();
        }
        else if (op == "9") {
            Personaje p;
            cin >> p; cin.ignore();

            Personaje *ptr = v.buscar(p);

            if (ptr == nullptr) {
                cout << "no encontrado" << endl;
            }
            else {
                cout << *ptr << endl;
            }
        }
        else if (op == "0") {
            break;
        }
    }
    


    return 0;
}