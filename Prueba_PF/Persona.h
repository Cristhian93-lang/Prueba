#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>
using namespace std;

class Persona {
protected:
    string nombre;
    int id;
    string telefono;
    string direccion;

public:
    Persona(string nombre, int id, string telefono, string direccion);
    virtual ~Persona();

    virtual void mostrarDatos() const = 0;
    virtual void realizarTarea() const = 0;

    string getNombre() const;
    string getTelefono() const;
    string getDireccion() const;

    void mostrarNombre() const;
};

Persona::Persona(string nombre, int id, string telefono, string direccion)
    : nombre(nombre), id(id), telefono(telefono), direccion(direccion) {}

Persona::~Persona() {}

string Persona::getNombre() const {
    return nombre;
}

string Persona::getTelefono() const {
    return telefono;
}

string Persona::getDireccion() const {
    return direccion;
}

void Persona::mostrarNombre() const {
    cout << "Nombre: " << nombre << endl;
}

#endif
