#include <iostream>
#include <vector>
using namespace std;

class Jugador {
protected:
    int id;
    bool ganoAlMenosUnDuelo;
public:
    Jugador(int id, bool gano) : id(id), ganoAlMenosUnDuelo(gano) {}
    bool gano() const { return ganoAlMenosUnDuelo; }
};

class JugadorCompetitivo : public Jugador {
public:
    JugadorCompetitivo(int id, bool gano) : Jugador(id, gano) {}
};

class Torneo {
private:
    vector<JugadorCompetitivo> jugadores; // sin punteros

public:
    Torneo(int n, const vector<int>& reportes) {
        for (int i = 0; i < n; ++i) {
            jugadores.emplace_back(i + 1, reportes[i]);
        }
    }

    bool hayMentiroso() {
        int ganadores = 0;
        for (auto& jugador : jugadores) {
            if (jugador.gano()) ganadores++;
        }
        return ganadores > jugadores.size() - 1;
    }
};

class Plataforma {
public:
    void ejecutar() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
            vector<int> reportes(n);
            for (int i = 0; i < n; ++i) cin >> reportes[i];

            Torneo torneo(n, reportes);
            cout << (torneo.hayMentiroso() ? "YES" : "NO") << endl;
        }
    }
};

int main() {
    Plataforma app;
    app.ejecutar();
    return 0;
}
