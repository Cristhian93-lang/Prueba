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

bool confirmarContrasena(Cliente* cliente) {
    string intento;
    cout << "\nIngrese su contrasena para confirmar su orden: ";
    getline(cin, intento);
    return intento == cliente->getContrasena();
}

int main() {
    string nombre, correo, telefono, direccion, contrasena;

    cout << "=== Registro de Cliente ===" << endl;
    cout << "Nombre: "; getline(cin, nombre);
    cout << "Correo: "; getline(cin, correo);
    cout << "Telefono: "; getline(cin, telefono);
    cout << "Direccion: "; getline(cin, direccion);
    cout << "Contrasena: "; getline(cin, contrasena);

    Cliente* cliente = new Cliente(nombre, 1, correo, telefono, direccion, contrasena);

    Restaurante* restaurantes[5] = {
        new Restaurante("Little Caesars"),
        new Restaurante("SushiDojo"),
        new Restaurante("McDonald's"),
        new Restaurante("Los Gusanos de Don Chucho Taco"),
        new Restaurante("KFC")
    };

    // Agregar platos
    restaurantes[0]->agregarPlato(Plato("Pizza Pepperoni", 100.0, true));
    restaurantes[0]->agregarPlato(Plato("Pizza Hawaiana", 90.0, false));
    restaurantes[0]->agregarPlato(Plato("Super Cheese Pepperoni", 199.0, true));
    restaurantes[0]->agregarPlato(Plato("Pepperoni Bacon Duo", 179.0, true));
    restaurantes[0]->agregarPlato(Plato("Combo Crazy Puffs", 204.0, true));

    restaurantes[1]->agregarPlato(Plato("Sushi Roll", 120.0, true));
    restaurantes[1]->agregarPlato(Plato("Nigiri", 80.0, true));
    restaurantes[1]->agregarPlato(Plato("Crunchy Camaron", 95.0, true));
    restaurantes[1]->agregarPlato(Plato("Yakimeshi Mixto", 125.0, false));
    restaurantes[1]->agregarPlato(Plato("Crunchy Cangrejo", 83.0, true));

    restaurantes[2]->agregarPlato(Plato("Cheeseburger", 110.0, true));
    restaurantes[2]->agregarPlato(Plato("Papas Fritas", 40.0, true));
    restaurantes[2]->agregarPlato(Plato("Home Office Big Mac", 99.0, false));
    restaurantes[2]->agregarPlato(Plato("Mc Trio Mediano McPollo", 89.0, true));
    restaurantes[2]->agregarPlato(Plato("Malteada Vainilla", 59.0, true));

    restaurantes[3]->agregarPlato(Plato("Taco Al Pastor x3", 35.0, true));
    restaurantes[3]->agregarPlato(Plato("Quesadilla", 45.0, true));
    restaurantes[3]->agregarPlato(Plato("QuesaBirria", 50.0, true));
    restaurantes[3]->agregarPlato(Plato("Taco Suadero", 20.0, true));
    restaurantes[3]->agregarPlato(Plato("Agua Sabor Orchata", 55.0, false));

    restaurantes[4]->agregarPlato(Plato("Buket Clasico 6 piezas", 269.0, true));
    restaurantes[4]->agregarPlato(Plato("MegaCombo Big Krunch", 208.0, true));
    restaurantes[4]->agregarPlato(Plato("Hot Cheese Fries", 125.0, true));
    restaurantes[4]->agregarPlato(Plato("Ke Tiras Lovers 9", 359.0, true));
    restaurantes[4]->agregarPlato(Plato("Coca Cola Lata", 29.0, false));

    string baseTel = "555-000";
    string direccionSucursal = "Sucursal Centro";
    for (int i = 0; i < 5; i++) {
        restaurantes[i]->agregarEmpleado(new Empleado("Juan - " + restaurantes[i]->getNombre(), 10, baseTel + "0", direccionSucursal, "Mesero"));
        restaurantes[i]->agregarEmpleado(new Empleado("Ana - " + restaurantes[i]->getNombre(), 11, baseTel + "1", direccionSucursal, "Mesero"));
        restaurantes[i]->agregarEmpleado(new Empleado("Mary - " + restaurantes[i]->getNombre(), 12, baseTel + "2", direccionSucursal, "Cocinera"));
        restaurantes[i]->agregarEmpleado(new Empleado("Diego - " + restaurantes[i]->getNombre(), 13, baseTel + "3", direccionSucursal, "Cocinera"));
    }

    int opcion;
    do {
        cout << "\n=== Menu Principal ===\n1. Pedidos\n2. Reservaciones\n3. Salir\nSeleccione una opcion: ";
        cin >> opcion; cin.ignore();

        if (opcion == 1) {
            cout << "\nSeleccione un restaurante:\n";
            for (int i = 0; i < 5; i++)
                cout << i + 1 << ". " << restaurantes[i]->getNombre() << endl;

            int idx;
            cout << "Opcion: "; cin >> idx; cin.ignore();
            if (idx < 1 || idx > 5) continue;

            Restaurante* r = restaurantes[idx - 1];
            Pedido p(cliente, obtenerHoraActual(), r->getNombre());

            char seguir = 's';
            while (seguir == 's' || seguir == 'S') {
                r->mostrarMenu();
                int sel;
                cout << "Seleccione el plato: ";
                cin >> sel; cin.ignore();
                if (sel >= 1 && sel <= r->sizePlatos()) {
                    const Plato* lista = r->getPlatos();
                    Plato pl = lista[sel - 1];
                    if (!pl.estaDisponible()) {
                        cout << "El plato '" << pl.getNombre() << "' no esta disponible.\n";
                    } else {
                        p.agregarPlato(pl.getNombre(), pl.getPrecio());
                    }
                }
                cout << "Desea agregar otro plato? (s/n): ";
                cin >> seguir; cin.ignore();
            }

            if (confirmarContrasena(cliente)) {
                string metodoPago;
                int mp;
                cout << "Metodo de pago:\n1. Efectivo\n2. Tarjeta\nOpcion: ";
                cin >> mp; cin.ignore();

                if (mp == 1) {
                    metodoPago = "Efectivo";
                    cout << "Una vez que el delivery llegue podra pagarle con efectivo. Gracias por su compra.\n";
                } else {
                    metodoPago = "Tarjeta";
                    string t, f, c;
                    cout << "Numero de tarjeta: "; getline(cin, t);
                    cout << "Fecha expiracion (MM/AA): "; getline(cin, f);
                    cout << "CVV: "; getline(cin, c);
                    cout << "Pago exitoso. Espere su pedido. Gracias por la compra.\n";
                }
                p.setMetodoPago(metodoPago);
                p.generarFactura();
            }
        }

        else if (opcion == 2) {
            cout << "\nSeleccione un restaurante:\n";
            for (int i = 0; i < 5; i++)
                cout << i + 1 << ". " << restaurantes[i]->getNombre() << endl;

            int idx;
            cout << "Opcion: "; cin >> idx; cin.ignore();
            if (idx < 1 || idx > 5) continue;

            Restaurante* r = restaurantes[idx - 1];
            int personas, mesa, idxEmp;
            string hora;
            cout << "Numero de personas: "; cin >> personas; cin.ignore();
            cout << "Numero de mesa: "; cin >> mesa; cin.ignore();
            cout << "Hora de reservacion (HH:MM): "; getline(cin, hora);

            Empleado** emps = r->getEmpleados();
            for (int i = 0; i < r->sizeEmpleados(); i++)
                cout << i + 1 << ". " << emps[i]->getNombre() << endl;

            cout << "Seleccione empleado: ";
            cin >> idxEmp; cin.ignore();
            if (idxEmp < 1 || idxEmp > r->sizeEmpleados()) continue;

            if (confirmarContrasena(cliente)) {
                Reservacion res(cliente, emps[idxEmp - 1], r->getNombre(), personas, mesa, hora);

                string metodoPago;
                int mp;
                cout << "Metodo de pago:\n1. Efectivo\n2. Tarjeta\nOpcion: ";
                cin >> mp; cin.ignore();

                if (mp == 1) {
                    metodoPago = "Efectivo";
                    cout << "Gracias por su reservacion. Lo esperamos.\n";
                } else {
                    metodoPago = "Tarjeta";
                    string t, f, c;
                    cout << "Numero de tarjeta: "; getline(cin, t);
                    cout << "Fecha expiracion (MM/AA): "; getline(cin, f);
                    cout << "CVV: "; getline(cin, c);
                    cout << "Pago exitoso. Gracias por su reservacion.\n";
                }
                res.setMetodoPago(metodoPago);
                res.generarFactura();
            }
        }

    } while (opcion != 3);

    return 0;
}

