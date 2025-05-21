#ifndef CLIENTE_H
#define CLIENTE_H
#include "Persona.h"
#include <iostream>
using namespace std;

class Cliente : public Persona {
private:
    string correo;
    string telefono;
    string contrasena;
public:
    Cliente(string nombre, int id, string correo, string telefono, string contrasena)
        : Persona(nombre, id), correo(correo), telefono(telefono), contrasena(contrasena) {}

    void mostrarDatos() const override {
        cout << "Cliente: " << nombre << ", ID: " << id << ", Correo: " << correo << ", Teléfono: " << telefono << endl;
    }

    void realizarTarea() const override {
        cout << "Cliente realizando un pedido o reservación." << endl;
    }

    string getCorreo() const { return correo; }
    string getTelefono() const { return telefono; }
    bool verificarContrasena(string pass) const { return pass == contrasena; }
};

#endif
