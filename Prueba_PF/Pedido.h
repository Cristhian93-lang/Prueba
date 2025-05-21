#ifndef PEDIDO_H
#define PEDIDO_H
#include "Plato.h"
#include "Cliente.h"
#include <vector>
#include <iostream>
using namespace std;

class Pedido {
private:
    Cliente cliente;
    vector<Plato> platosSolicitados;
    float total;  

public:
    Pedido(Cliente cliente) : cliente(cliente), total(0.0f) {}  

    void agregarPlato(const Plato& p) {
        platosSolicitados.push_back(p);
        total += p.getPrecio();  
    }

    float calcularTotal() const {
        return total;  
    }

    void generarFactura() const {
        cout << "\nFactura para: ";
        cliente.mostrarDatos();
        for (const auto& p : platosSolicitados) {
            p.mostrarPlato();
        }
        cout << "Total: $" << total << endl;
    }
};

#endif

