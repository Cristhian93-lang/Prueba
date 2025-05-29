#ifndef PERSONA_H
#define PERSONA_H

#include <string>
using namespace std;

class Persona {
protected:
    string nombre;
    int id;

public:
    Persona(string nombre, int id);
    virtual void mostrarDatos() const = 0;
    virtual void realizarTarea() const = 0;
    virtual ~Persona();
};

Persona::Persona(string nombre, int id) {
    this->nombre = nombre;
    this->id = id;
}

Persona::~Persona() {}

#endif

