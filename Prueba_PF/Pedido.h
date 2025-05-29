#ifndef PEDIDO_H
#define PEDIDO_H

#include "Plato.h"
#include "Cliente.h"
#include <vector>
#include <string>
#include <ctime>
using namespace std;

class Pedido {
private:
    Cliente* cliente;
    vector<Plato> platosSolicitados;
    float total;
    string horaEntrega;
    string nombreRestaurante;

public:
    Pedido(Cliente* cliente, string horaEntrega, string nombreRestaurante);

    void agregarPlato(const Plato& p);
    float calcularTotal() const;
    void generarFactura() const;
    void setHora(string hora);
};

Pedido::Pedido(Cliente* cliente, string horaEntrega, string nombreRestaurante) {
    this->cliente = cliente;
    this->horaEntrega = horaEntrega;
    this->nombreRestaurante = nombreRestaurante;
    total = 0.0f;
}

void Pedido::agregarPlato(const Plato& p) {
    platosSolicitados.push_back(p);
    total += p.getPrecio();
}

float Pedido::calcularTotal() const {
    return total;
}

void Pedido::setHora(string hora) {
    horaEntrega = hora;
}

void Pedido::generarFactura() const {
    cout << "\n\n------ FACTURA DE PEDIDO ------\n";
    cout << "Cliente: " << cliente->getNombre() << endl;
    cout << "Dirección: " << cliente->getDireccion() << endl;
    cout << "Restaurante: " << nombreRestaurante << endl;
    cout << "Hora de entrega: " << horaEntrega << endl;
    cout << "Platos:\n";
    for (const auto& p : platosSolicitados) {
        cout << "  - " << p.getNombre() << ": $" << p.getPrecio() << endl;
    }
    cout << "Total a pagar: $" << total << endl;
    cout << "-------------------------------\n\n";
}

#endif
