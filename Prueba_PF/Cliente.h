#ifndef CLIENTE_H
#define CLIENTE_H
#include "Persona.h"

class Cliente : public Persona {
private:
    string correo;
    string contrasena;

public:
    Cliente(string nombre, int id, string correo, string telefono, string direccion, string contrasena);
    void mostrarDatos() const;
    void realizarTarea() const;

    string getCorreo() const;
    string getContrasena() const;
};

Cliente::Cliente(string nombre, int id, string correo, string telefono, string direccion, string contrasena)
    : Persona(nombre, id, telefono, direccion), correo(correo), contrasena(contrasena) {}

void Cliente::mostrarDatos() const {
    cout << "Cliente: " << nombre << ", ID: " << id << ", Correo: " << correo
         << ", Tel: " << telefono << ", Direccion: " << direccion << endl;
}

void Cliente::realizarTarea() const {
    cout << "Cliente realizando accion..." << endl;
}

string Cliente::getCorreo() const {
    return correo;
}

string Cliente::getContrasena() const {
    return contrasena;
}

#endif

