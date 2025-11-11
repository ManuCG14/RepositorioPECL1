#include "NodoLista.hpp"

NodoLista::NodoLista(Aficionado* aficionado, NodoLista* sig) 
{
	dato = aficionado;
	siguiente = sig;
}

NodoLista::~NodoLista()
{
}

