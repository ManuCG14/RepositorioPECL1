#ifndef PILA_HPP
#define PILA_HPP

#include "NodoPila.hpp"
#include <iostream>
using namespace std;

class Pila
{
public:
    Pila();
    ~Pila();

    void insertar(Aficionado afi);
    Aficionado extraer();          
    Aficionado cima() const;      
    void mostrar() const;
    int getlongitud() const;       

private:
    pnodoPila ultimo;
    int longitud;
};

#endif // PILA_HPP
