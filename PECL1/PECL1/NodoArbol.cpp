#include "NodoArbol.hpp"

NodoArbol::NodoArbol(Aficionado* aficionado)
{
	this->dato = aficionado; 
	this->izquierdo = nullptr; 
	this->derecho = nullptr;
}

NodoArbol::~NodoArbol() 
{
}