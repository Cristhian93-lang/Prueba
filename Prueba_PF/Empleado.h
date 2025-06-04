#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Persona.h"

class Empleado : public Persona {
private:
    string rol;

public:
    Empleado(string nombre, int id, string telefono, string direccion, string rol);
    void mostrarDatos() const;
    void realizarTarea() const;
    string getRol() const;
};

Empleado::Empleado(string nombre, int id, string telefono, string direccion, string rol)
    : Persona(nombre, id, telefono, direccion), rol(rol) {}

void Empleado::mostrarDatos() const {
    cout << "Empleado: " << nombre << ", ID: " << id << ", Tel: " << telefono
         << ", Direccion: " << direccion << ", Rol: " << rol << endl;
}

void Empleado::realizarTarea() const {
    cout << "Empleado en funcion: " << rol << endl;
}

string Empleado::getRol() const {
    return rol;
}

#endif
