#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Grafo {
protected:
    int numNodos;
public:
    Grafo(int n) : numNodos(n) {}
    virtual ~Grafo() {}
};

class Arbol : public Grafo {
private:
    struct Nodo {
        int id;
        bool tieneManzana;
        Nodo(int id) : id(id), tieneManzana(true) {}
    };
    vector<Nodo> nodos;
    vector<vector<int>> listaAdy;

    // BFS que devuelve el nodo más lejano y su distancia
    pair<int, int> bfsLejano(int inicio) {
        queue<int> q;
        vector<int> distancia(numNodos + 1, -1);
        vector<int> padre(numNodos + 1, -1);
        q.push(inicio);
        distancia[inicio] = 0;
        int lejano = inicio;

        while (!q.empty()) {
            int actual = q.front();
            q.pop();
            for (int vecino : listaAdy[actual]) {
                if (distancia[vecino] == -1 && nodos[vecino].tieneManzana) {
                    distancia[vecino] = distancia[actual] + 1;
                    padre[vecino] = actual;
                    q.push(vecino);
                    if (distancia[vecino] > distancia[lejano] || 
                        (distancia[vecino] == distancia[lejano] && vecino > lejano)) {
                        lejano = vecino;
                    }
                }
            }
        }
        return {lejano, distancia[lejano]};
    }

    // Encuentra el camino más largo y lo devuelve ordenado
    pair<int, pair<int, int>> encontrarCaminoMaximo() {
        // Paso 1: Encontrar el nodo con manzana de mayor ID
        int inicio = -1;
        for (int i = numNodos; i >= 1; --i) {
            if (nodos[i].tieneManzana) {
                inicio = i;
                break;
            }
        }
        if (inicio == -1) return {-1, {-1, -1}};

        // Paso 2: Encontrar el diámetro del subárbol
        auto [extremo1, _] = bfsLejano(inicio);
        auto [extremo2, distancia] = bfsLejano(extremo1);

        // Ordenar extremos para maximizar lexicográficamente
        if (extremo1 < extremo2) swap(extremo1, extremo2);
        return {distancia + 1, {extremo1, extremo2}};
    }

public:
    Arbol(int n) : Grafo(n) {
        nodos.reserve(n + 1);
        for (int i = 0; i <= n; ++i) {
            nodos.emplace_back(i);
        }
        listaAdy.resize(n + 1);
    }

    void agregarArista(int u, int v) {
        listaAdy[u].push_back(v);
        listaAdy[v].push_back(u);
    }

    vector<int> obtenerSecuenciaOptima() {
        vector<int> secuencia;
        vector<pair<int, pair<int, int>>> caminos;

        // Paso 1: Procesar todos los caminos largos (D > 1)
        while (true) {
            auto resultado = encontrarCaminoMaximo();
            int d = resultado.first;
            auto [u, v] = resultado.second;
            if (d == -1) break;

            caminos.push_back({d, {u, v}});
            // Marcar nodos del camino como sin manzanas
            queue<int> q;
            vector<bool> visitado(numNodos + 1, false);
            vector<int> padre(numNodos + 1, -1);
            q.push(u);
            visitado[u] = true;

            while (!q.empty()) {
                int actual = q.front();
                q.pop();
                for (int vecino : listaAdy[actual]) {
                    if (!visitado[vecino] && nodos[vecino].tieneManzana) {
                        visitado[vecino] = true;
                        padre[vecino] = actual;
                        q.push(vecino);
                    }
                }
            }

            for (int nodo = v; nodo != -1; nodo = padre[nodo]) {
                nodos[nodo].tieneManzana = false;
            }
        }

        // Paso 2: Ordenar caminos por D descendente y luego por U descendente
        sort(caminos.begin(), caminos.end(), [](const auto& a, const auto& b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second.first > b.second.first;
        });

        // Paso 3: Añadir caminos a la secuencia
        for (const auto& camino : caminos) {
            secuencia.push_back(camino.first);
            secuencia.push_back(camino.second.first);
            secuencia.push_back(camino.second.second);
        }

        // Paso 4: Procesar nodos aislados (D = 1)
        for (int i = numNodos; i >= 1; --i) {
            if (nodos[i].tieneManzana) {
                secuencia.push_back(1);
                secuencia.push_back(i);
                secuencia.push_back(i);
                nodos[i].tieneManzana = false;
            }
        }

        return secuencia;
    }
};

void imprimirSecuencia(const vector<int>& secuencia) {
    for (size_t i = 0; i < secuencia.size(); ++i) {
        if (i > 0) cout << " ";
        cout << secuencia[i];
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int casosPrueba;
    cin >> casosPrueba;
    while (casosPrueba--) {
        int n;
        cin >> n;
        Arbol arbol(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            arbol.agregarArista(u, v);
        }
        vector<int> secuencia = arbol.obtenerSecuenciaOptima();
        imprimirSecuencia(secuencia);
    }
    return 0;
}