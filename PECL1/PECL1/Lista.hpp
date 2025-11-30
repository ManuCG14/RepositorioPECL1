#ifndef LISTA_HPP
#define LISTA_HPP
#include "NodoLista.hpp"
#include <iostream>
using namespace std;

class Lista
{
public:
    Lista();
    ~Lista();

    void insertarOrdenado(Aficionado* aficionado);
    void mostrar();

    bool estaVacia();
    int getLongitud();

    // Métodos usados por Gestor
    Aficionado* getPrimero();
    Aficionado* getUltimo();
    Aficionado* getPrimerSocio();
    Aficionado* getPrimerSimpatizante();

private:
    pnodoLista primero;
    int longitud;
	friend class Arbol;
};

#endif // LISTA_HPP