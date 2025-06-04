#include <iostream>
#define MAX 100
#ifndef MEDIA_H
#define MEDIA_H
using namespace std;

class Media {
    protected:
        string nombre;
        float rating;
        string tipo;
    public:
        virtual string to_string() = 0;


};

#endif