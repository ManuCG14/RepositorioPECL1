#include "Pila.hpp"

Pila::Pila()
{
	ultimo = NULL;
	longitud = 0;
}
void Pila::insertar(Aficionado afi){
	pnodoPila nuevo;
	nuevo= new NodoPila( afi, ultimo);
	ultimo = nuevo;
	longitud++;

}
Aficionado Pila::extraer();{
	pnodoPila nodo;
	Aficionado afi;
	if(!ultimo)
		return 0;
	nodo = ultimo;
	ultimo = nodo->siguente;
	afi =  nodo->aficionado;
	longitud--;
	delete nodo;
	return afi;
} 	 	

Pila::~Pila()
{
}

