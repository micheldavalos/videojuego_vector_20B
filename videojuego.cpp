#include "videojuego.h"
#include <fstream>
#include <algorithm>

Videojuego::Videojuego()
{

}

void Videojuego::agregarPersonaje(const Personaje &p)
{
    personajes.push_back(p);
}

void Videojuego::mostrar()
{
    cout << left;
    cout << setw(10) << "Nombre";
    cout << setw(10) << "Tipo";
    cout << setw(8) << "Fuerza";
    cout << setw(6) << "Salud";
    cout << endl;
    for (size_t i = 0; i < personajes.size(); i++) {
        Personaje &p = personajes[i];
        cout << p;
        // cout << "Nombre: " << p.getNombre() << endl;
        // cout << "Tipo: " << p.getTipo() << endl;
        // cout << "Fuerza: " << p.getFuerza() << endl;
        // cout << "Salud: " << p.getSalud() << endl;
        // cout << endl;
    }
}

void Videojuego::respaldar_tabla()
{
    ofstream archivo("personajes_tabla.txt");
    if (archivo.is_open()) {
        archivo << left;
        archivo << setw(10) << "Nombre";
        archivo << setw(10) << "Tipo";
        archivo << setw(8) << "Fuerza";
        archivo << setw(6) << "Salud";
        archivo << endl;
        for (size_t i = 0; i < personajes.size(); i++) {
            Personaje &p = personajes[i];
            archivo << p;
        }
    }
    archivo.close();
}
void Videojuego::respaldar()
{
    ofstream archivo("personajes.txt");
    if (archivo.is_open()) {
        for (size_t i = 0; i < personajes.size(); i++) {
            Personaje &p = personajes[i];
            archivo << p.getNombre() << endl;
            archivo << p.getTipo() << endl;
            archivo << p.getFuerza() << endl;
            archivo << p.getSalud() << endl;
        }
    }
    archivo.close();
}

void Videojuego::recuperar()
{
    ifstream archivo("personajes.txt");
    if (archivo.is_open()) {
        string temp;
        float fuerza;
        int salud;
        Personaje p;

        while (true)
        {
            getline(archivo, temp); // nombre
            if (archivo.eof()) {
                break;
            }
            p.setNombre(temp);

            getline(archivo, temp); // tipo
            p.setTipo(temp);

            getline(archivo, temp); // fuerza
            fuerza = stof(temp);  // string-to-float
            p.setFuerza(fuerza);

            getline(archivo, temp);
            salud = stoi(temp); // // string-to-int
            p.setSalud(salud);

            agregarPersonaje(p);            
        }
        
    }
    archivo.close();
}

void Videojuego::insertar(const Personaje &p, size_t pos)
{
    personajes.insert(personajes.begin()+pos, p);
}

size_t Videojuego::size()
{
    return personajes.size();
}

void Videojuego::inicializar(const Personaje &p, size_t n)
{
    personajes = vector<Personaje>(n, p);
}

void Videojuego::eliminar(size_t pos)
{
    personajes.erase(personajes.begin()+pos);
}

void Videojuego::ordenar()
{
    sort(personajes.begin(), personajes.end());
}

Personaje* Videojuego::buscar(const Personaje &p)
{
    // vector<Personaje>::iterator
    auto it = find(personajes.begin(), personajes.end(), p);

    if (it == personajes.end()) {
        return nullptr;
    }
    else {
        return &(*it);
    }
}
