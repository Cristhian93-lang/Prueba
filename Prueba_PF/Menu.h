#ifndef MENU_H
#define MENU_H
#include "Plato.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Menu {
private:
    vector<Plato> listaPlatos;

public:
    void agregarPlato(const Plato& p);
    void mostrarMenu() const;
    Plato buscarPlato(const string& nombre) const;
};

void Menu::agregarPlato(const Plato& p) {
    listaPlatos.push_back(p);
}

void Menu::mostrarMenu() const {
    if (listaPlatos.empty()) {
        cout << "El menú está vacío." << endl;
        return;
    }

    cout << "------ MENÚ ------" << endl;
    for (const auto& plato : listaPlatos) {
        plato.mostrarPlato();
    }
}

Plato Menu::buscarPlato(const string& nombre) const {
    for (const auto& plato : listaPlatos) {
        if (plato.getNombre() == nombre) {
            return plato;
        }
    }
    throw runtime_error("Plato no encontrado.");
}

#endif

