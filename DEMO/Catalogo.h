#include <iostream>
#include "Media.h"
#define MAX 100
#ifndef CATALOGO_H
#define CATALOGO_H
using namespace std;

class Catalogo {
    private:
        Media *media[MAX];
    public:
        void buscarMedia(Media);
        void filtrarRagting(float);
        void filtrarNombre(string);

};


#endif