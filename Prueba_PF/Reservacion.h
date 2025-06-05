#ifndef RESERVACION_H
#define RESERVACION_H
#include "Cliente.h"
#include "Empleado.h"
#include <string>
#include <iostream>
using namespace std;

class Reservacion {
private:
    Cliente* cliente;
    Empleado* empleado;
    string restaurante;
    int personas;
    int mesa;
    string hora;
    string metodoPago;

public:
    Reservacion(Cliente* cliente, Empleado* empleado, string restaurante, int personas, int mesa, string hora);
    Reservacion(Cliente* cliente, string restaurante, int personas, string hora);

    float calcularCosto() const;
    void setMetodoPago(string metodo);
    void generarFactura() const;
};

Reservacion::Reservacion(Cliente* cliente, Empleado* empleado, string restaurante, int personas, int mesa, string hora)
    : cliente(cliente), empleado(empleado), restaurante(restaurante), personas(personas), mesa(mesa), hora(hora), metodoPago("No especificado") {}

Reservacion::Reservacion(Cliente* cliente, string restaurante, int personas, string hora)
    : cliente(cliente), empleado(nullptr), restaurante(restaurante), personas(personas), mesa(-1), hora(hora), metodoPago("No especificado") {}

float Reservacion::calcularCosto() const {
    return personas * 30.0f;
}

void Reservacion::setMetodoPago(string metodo) {
    metodoPago = metodo;
}

void Reservacion::generarFactura() const {
    cout << "\n--- FACTURA DE RESERVACION ---" << endl;
    cout << "Cliente: " << cliente->getNombre() << endl;
    cout << "Direccion: " << cliente->getDireccion() << endl;
    cout << "Restaurante: " << restaurante << endl;
    cout << "Hora: " << hora << endl;

    cout << "Mesa: ";
    if (mesa >= 0) cout << mesa;
    else cout << "No asignada";
    cout << ", Personas: " << personas << endl;

    if (empleado)
        cout << "Empleado asignado: " << empleado->getNombre() << endl;
    else
        cout << "Empleado asignado: No asignado" << endl;

    cout << "Metodo de pago: " << metodoPago << endl;
    cout << "Costo total: $" << calcularCosto() << endl;
    cout << "-------------------------------\n" << endl;
}

#endif
