#include "NodoArbol.hpp"

NodoArbol::NodoArbol(Aficionado* aficionado)
{
	dato = aficionado;
	izquierdo = nullptr;
	derecho = nullptr;
}

NodoArbol::~NodoArbol()
{
}