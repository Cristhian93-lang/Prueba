#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#define MAX 100

#include "Plato.h"
#include "Empleado.h"
#include "Pedido.h"
#include <string>
#include <iostream>
using namespace std;

class Restaurante {
private:
    string nombre;
    Plato platos[MAX];
    int numPlatos;
    Empleado* empleados[MAX];
    int numEmpleados;
    Pedido pedidos[MAX];
    int numPedidos;

public:
    Restaurante(string nombre);

    string getNombre() const;
    void agregarEmpleado(Empleado* e);
    Empleado* getEmpleado(int index) const;
    int sizeEmpleados() const;
    Empleado** getEmpleados();

    void agregarPlato(const Plato& p);
    void mostrarMenu() const;
    const Plato* getPlatos() const;
    int sizePlatos() const;

    void tomarPedido(const Pedido& p);
};

Restaurante::Restaurante(string nombre)
    : nombre(nombre), numPlatos(0), numEmpleados(0), numPedidos(0) {}

string Restaurante::getNombre() const {
    return nombre;
}

void Restaurante::agregarEmpleado(Empleado* e) {
    if (numEmpleados < MAX) {
        empleados[numEmpleados++] = e;
    }
}

Empleado* Restaurante::getEmpleado(int index) const {
    if (index >= 0 && index < numEmpleados)
        return empleados[index];
    return nullptr;
}

int Restaurante::sizeEmpleados() const {
    return numEmpleados;
}

Empleado** Restaurante::getEmpleados() {
    return empleados;
}

void Restaurante::agregarPlato(const Plato& p) {
    if (numPlatos < MAX) {
        platos[numPlatos++] = p;
    }
}

void Restaurante::mostrarMenu() const {
    if (numPlatos == 0) {
        cout << "El menu esta vacio." << endl;
        return;
    }

    cout << "------ MENU ------" << endl;
    for (int i = 0; i < numPlatos; ++i) {
        cout << i + 1 << ". ";
        platos[i].mostrarPlato();
    }
}

const Plato* Restaurante::getPlatos() const {
    return platos;
}

int Restaurante::sizePlatos() const {
    return numPlatos;
}

void Restaurante::tomarPedido(const Pedido& p) {
    if (numPedidos < MAX) {
        pedidos[numPedidos++] = p;
    }
}

#endif
