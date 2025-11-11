#include "Cola.hpp"

Cola::Cola()
{
    primero = nullptr;
    ultimo = nullptr;
    longitud = 0;
}

void Cola::insertar(Aficionado* aficionado)
{
    pnodoCola nuevo = new NodoCola(aficionado);
    if (ultimo)
        ultimo->siguiente = nuevo;

    ultimo = nuevo;

    if (!primero)
        primero = nuevo;
    longitud++;
}

Aficionado* Cola::eliminar()
{
    if (!primero)
        return nullptr;

    pnodoCola nodo = primero;
    Aficionado* aficionado = nodo->dato;
    primero = nodo->siguiente;
    delete nodo;

    if (!primero)
        ultimo = nullptr;

    longitud--;
    return aficionado;
}

Aficionado* Cola::verPrimero()
{
    return primero ? primero->dato : nullptr;
}

bool Cola::estaVacia() 
{
    return primero == nullptr;
}

int Cola::getLongitud() 
{
    return longitud;
}

void Cola::mostrar()
{
    pnodoCola aux = primero;
    cout << "\nContenido de la cola:\n";
    while (aux)
    {
        aux->dato->mostrar();
        aux = aux->siguiente;
    }
    cout << endl;
}

Cola::~Cola()
{
    while (primero)
        eliminar();
}

