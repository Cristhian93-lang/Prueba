#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Participante {
    public:
    Participante(int nivel) : nivelHabilidad(nivel) {}
    int obtenerNivel() const { return nivelHabilidad; }

    protected:
        int nivelHabilidad;

};

class Alumno : public Participante {
    public:
        Alumno(int nivel) : Participante(nivel) {}
    };

class Coordinador {
    public:
    Coordinador(int umbral) : umbralFuerza(umbral) {}

    void registrarAlumno(const Alumno& a) {
        grupoEntrenamiento.push_back(a);
    }

    int contarEquiposFuertes() {
        sort(grupoEntrenamiento.begin(), grupoEntrenamiento.end(), [](const Alumno& a, const Alumno& b) {
            return a.obtenerNivel() > b.obtenerNivel();
        });

        int equiposFormados = 0;
        int integrantesActuales = 0;

        for (const auto& alumno : grupoEntrenamiento) {
            integrantesActuales++;
            if (integrantesActuales * alumno.obtenerNivel() >= umbralFuerza) {
                equiposFormados++;
                integrantesActuales = 0;
            }
        }

        return equiposFormados;
    }
private:
    vector<Alumno> grupoEntrenamiento;
    int umbralFuerza;

};

int main() {
    int totalCasos;
    cin >> totalCasos;

    for (int caso = 0; caso < totalCasos; ++caso) {
        int cantidadAlumnos, fuerzaMinima;
        cin >> cantidadAlumnos >> fuerzaMinima;

        Coordinador organizador(fuerzaMinima);
        for (int i = 0; i < cantidadAlumnos; ++i) {
            int nivel;
            cin >> nivel;
            Alumno nuevo(nivel);
            organizador.registrarAlumno(nuevo);
        }

        cout << organizador.contarEquiposFuertes() << '\n';
    }

    return 0;
}
