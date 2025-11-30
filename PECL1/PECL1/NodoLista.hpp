#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP
#include "Aficionado.hpp"

class NodoLista
{
public:
	NodoLista(Aficionado* aficionado, NodoLista* sig = nullptr);
	~NodoLista();
private:
	Aficionado* dato;
	NodoLista* siguiente;
	friend class Lista;
	friend class Arbol;

};
typedef NodoLista* pnodoLista;

#endif // NODOLISTA_HPP
