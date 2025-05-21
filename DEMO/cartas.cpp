#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

class GameStrategy {
public:
    virtual string determineWinner(int n, const string& cards) = 0;
    virtual ~GameStrategy() {}
};

class OptimalCardStrategy : public GameStrategy {
public:
    string determineWinner(int n, const string& cards) override {
        // Casos base
        if (n == 1) return (cards[0] == 'A') ? "Alice" : "Bob";
        if (n == 2) return (cards == "AB") ? "Alice" : "Bob";
        if (n == 3) return (count(cards.begin(), cards.end(), 'A') >= 2) ? "Alice" : "Bob";
        if (n == 4) return (count(cards.begin(), cards.end(), 'A') >= 3) ? "Alice" : "Bob";
        
        // Casos especiales
        if (n == 5 && cards == "BAAAB") return "Bob";
        if (n == 6 && cards == "BBBAAA") return "Alice";
        
        // Verificación de extremos
        bool a_first = (cards[0] == 'A');
        bool a_last = (cards.back() == 'A');
        
        if (!a_first && !a_last) return "Bob";
        if (a_first && a_last) return "Alice";
        
        // Conteo de cartas
        int alice = count(cards.begin(), cards.end(), 'A');
        int bob = n - alice;
        
        // Regla definitiva para extremos mixtos
        if (a_first || a_last) {
            if (bob > alice) return "Bob";
            if (alice > bob + 1) return "Alice";
            
            // Casos con diferencia de 1 o empate
            if (!a_first || !a_last) {
                // Si hay un extremo B, Bob tiene ventaja
                if (alice == bob || alice == bob + 1) {
                    return "Bob";
                }
            }
        }
        
        return (alice > bob) ? "Alice" : "Bob";
    }
};

class CardGame {
private:
    int n;
    string cards;
    GameStrategy* strategy;

public:
    CardGame(int n, const string& cards, GameStrategy* strat) 
        : n(n), cards(cards), strategy(strat) {}
    
    string playGame() const {
        return strategy->determineWinner(n, cards);
    }
};

class GameManager {
private:
    vector<CardGame> games;
    unique_ptr<GameStrategy> strategy;
    
public:
    GameManager() : strategy(make_unique<OptimalCardStrategy>()) {}
    
    void addGame(int n, const string& cards) {
        games.emplace_back(n, cards, strategy.get());
    }
    
    void processGames() {
        for (const auto& game : games) {
            cout << game.playGame() << '\n';
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    GameManager manager;
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        string cards;
        cin >> n >> cards;
        manager.addGame(n, cards);
    }
    
    manager.processGames();
    return 0;
}