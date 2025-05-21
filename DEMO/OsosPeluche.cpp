#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BearSorter {
public:
    virtual void sortGroup(vector<char>& group) = 0;
    virtual ~BearSorter() {}
};

class BFirstSorter : public BearSorter {
public:
    void sortGroup(vector<char>& group) override {
        sort(group.begin(), group.end(), [](char a, char b) {
            return a == 'B' && b == 'P';
        });
    }
};

class TeddyBear {
private:
    char color;
public:
    TeddyBear(char c) : color(c) {}
    char getColor() const { return color; }
    void setColor(char c) { color = c; }
};

class Shelf {
private:
    vector<TeddyBear> bears;
    BearSorter* sorter;
public:
    Shelf(BearSorter* sorter) : sorter(sorter) {}
    ~Shelf() { delete sorter; }
    
    void addBear(char c) { bears.emplace_back(c); }
    
    bool isBeautiful() const {
        bool seenP = false;
        for (const auto &bear : bears) {
            if (bear.getColor() == 'P') seenP = true;
            else if (seenP && bear.getColor() == 'B') return false;
        }
        return true;
    }
    
    void reorderGroup(int i) {
        if (i < 0 || i + 2 >= bears.size()) return;
        
        vector<char> group = {
            bears[i].getColor(),
            bears[i+1].getColor(),
            bears[i+2].getColor()
        };
        
        sorter->sortGroup(group);
        
        bears[i].setColor(group[0]);
        bears[i+1].setColor(group[1]);
        bears[i+2].setColor(group[2]);
    }
    
    int minOperationsToBeautiful() {
        if (isBeautiful()) return 0;
        int operations = 0;
        while (!isBeautiful()) {
            for (int i = 0; i < bears.size() - 2; ++i) {
                if (bears[i].getColor() == 'P' || bears[i+1].getColor() == 'P' || bears[i+2].getColor() == 'P') {
                    reorderGroup(i);
                    operations++;
                    break; // Reiniciar el bucle después de cada operación
                }
            }
        }
        return operations;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Caso específico que fallaba
    string test_case = "BPBPBBBBBPBBBBB";
    Shelf shelf(new BFirstSorter());
    for (char c : test_case) shelf.addBear(c);
    cout << "Operaciones necesarias: " << shelf.minOperationsToBeautiful() << endl;
    cout << "Resultado esperado: 14" << endl;

    return 0;
}