#ifndef MENU_H
#define MENU_H
#include "Plato.h"
#include <vector>
#include <iostream>
using namespace std;

class Menu {
private:
    vector<Plato> listaPlatos;

public:
    void agregarPlato(const Plato& p) {
        listaPlatos.push_back(p);
    }

    void mostrarMenu() const {
        for (const auto& plato : listaPlatos) {
            plato.mostrarPlato();
        }
    }

    Plato buscarPlato(const string& nombre) const {
        for (const auto& plato : listaPlatos) {
            if (plato.getNombre() == nombre) return plato;
        }
        throw runtime_error("Plato no encontrado");
    }
};

#endif
