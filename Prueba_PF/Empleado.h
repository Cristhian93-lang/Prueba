#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Persona.h"
#include <string>
#include <iostream>
using namespace std;

class Empleado : public Persona {
private:
    string rol;

public:
    Empleado(string nombre, int id, string rol);
    virtual void mostrarDatos() const;
    virtual void realizarTarea() const;
    string getRol() const;
    string getNombre() const;
};

Empleado::Empleado(string nombre, int id, string rol) : Persona(nombre, id), rol(rol) {}

void Empleado::mostrarDatos() const {
    cout << "Empleado: " << nombre << ", ID: " << id << ", Rol: " << rol << endl;
}

void Empleado::realizarTarea() const {
    cout << "Empleado en función: " << rol << endl;
}

string Empleado::getRol() const {
    return rol;
}

string Empleado::getNombre() const {
    return nombre;
}

#endif
