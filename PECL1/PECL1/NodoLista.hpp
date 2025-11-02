#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP

#include "Aficionado.hpp"

class NodoLista
{
public:
    Aficionado aficionado;   
    NodoLista* siguiente;

    NodoLista(Aficionado a, NodoLista* sig = nullptr)
        : aficionado(a), siguiente(sig) {}

    
};

#endif
