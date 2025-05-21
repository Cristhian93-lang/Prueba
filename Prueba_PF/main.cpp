#include "Persona.h"
#include "Empleado.h"
#include "Cliente.h"
#include "Plato.h"
#include "Menu.h"
#include "Pedido.h"
#include "Restaurante.h"
#include <iostream>
using namespace std;

int main() {
    // Crear restaurante
    Restaurante rest("Sabor Local");

    // Mostrar nombre del restaurante
    cout << "Bienvenido a " << rest.getNombre() << "!" << endl;

    // Agregar empleados
    Empleado emp1("Luis", 101, "Chef");
    Empleado emp2("María", 102, "Mesera");
    rest.agregarEmpleado(emp1);
    rest.agregarEmpleado(emp2);

    // Asignar un empleado
    rest.asignarEmpleado();

    // Crear y agregar platos al menú
    Plato p1("Tacos", 80.0, true);
    Plato p2("Enchiladas", 90.0, true);
    Plato p3("Pozole", 100.0, false); // no disponible
    rest.agregarPlatoAlMenu(p1);
    rest.agregarPlatoAlMenu(p2);
    rest.agregarPlatoAlMenu(p3);

    // Mostrar el menú completo
    rest.mostrarMenu();

    // Crear cliente
    Cliente cli("Ana", 202, "ana@mail.com", "555-1234", "1234");

    // Crear pedido y agregar platos disponibles
    Pedido pedido(cli);
    pedido.agregarPlato(p1);
    pedido.agregarPlato(p2);
    rest.tomarPedido(pedido);

    // Generar factura del pedido
    pedido.generarFactura();

    // Hacer una reservación
    rest.realizarReservacion("Ana", 3);

    // Polimorfismo con Persona*
    Persona* personas[] = { &emp1, &cli };
    for (Persona* p : personas) {
        p->realizarTarea();
    }

    return 0;
}