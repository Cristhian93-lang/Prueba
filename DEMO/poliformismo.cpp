#include <iostream>
using namespace std;

class Estudiante{  //Base
    public:
        void come(){cout<< "Alimentos Baratos \n";}  //se llama en compilacion
        virtual void toma() = 0;  //mÃ©todo abstracto serÃ¡ sobreescrito ejecuciÃ³n
                                  //pure virtual

};

/* Usamos virtual  funcion() = 0; para declarar la clase completa
* como abstracta, por lo que ya no se podrÃ¡ crear un objeto de ella
* directamente. Observa cÃ³digo comentado en el main para ver ejemplo.
*/


class Programador : public Estudiante{
    public:
        void come(){cout << "Pizza \n";}
        void toma(){cout << "cafe \n";}
};


int main(){
   //Mem.Estatica   o  //Mem. Dinamica
   //Tiempo de comp    //tiempo de ejecucion
    Estudiante *est =  new Programador();

    est->come();   //imprime Alimentos Baratos  (sin virtual)
    est->toma();   //imprime Cafe               (con virtual)

    /* al hacer un clase abstracta ya no se puede declarar como objeto, por lo
    que el siguiente cÃ³digo marcarÃ­a errores de compilacion.

    Decomenta el cÃ³digo para que veas lo que ocurre cuando intentas
    declarar un objeto de una interfaz (clase abstracta) directamente */

    //Estudiante abst = new Estudiante();
    //abst.come();
    //abst.toma();

}