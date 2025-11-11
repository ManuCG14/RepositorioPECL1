#ifndef NODOPILA_HPP
#define NODOPILA_HPP
#include "Aficionado.hpp"
#include <iostream>
using namespace std;

class NodoPila
{
public:
	NodoPila(Aficionado* aficionado, NodoPila* sig = nullptr);
	~NodoPila();

private:
	Aficionado* dato;
	NodoPila* siguiente;
	friend class Pila;

};
typedef NodoPila* pnodoPila;

#endif // NODOPILA_HPP
