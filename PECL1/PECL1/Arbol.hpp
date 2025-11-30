#ifndef ARBOL_HPP
#define ARBOL_HPP

#include "NodoArbol.hpp"
#include "Aficionado.hpp"
#include "Lista.hpp" // Necesario para crearABB
#include <iostream>

class Arbol
{
public:
	Arbol();
	~Arbol();

	void crearABB(Lista& lista); 
	void dibujarEnConsola();     
	
	void mostrarSocios();        
	void mostrarSimpatizantes(); 
	void recorrerInorden();      
	
	Aficionado* getPrimerAficionado(); // Devuelve el dato del primer nodo en el subárbol izquierdo (menor ID socio)
	Aficionado* getUltimoSocio();      // Devuelve el dato del nodo más a la derecha del subárbol izquierdo (mayor ID socio)
	Aficionado* getPrimerSimpatizante(); // Devuelve el dato del primer nodo en el subárbol derecho (menor ID simpatizante)
	Aficionado* getUltimoAficionado(); // Devuelve el dato del nodo más a la derecha del subárbol derecho (mayor ID simpatizante)

	int contarIdPares();                 
	void mostrarHojas();                 
	void eliminarAficionado(int id);     

	int getLongitud(); 

private:
	pnodoArbol raiz;
	int longitud;

	void _insertar(pnodoArbol& nodo, Aficionado* aficionado);
	void _inorden(pnodoArbol nodo, bool soloSocios, bool soloSimpatizantes);
	void _preordenDibujo(pnodoArbol nodo, int nivel, char rama); // Auxiliar para dibujar
	void _contarIdPares(pnodoArbol nodo, int& contador);
	void _mostrarHojas(pnodoArbol nodo);
	pnodoArbol _eliminar(pnodoArbol nodo, int id);
	pnodoArbol _encontrarMaximo(pnodoArbol nodo);
	pnodoArbol _encontrarMinimo(pnodoArbol nodo); // Usado para encontrar el primer/último elemento
	void _destruir(pnodoArbol nodo);
};

#endif // ARBOL_HPP