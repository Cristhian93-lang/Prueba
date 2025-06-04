#ifndef PEDIDO_H
#define PEDIDO_H
#define MAX 100
#include "Plato.h"
#include "Cliente.h"
#include <string>
#include <ctime>
using namespace std;

class Pedido {
private:
    Cliente* cliente;
    Plato platosSolicitados[MAX];
    int numPlatos;
    float total;
    string horaEntrega;
    string nombreRestaurante;

public:
    Pedido();
    Pedido(Cliente* cliente, string horaEntrega, string nombreRestaurante);

    void agregarPlato(const Plato& p);
    float calcularTotal() const;
    void generarFactura() const;
    void setHora(string hora);
};

Pedido::Pedido() : cliente(nullptr), numPlatos(0), total(0.0), horaEntrega(""), nombreRestaurante("") {}

Pedido::Pedido(Cliente* cliente, string horaEntrega, string nombreRestaurante)
    : cliente(cliente), horaEntrega(horaEntrega), nombreRestaurante(nombreRestaurante), numPlatos(0), total(0.0f) {}

void Pedido::agregarPlato(const Plato& p) {
    if (numPlatos < MAX) {
        platosSolicitados[numPlatos++] = p;
        total += p.getPrecio();
    }
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
    cout << "Direcci\u00f3n: " << cliente->getDireccion() << endl;
    cout << "Restaurante: " << nombreRestaurante << endl;
    cout << "Hora de entrega: " << horaEntrega << endl;
    cout << "Platos:\n";
    for (int i = 0; i < numPlatos; ++i) {
        cout << "  - " << platosSolicitados[i].getNombre() << ": $" << platosSolicitados[i].getPrecio() << endl;
    }
    cout << "Total a pagar: $" << total << endl;
    cout << "-------------------------------\n\n";
}

#endif
