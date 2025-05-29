#ifndef PLATO_H
#define PLATO_H
#include <string>
#include <iostream>
using namespace std;

class Plato {
private:
    string nombre;
    float precio;
    bool disponible;

public:
    Plato(string nombre, float precio, bool disponible);
    string getNombre() const;
    float getPrecio() const;
    bool estaDisponible() const;
    void mostrarPlato() const;
};

Plato::Plato(string nombre, float precio, bool disponible)
    : nombre(nombre), precio(precio), disponible(disponible) {}

string Plato::getNombre() const {
    return nombre;
}

float Plato::getPrecio() const {
    return precio;
}

bool Plato::estaDisponible() const {
    return disponible;
}

void Plato::mostrarPlato() const {
    cout << nombre << " - $" << precio;
    if (disponible) {
        cout << " (Disponible)" << endl;
    } else {
        cout << " (No disponible)" << endl;
    }
}

#endif

