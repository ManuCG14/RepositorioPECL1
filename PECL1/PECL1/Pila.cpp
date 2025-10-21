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
	ultimo = nodo->siguinte;
	afi =  nodo->aficionado;
	longitud--;
	delete nodo;
	return afi;
} 	 	
int Pila::cima(){
	pnodoPila nodo;
	if(!ultimo)
		return 0;
	return ultimo->aficionado;
}
void Pila::mostrar(){
	pnodoPila aux = ultimo;
	cout << "\tEl contenido de la pila es: ";
	while(aux) {
	cout << "-> " << aux->aficionado;
	aux = aux->siguiente;
	}
	cout <<endl;
}
int Pila::getLongitud(){
	return this->longitud;
}
Pila::~Pila()
{
	pnodoPila aux;
	while(ultimo){
		aux = ultimo;
		ultimo= ultimo-> siguiente;
		delete aux;
	}
}

