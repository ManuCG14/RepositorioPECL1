#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP

#include "Aficionado.hpp"

class NodoArbol
{
public:
	NodoArbol(Aficionado* aficionado);
	~NodoArbol();

private:
	Aficionado* dato;
	NodoArbol* izquierdo;
	NodoArbol* derecho;
	
    friend class Arbol;
	friend class Gestor;
};

typedef NodoArbol* pnodoArbol;

#endif // NODOARBOL_HPP