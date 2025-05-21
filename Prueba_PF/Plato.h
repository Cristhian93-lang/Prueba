#ifndef PLATO_H
#define PLATO_H
#include <iostream>
#include <string>
using namespace std;

class Plato {
private:
    string nombre;
    float precio;
    bool disponible;

public:
    Plato(string nombre, float precio, bool disponible)
        : nombre(nombre), precio(precio), disponible(disponible) {}

    string getNombre() const { return nombre; }
    float getPrecio() const { return precio; }
    bool estaDisponible() const { return disponible; }

    void mostrarPlato() const {
        cout << nombre << " - $" << precio << (disponible ? " (Disponible)" : " (No disponible)") << endl;
    }
};

#endif
