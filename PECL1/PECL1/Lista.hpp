#ifndef LISTA_HPP
#define LISTA_HPP

#include "Aficionado.hpp"
#include <iostream>
using namespace std;

class NodoLista
{
public:
    Aficionado* aficionado;
    NodoLista* siguiente;

    NodoLista(Aficionado* a, NodoLista* sig = nullptr)
        : aficionado(a), siguiente(sig) {}
};

class Lista
{
private:
    NodoLista* primero;
    NodoLista* ultimo;
    int longitud;

public:
    Lista();
    ~Lista();

    void insertarOrdenado(Aficionado* a);
    void mostrar() const;

    // Consulta
    int getLongitud() const;
    Aficionado* getPrimero() const;
    Aficionado* getUltimo() const;
    Aficionado* getPrimerSocio() const;
    Aficionado* getPrimerSimpatizante() const;

    //Gestion
    bool estaVacia() const;
    void vaciar();
};

#endif // LISTA_HPP
