#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include "Menu.h"
#include "Empleado.h"
#include "Pedido.h"
#include <vector>
#include <map>
#include <string>
using namespace std;

class Restaurante {
private:
    string nombre;
    Menu* menu;
    vector<Empleado*> empleados;
    vector<Pedido> pedidos;
    map<string, int> reservaciones;

public:
    Restaurante(string nombre);
    ~Restaurante();

    string getNombre() const;
    void agregarEmpleado(Empleado* e);
    void agregarPlatoAlMenu(const Plato& p);
    void tomarPedido(const Pedido& p);
    void realizarReservacion(string nombreCliente, int cantidad);
    Menu* getMenu() const;
    Empleado* getEmpleado(int index) const;
    int sizeEmpleados() const;
    vector<Empleado*> getEmpleados() const; // ✅ Agregado aquí
};

// Implementaciones

Restaurante::Restaurante(string nombre) : nombre(nombre) {
    menu = new Menu();
}

Restaurante::~Restaurante() {
    delete menu;
    for (Empleado* e : empleados)
        delete e;
}

string Restaurante::getNombre() const {
    return nombre;
}

void Restaurante::agregarEmpleado(Empleado* e) {
    empleados.push_back(e);
}

void Restaurante::agregarPlatoAlMenu(const Plato& p) {
    menu->agregarPlato(p);
}

void Restaurante::tomarPedido(const Pedido& p) {
    pedidos.push_back(p);
}

void Restaurante::realizarReservacion(string nombreCliente, int cantidad) {
    reservaciones[nombreCliente] = cantidad;
}

Menu* Restaurante::getMenu() const {
    return menu;
}

Empleado* Restaurante::getEmpleado(int index) const {
    if (index >= 0 && index < empleados.size())
        return empleados[index];
    return nullptr;
}

int Restaurante::sizeEmpleados() const {
    return empleados.size();
}

vector<Empleado*> Restaurante::getEmpleados() const {
    return empleados;
}

#endif
