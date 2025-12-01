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

	// Parte 2 - Opciones K-R
	void crearABB(Lista& lista); 
	void dibujarEnConsola();     
	void mostrarSocios();        
	void mostrarSimpatizantes(); 
	void recorrerInorden();      
	
    // Opciones de búsqueda O
	Aficionado* getPrimerAficionado(); 
	Aficionado* getUltimoSocio();      
	Aficionado* getPrimerSimpatizante(); 
	Aficionado* getUltimoAficionado(); 

	int contarIdPares();                 
	void mostrarHojas();                 
	void eliminarAficionado(int id);     

	int getLongitud(); 

private:
	pnodoArbol raiz;
	int longitud; // Incluye el nodo ficticio

	void _insertar(pnodoArbol& nodo, Aficionado* aficionado);
	void _inorden(pnodoArbol nodo, bool soloSocios, bool soloSimpatizantes);
	void _preordenDibujo(pnodoArbol nodo, int nivel, char rama); 
	void _contarIdPares(pnodoArbol nodo, int& contador);
	void _mostrarHojas(pnodoArbol nodo);
	pnodoArbol _eliminar(pnodoArbol nodo, int id);
	pnodoArbol _encontrarMaximo(pnodoArbol nodo); 
	pnodoArbol _encontrarMinimo(pnodoArbol nodo); 
	void _destruir(pnodoArbol nodo);
};

#endif // ARBOL_HPP