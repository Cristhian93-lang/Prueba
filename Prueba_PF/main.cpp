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

    string intentoContrasena;
    bool autenticado = false;
    int intentos = 3;

    while (intentos > 0 && !autenticado) {
        cout << "\nIngrese su contraseña para continuar: ";
        getline(cin, intentoContrasena);

        if (intentoContrasena == clienteRegistrado->getContrasena()) {
            cout << "Contraseña correcta.\n";
            autenticado = true;
        } else {
            intentos--;
            cout << "Contraseña incorrecta. Intentos restantes: " << intentos << endl;
        }
    }

    if (!autenticado) {
        cout << "Demasiados intentos fallidos. Cerrando programa.\n";
        return 0;
    }

    Restaurante* restaurantes[5] = {
        new Restaurante("Little Caesars"),
        new Restaurante("SushiDojo"),
        new Restaurante("McDonald's"),
        new Restaurante("Los Gusanos de Don Chucho Taco"),
        new Restaurante("KFC")
    };

    for (int i = 0; i < 5; ++i) {
        string baseTel = "555-000";
        string direccionSucursal = "Sucursal Centro";
        restaurantes[i]->agregarEmpleado(new Empleado("Juan - " + restaurantes[i]->getNombre(), 10, baseTel + "0", direccionSucursal, "Mesero"));
        restaurantes[i]->agregarEmpleado(new Empleado("Ana - " + restaurantes[i]->getNombre(), 11, baseTel + "1", direccionSucursal, "Mesero"));
        restaurantes[i]->agregarEmpleado(new Empleado("Mary - " + restaurantes[i]->getNombre(), 12, baseTel + "2", direccionSucursal, "Cocinera"));
        restaurantes[i]->agregarEmpleado(new Empleado("Diego - " + restaurantes[i]->getNombre(), 13, baseTel + "3", direccionSucursal, "Cocinera"));
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
