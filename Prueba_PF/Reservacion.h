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
    float costo;

public:
    Reservacion(Cliente* cliente, Empleado* empleado, string restaurante, int personas, int mesa, string hora);

    float calcularCosto() const;
    void generarFactura() const;
};

Reservacion::Reservacion(Cliente* cliente, Empleado* empleado, string restaurante, int personas, int mesa, string hora) {
    this->cliente = cliente;
    this->empleado = empleado;
    this->restaurante = restaurante;
    this->personas = personas;
    this->mesa = mesa;
    this->hora = hora;
    this->costo = calcularCosto();
}

float Reservacion::calcularCosto() const {
    return personas * 30.0f; 
}

void Reservacion::generarFactura() const {
    cout << "\n--- FACTURA DE RESERVACIÓN ---" << endl;
    cout << "Cliente: " << cliente->getNombre() << endl;
    cout << "Dirección: " << cliente->getDireccion() << endl;
    cout << "Restaurante: " << restaurante << endl;
    cout << "Hora: " << hora << endl;
    cout << "Mesa: " << mesa << ", Personas: " << personas << endl;
    cout << "Empleado asignado: " << empleado->getNombre() << endl;
    cout << "Costo total: $" << costo << endl;
    cout << "-------------------------------\n" << endl;
}

#endif

