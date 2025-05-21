#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Persona.h"
#include <iostream>
using namespace std;

class Empleado : public Persona {
private:
    string rol;
public:
    Empleado(string nombre, int id, string rol) : Persona(nombre, id), rol(rol) {}

    void mostrarDatos() const override {
        cout << "Empleado: " << nombre << ", ID: " << id << ", Rol: " << rol << endl;
    }

    void realizarTarea() const override {
        cout << "Empleado desempeñando su rol: " << rol << endl;
    }
};
#endif

