#include <iostream>
#include <string>
#include <ctime>
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

    Restaurante* restaurantes[5] = {
        new Restaurante("Little Caesars"),
        new Restaurante("SushiDojo"),
        new Restaurante("McDonald's"),
        new Restaurante("Los Gusanos de Don Chucho Taco"),
        new Restaurante("KFC")
    };

    restaurantes[0]->agregarPlato(Plato("Pizza Pepperoni", 100.0, true));
    restaurantes[0]->agregarPlato(Plato("Pizza Hawaiana", 90.0, true));
    restaurantes[0]->agregarPlato(Plato("Super Cheese Pepperoni", 199.0, true));
    restaurantes[0]->agregarPlato(Plato("Pepperoni Bacon Duo", 179.0, true));
    restaurantes[0]->agregarPlato(Plato("Combo Crazy Puffs", 204.0, true));

    restaurantes[1]->agregarPlato(Plato("Sushi Roll", 120.0, true));
    restaurantes[1]->agregarPlato(Plato("Nigiri", 80.0, true));
    restaurantes[1]->agregarPlato(Plato("Crunchy Camaron", 95.0, true));
    restaurantes[1]->agregarPlato(Plato("Yakimeshi Mixto", 125.0, true));
    restaurantes[1]->agregarPlato(Plato("Crunchy Cangrejo", 83.0, true));

    restaurantes[2]->agregarPlato(Plato("Cheeseburger", 110.0, true));
    restaurantes[2]->agregarPlato(Plato("Papas Fritas", 40.0, true));
    restaurantes[2]->agregarPlato(Plato("Home Office Big Mac", 99.0, true));
    restaurantes[2]->agregarPlato(Plato("Mc Trio Mediano McPollo", 89.0, true));
    restaurantes[2]->agregarPlato(Plato("Malteada Vainilla", 59.0, true));

    restaurantes[3]->agregarPlato(Plato("Taco Al Pastor x3", 35.0, true));
    restaurantes[3]->agregarPlato(Plato("Quesadilla", 45.0, true));
    restaurantes[3]->agregarPlato(Plato("QuesaBirria", 50.0, true));
    restaurantes[3]->agregarPlato(Plato("Taco Suadero", 20.0, true));
    restaurantes[3]->agregarPlato(Plato("Agua Sabor Orchata", 55.0, true));

    restaurantes[4]->agregarPlato(Plato("Buket Clasico 6 piesas", 269.0, true));
    restaurantes[4]->agregarPlato(Plato("MegaCombo Big Krunch", 208.0, true));
    restaurantes[4]->agregarPlato(Plato("Hot Cheese Fries", 125.0, true));
    restaurantes[4]->agregarPlato(Plato("Ke Tiras Lovers 9", 359.0, true));
    restaurantes[4]->agregarPlato(Plato("Coca Cola Lata", 29.0, true));

    for (int i = 0; i < 5; ++i) {
        restaurantes[i]->agregarEmpleado(new Empleado("Juan - " + restaurantes[i]->getNombre(), 10, "Mesero"));
        restaurantes[i]->agregarEmpleado(new Empleado("Ana - " + restaurantes[i]->getNombre(), 11, "Mesero"));
        restaurantes[i]->agregarEmpleado(new Empleado("Mary - " + restaurantes[i]->getNombre(), 12, "Cocinera"));
        restaurantes[i]->agregarEmpleado(new Empleado("Diego - " + restaurantes[i]->getNombre(), 13, "Cocinera"));
    }

    int opcion;
    do {
        cout << "\n=== Menu Principal ===" << endl;
        cout << "1. Pedidos" << endl;
        cout << "2. Reservaciones" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            cout << "\nSeleccione un restaurante:" << endl;
            for (int i = 0; i < 5; ++i)
                cout << i + 1 << ". " << restaurantes[i]->getNombre() << endl;

            int idxRest;
            cout << "Opcion: "; cin >> idxRest; cin.ignore();
            if (idxRest < 1 || idxRest > 5) continue;

            Restaurante* rest = restaurantes[idxRest - 1];
            Pedido pedido(clienteRegistrado, obtenerHoraActual(), rest->getNombre());

            char continuar = 's';
            while (continuar == 's') {
                rest->mostrarMenu();
                const Plato* lista = rest->getPlatos();
                int numPlatos = rest->sizePlatos();

                int idxPlato;
                cout << "Seleccione el plato: ";
                cin >> idxPlato; cin.ignore();

                if (idxPlato >= 1 && idxPlato <= numPlatos) {
                    Plato p = lista[idxPlato - 1];
                    pedido.agregarPlato(p);
                } else {
                    cout << "Plato invalido. Intente de nuevo.\n";
                }

                cout << "\nDesea agregar otro plato? (s/n): ";
                cin >> continuar;
                cin.ignore();
            }
            pedido.generarFactura();
        }
        else if (opcion == 2) {
            cout << "\nSeleccione un restaurante:" << endl;
            for (int i = 0; i < 5; ++i)
                cout << i + 1 << ". " << restaurantes[i]->getNombre() << endl;

            int idxRest;
            cout << "Opcion: "; cin >> idxRest; cin.ignore();
            if (idxRest < 1 || idxRest > 5) continue;

            Restaurante* rest = restaurantes[idxRest - 1];
            int personas, mesa, idxEmp;
            string hora;
            cout << "Numero de personas: "; cin >> personas; cin.ignore();
            cout << "Numero de mesa: "; cin >> mesa; cin.ignore();
            cout << "Hora de reservacion (HH:MM): "; getline(cin, hora);

            Empleado** emps = rest->getEmpleados();
            int nEmps = rest->sizeEmpleados();
            for (int i = 0; i < nEmps; ++i)
                cout << i + 1 << ". " << emps[i]->getNombre() << endl;

            cout << "Seleccione empleado (1 a " << nEmps << "): ";
            cin >> idxEmp; cin.ignore();
            if (idxEmp < 1 || idxEmp > nEmps) continue;

            Reservacion r(clienteRegistrado, emps[idxEmp - 1], rest->getNombre(), personas, mesa, hora);
            r.generarFactura();
        }
    } while (opcion != 3);

    return 0;
}
