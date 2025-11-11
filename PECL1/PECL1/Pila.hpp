#ifndef PILA_HPP
#define PILA_HPP
#include "Aficionado.hpp"
#include "NodoPila.hpp"
#include <iostream>
using namespace std;

class Pila
{
public:
	Pila();
	~Pila();
	void insertar(Aficionado* aficionado);
	Aficionado* extraer();
	Aficionado* cima();
	void mostrar();
	int getLongitud();
	
private:
	pnodoPila ultimo;
	int longitud;

};

#endif // PILA_HPP