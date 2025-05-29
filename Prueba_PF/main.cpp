#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <limits>
#include "Cliente.h"
#include "Empleado.h"
#include "Restaurante.h"
#include "Pedido.h"
#include "Reservacion.h"

using namespace std;

string obtenerHoraActual() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[6];
    sprintf(buffer, "%02d:%02d", ltm->tm_hour, ltm->tm_min);
    return string(buffer);
}

int main() {
    string nombre, correo, telefono, direccion, contrasena;

    cout << "=== Registro de Cliente ===" << endl;
    cout << "Nombre: "; getline(cin, nombre);
    cout << "Correo: "; getline(cin, correo);
    cout << "Telefono: "; getline(cin, telefono);
    cout << "Direccion: "; getline(cin, direccion);
    cout << "Contrasena: "; getline(cin, contrasena);

    Cliente* clienteRegistrado = new Cliente(nombre, 1, correo, telefono, direccion, contrasena);

    vector<Restaurante*> restaurantes = {
        new Restaurante("Little Caesars"),
        new Restaurante("SushiDojo"),
        new Restaurante("McDonald's"),
        new Restaurante("Los Gusanos de Don Chucho Taco"),
        new Restaurante("KFC")
    };

    restaurantes[0]->agregarPlatoAlMenu(Plato("Pizza Pepperoni", 100.0, true));
    restaurantes[0]->agregarPlatoAlMenu(Plato("Pizza Hawaiana", 90.0, true));
    restaurantes[0]->agregarPlatoAlMenu(Plato("Super Cheese Pepperoni", 199.0, true));
    restaurantes[0]->agregarPlatoAlMenu(Plato("Piñaronni Bacon Duo", 179.0, true));
    restaurantes[0]->agregarPlatoAlMenu(Plato("Combo Crazy Puffs", 204.0, true));

    restaurantes[1]->agregarPlatoAlMenu(Plato("Sushi Roll", 120.0, true));
    restaurantes[1]->agregarPlatoAlMenu(Plato("Nigiri", 80.0, true));
    restaurantes[1]->agregarPlatoAlMenu(Plato("Crunchy Camaron", 95.0, true));
    restaurantes[1]->agregarPlatoAlMenu(Plato("Yakimeshi Mixto", 125.0, true));
    restaurantes[1]->agregarPlatoAlMenu(Plato("Crunchy Cangrejo", 83.0, true));

    restaurantes[2]->agregarPlatoAlMenu(Plato("Cheeseburger", 110.0, true));
    restaurantes[2]->agregarPlatoAlMenu(Plato("Papas Fritas", 40.0, true));
    restaurantes[2]->agregarPlatoAlMenu(Plato("Home Office Big Mac", 99.0, true));
    restaurantes[2]->agregarPlatoAlMenu(Plato("Mc Trio Mediano McPollo", 89.0, true));
    restaurantes[2]->agregarPlatoAlMenu(Plato("Malteada Vainilla", 59.0, true));

    restaurantes[3]->agregarPlatoAlMenu(Plato("Taco Al Pastor x3", 35.0, true));
    restaurantes[3]->agregarPlatoAlMenu(Plato("Quesadilla", 45.0, true));
    restaurantes[3]->agregarPlatoAlMenu(Plato("QuesaBirria", 50.0, true));
    restaurantes[3]->agregarPlatoAlMenu(Plato("Taco Suadero", 20.0, true));
    restaurantes[3]->agregarPlatoAlMenu(Plato("Agua Sabor Orchata", 55.0, true));

    restaurantes[4]->agregarPlatoAlMenu(Plato("Buket Clasico 6 piesas", 269.0, true));
    restaurantes[4]->agregarPlatoAlMenu(Plato("MegaCombo Big Krunch", 208.0, true));
    restaurantes[4]->agregarPlatoAlMenu(Plato("Hot Cheese Fries", 125.0, true));
    restaurantes[4]->agregarPlatoAlMenu(Plato("Ke Tiras Lovers 9", 359.0, true));
    restaurantes[4]->agregarPlatoAlMenu(Plato("Coca Cola Lata", 29.0, true));

    for (auto& rest : restaurantes) {
        rest->agregarEmpleado(new Empleado("Juan - " + rest->getNombre(), 10, "Mesero"));
        rest->agregarEmpleado(new Empleado("Ana - " + rest->getNombre(), 11, "Mesero"));
        rest->agregarEmpleado(new Empleado("Mary - " + rest->getNombre(), 12, "Cocinera"));
        rest->agregarEmpleado(new Empleado("Diego - " + rest->getNombre(), 13, "Cocinera"));
    }

    int opcion;
    do {
        cout << "\n=== Menú Principal ===" << endl;
        cout << "1. Pedidos" << endl;
        cout << "2. Reservaciones" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            cout << "\nSeleccione un restaurante:" << endl;
            for (size_t i = 0; i < restaurantes.size(); ++i)
                cout << i+1 << ". " << restaurantes[i]->getNombre() << endl;

            int idxRest;
            cout << "Opción: "; cin >> idxRest; cin.ignore();

            if (idxRest < 1 || idxRest > restaurantes.size()) continue;
            Restaurante* rest = restaurantes[idxRest-1];

            Pedido pedido(clienteRegistrado, obtenerHoraActual(), rest->getNombre());

            string nombrePlato;
            char continuar = 's';
            while (continuar == 's') {
                rest->getMenu()->mostrarMenu();
                cout << "Nombre del plato: "; getline(cin, nombrePlato);
                Plato p = rest->getMenu()->buscarPlato(nombrePlato);
                pedido.agregarPlato(p);
                cout << "¿Desea agregar otro plato? (s/n): "; cin >> continuar; cin.ignore();
            }

            pedido.generarFactura();
        }
        else if (opcion == 2) {
            cout << "\nSeleccione un restaurante:" << endl;
            for (size_t i = 0; i < restaurantes.size(); ++i)
                cout << i+1 << ". " << restaurantes[i]->getNombre() << endl;

            int idxRest;
            cout << "Opción: "; cin >> idxRest; cin.ignore();

            if (idxRest < 1 || idxRest > restaurantes.size()) continue;
            Restaurante* rest = restaurantes[idxRest-1];

            int personas, mesa, idxEmp;
            string hora;
            cout << "Número de personas: "; cin >> personas; cin.ignore();
            cout << "Número de mesa: "; cin >> mesa; cin.ignore();
            cout << "Hora de reservación (HH:MM): "; getline(cin, hora);

            vector<Empleado*> emps = rest->getEmpleados();
            for (size_t i = 0; i < emps.size(); ++i)
                cout << i+1 << ". " << emps[i]->getNombre() << endl;
            cout << "Seleccione empleado (1 a " << emps.size() << "): ";
            cin >> idxEmp; cin.ignore();
            if (idxEmp < 1 || idxEmp > emps.size()) continue;

            Reservacion r(clienteRegistrado, emps[idxEmp-1], rest->getNombre(), personas, mesa, hora);
            r.generarFactura();
        }
    } while (opcion != 3);

    for (auto& r : restaurantes) delete r;
    delete clienteRegistrado;
    return 0;
}
