#ifndef RESTAURANTE_H
#define RESTAURANTE_H
#include "Menu.h"
#include "Empleado.h"
#include "Pedido.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

class Restaurante {
private:
    string nombre;
    Menu menu;
    vector<Empleado> empleados;
    vector<Pedido> pedidos;
    map<string, int> reservaciones;

public:
    Restaurante(string nombre) : nombre(nombre) {}
    string getNombre() const {
        return nombre;
    }

    void agregarEmpleado(const Empleado& e) {
        empleados.push_back(e);
    }

    void asignarEmpleado() const {
        if (!empleados.empty()) {
            cout << "Empleado asignado: ";
            empleados.front().mostrarDatos();
        } else {
            cout << "No hay empleados disponibles para asignar." << endl;
        }
    }

    void agregarPlatoAlMenu(const Plato& p) {
        menu.agregarPlato(p);
    }

    void tomarPedido(const Pedido& p) {
        pedidos.push_back(p);
    }

    void mostrarMenu() const {
        cout << "\nMenú de " << nombre << ":\n";
        menu.mostrarMenu();
    }

    void realizarReservacion(string nombreCliente, int cantidad) {
        reservaciones[nombreCliente] = cantidad;
        cout << "Reservación registrada para " << nombreCliente
             << " (" << cantidad << " personas)\n";
    }
};

#endif
