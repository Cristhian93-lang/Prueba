#ifndef PERSONA_H
#define PERSONA_H
#include <string>
using namespace std;

class Persona {
protected:
    string nombre;
    int id;
public:
    Persona(string nombre, int id) : nombre(nombre), id(id) {}
    virtual void mostrarDatos() const = 0;
    virtual void realizarTarea() const = 0;
    virtual ~Persona() {}
};
#endif

