#ifndef NODOPILA_HPP
#define NODOPILA_HPP

#include "Aficionado.hpp"

class NodoPila
{
public:
    NodoPila(Aficionado afi, NodoPila* sig = nullptr);
    ~NodoPila();

private:
    Aficionado aficionado;
    NodoPila* siguiente;

    friend class Pila;
};

typedef NodoPila* pnodoPila;

#endif // NODOPILA_HPP
