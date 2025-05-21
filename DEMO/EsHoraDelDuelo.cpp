#include <iostream>
#include <vector>
using namespace std;

// HERENCIA (clase base)
class Persona {
protected:
    int id;
public:
    Persona(int id) : id(id) {}
    virtual ~Persona() {}  // Destructor virtual
};

// HERENCIA (clase derivada)
class Duelista : public Persona {
private:  // ENCAPSULAMIENTO (private)
    bool victoriaReportada;
public:
    Duelista(int id, bool victoriaReportada) : Persona(id), victoriaReportada(victoriaReportada) {}
    bool obtuvoVictoria() const { return victoriaReportada; }  // Método const
};

// COMPOSICIÓN
class TorneoDuelo {
private:
    vector<Duelista> participantes;
public:
    void agregarDuelista(const Duelista& d) {
        participantes.push_back(d);
    }
    
    // Versión const para el validador
    bool detectarMentiroso() const {
        int n = participantes.size();
        if (n == 1) return participantes[0].obtuvoVictoria(); // 1 jugador con 1 es mentira
        
        if (n == 2) {
            bool a = participantes[0].obtuvoVictoria();
            bool b = participantes[1].obtuvoVictoria();
            return (a == b); // Si ambos son iguales, hay mentira
        }

        for (int i = 0; i < n; ++i) {
            if (!participantes[i].obtuvoVictoria()) {
                bool izquierdaPerdedor = (i > 0) && !participantes[i-1].obtuvoVictoria();
                bool derechaPerdedor = (i < n-1) && !participantes[i+1].obtuvoVictoria();
                if (izquierdaPerdedor || derechaPerdedor) return true;
            }
        }
        return false;
    }
};

// AGREGACIÓN
class ValidadorTorneo {
private:
    const TorneoDuelo& torneo;  // Agregación
public:
    ValidadorTorneo(const TorneoDuelo& t) : torneo(t) {}
    bool validar() const { return torneo.detectarMentiroso(); }  // Método const
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numCasos;
    cin >> numCasos;

    for (int caso = 0; caso < numCasos; ++caso) {
        int numDuelistas;
        cin >> numDuelistas;
        vector<bool> reportes(numDuelistas);
        
        TorneoDuelo torneo;
        for (int i = 0; i < numDuelistas; ++i) {
            int valor;
            cin >> valor;
            torneo.agregarDuelista(Duelista(i+1, valor == 1));
        }

        ValidadorTorneo validador(torneo);
        cout << (validador.validar() ? "YES" : "NO") << '\n';
    }

    return 0;
}