#ifndef COLA_HPP
#define COLA_HPP
#include "Aficionado.hpp"
#include "NodoCola.hpp"
#include <iostream>
using namespace std;

class Cola
{
public:
    Cola();
    ~Cola();
    
    void insertar(Aficionado* aficionado);
    Aficionado* eliminar();
    Aficionado* verPrimero();
    void mostrar();

    bool estaVacia();      
    int getLongitud();    

private:
    pnodoCola primero, ultimo;
    int longitud;
};

#endif // COLA_HPP

