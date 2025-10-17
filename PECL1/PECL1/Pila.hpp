#ifndef PILA_HPP
#define PILA_HPP
#include "NodoPila.hpp"	
class Pila
{
public:
	Pila();
	~Pila();
	void insertar(Aficionado afi);
	Aficionado extraer();
	Aficionado cima();
	void mostrar();
	int getlongitud();
	
private:
	pnodoPila ultimo;
	int longitud;

};

#endif // PILA_HPP
