#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include "personaje.h"
#include <vector>

class Videojuego
{
    vector<Personaje> personajes;

public:
    Videojuego();
    void agregarPersonaje(const Personaje &p);
    void mostrar();
    void respaldar_tabla();
    void respaldar();
    void recuperar();

    void insertar(const Personaje &p, size_t pos);
    size_t size();
    void inicializar(const Personaje &p, size_t n);
    void eliminar(size_t pos);
    void ordenar();
    Personaje* buscar(const Personaje &p);

    friend Videojuego& operator<<(Videojuego &v, const Personaje &p)
    {
        v.agregarPersonaje(p);

        return v;
    }
};

#endif