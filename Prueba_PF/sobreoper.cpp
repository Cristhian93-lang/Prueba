// sobrecarga de operadores y sintaxis avanzada const

#include <iostream>
using namespace std;

class Port{
    private:
        int priv1, priv2;

    public:

        int pub1, pub2;

        // constructores
    	  Port () {};
    	  Port (int a, int b, int c, int d): priv1(a), pub1(c){
            priv2 = b;
            pub2 = d;
        }

        // se usa const para encapsular el objeto i.e., que no sea modificable ya
        // que el paso es por referencia y existe el riesgo de cambios al objeto.
    	  Port operator * (const Port&);
          Port operator + (const Port&);

          int get_priv1() {return priv1;}
    	  int get_priv2() {return priv2;}
};

// sobrecarga de * para multipliaciÃ³n entre objetos.
Port Port::operator * (const Port &param){
  Port temp;
  temp.priv1 = priv1 * param.priv1;
  temp.priv2 = priv2 * param.priv2;
  temp.pub1 = pub1 * param.pub1;
  temp.pub2 = pub2 * param.pub2;
  return temp;
}

Port Port::operator+(const Port &param) {
    Port temp;
    temp.priv1 = priv1 + param.priv1;
    temp.priv2 = priv2 + param.priv2;
    temp.pub1 = pub1 + param.pub1;
    temp.pub2 = pub2 + param.pub2;
    return temp;
}
int main () {

  Port hugo(1,2,3,4);
  Port paco(5,6,7,8);
  Port luis;
  Port miguel;
  //  luis = hugo.operator*(paco);
  luis = hugo * paco;
  miguel = hugo + paco;

  cout << hugo.get_priv1() << ',' << hugo.get_priv2() << ',' << hugo.pub1 << ',' << hugo.pub2 << '\n' ;
  cout << paco.get_priv1() << ',' << paco.get_priv2() << ',' << paco.pub1 << ',' << paco.pub2 << '\n' ;
  cout << luis.get_priv1() << ',' << luis.get_priv2() << ',' << luis.pub1 << ',' << luis.pub2 << '\n' ;

  cout << "Suma:\n";
  cout << hugo.get_priv1() << ',' << hugo.get_priv2() << ',' << hugo.pub1 << ',' << hugo.pub2 << '\n' ;
  cout << paco.get_priv1() << ',' << paco.get_priv2() << ',' << paco.pub1 << ',' << paco.pub2 << '\n' ;
  cout << miguel.get_priv1() << ',' << miguel.get_priv2() << ',' << miguel.pub1 << ',' << miguel.pub2 << '\n';



  return 0;
}