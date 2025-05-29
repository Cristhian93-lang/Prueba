// sobrecarga de operadores y sintaxis avanzada const

#include <iostream>
using namespace std;

class CVector {
private:
    int x, y;

public:
    // constructores
    CVector() {}
    CVector(int a, int b) : x(a), y(b) {}

    // sobrecarga de operadores
    CVector operator + (const CVector&);
    CVector operator - (const CVector&);
    CVector& operator = (const CVector&);

    // getters
    int getX() const { return x; }
    int getY() const { return y; }
};

// sobrecarga del operador suma
CVector CVector::operator+ (const CVector& param) {
    CVector temp;
    temp.x = x + param.x;
    temp.y = y + param.y;
    return temp;
}

// sobrecarga del operador resta
CVector CVector::operator- (const CVector& param) {
    CVector temp;
    temp.x = x - param.x;
    temp.y = y - param.y;
    return temp;
}

// sobrecarga del operador de asignación
CVector& CVector::operator= (const CVector& param) {
    if (this != &param) {
        x = param.x;
        y = param.y;
    }
    return *this;
}

int main() {
    CVector foo(3, 1);
    CVector bar(1, 2);
    CVector fei(9, 9);
    CVector result;

    result = foo + bar - fei;

    cout << result.getX() << ',' << result.getY() << '\n';

    CVector new_one = result;
    result = result - fei;

    cout << "result " << result.getX() << ',' << result.getY() << '\n';
    cout << "new_one " << new_one.getX() << ',' << new_one.getY() << '\n';

    return 0;
}
