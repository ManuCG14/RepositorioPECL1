#include "Pila.hpp"

Pila::Pila()
{
	ultimo = nullptr;
	longitud = 0;
}

void Pila::insertar(Aficionado* aficionado)
{
	pnodoPila nuevo;
	nuevo = new NodoPila(aficionado,ultimo);
	ultimo = nuevo;
	longitud++;
}

Aficionado* Pila::extraer()
{
	pnodoPila nodo;
	Aficionado* aficionado;
	if(!ultimo)
		return nullptr;
	nodo = ultimo;
	ultimo = nodo->siguiente;
	aficionado = nodo -> dato;
	longitud--;
	delete nodo;
	return aficionado;
}

Aficionado* Pila::cima()
{
	pnodoPila nodo;
	if(!ultimo)
		return nullptr;
	return ultimo -> dato;
}

void Pila::mostrar()
{
    pnodoPila aux = ultimo;
    cout << "\nContenido de la pila:\n";
    while (aux)
    {
        aux->dato->mostrar();
        aux = aux->siguiente;
    }
    cout << endl;
}

int Pila::getLongitud()
{
	return this->longitud;
}

Pila::~Pila()
{
	pnodoPila aux;
	while(ultimo){
		aux = ultimo;
		ultimo = ultimo->siguiente;
        delete aux->dato; // libera el Aficionado almacenado
        delete aux;       // libera el nodo
}
}
