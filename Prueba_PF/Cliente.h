#ifndef CLIENTE_H
#define CLIENTE_H
#include "Persona.h"
#include <string>
using namespace std;

class Cliente : public Persona {
private:
    string correo;
    string telefono;
    string contrasena;
    string direccion;

public:
    Cliente(string nombre, int id, string correo, string telefono, string direccion, string contrasena);
    virtual void mostrarDatos() const;
    virtual void realizarTarea() const;

    string getCorreo() const;
    string getTelefono() const;
    string getContrasena() const;
    string getDireccion() const;
    string getNombre() const;  
};

Cliente::Cliente(string nombre, int id, string correo, string telefono, string direccion, string contrasena)
    : Persona(nombre, id), correo(correo), telefono(telefono), direccion(direccion), contrasena(contrasena) {}

void Cliente::mostrarDatos() const {
    cout << "Cliente: " << nombre << ", ID: " << id << ", Correo: " << correo << ", Teléfono: " << telefono << ", Dirección: " << direccion << endl;
}

void Cliente::realizarTarea() const {
    cout << "Cliente realizando acción..." << endl;
}

string Cliente::getCorreo() const {
    return correo;
}

string Cliente::getTelefono() const {
    return telefono;
}

string Cliente::getContrasena() const {
    return contrasena;
}

string Cliente::getDireccion() const {
    return direccion;
}

string Cliente::getNombre() const {
    return nombre;
}

#endif

