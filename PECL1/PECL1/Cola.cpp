#include "Cola.hpp"

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

void Cola::insertar(Aficionado v)
{
    pnodoCola nuevo = new NodoCola(v);
    if (ultimo)
        ultimo->siguiente = nuevo;
    ultimo = nuevo;
    if (!primero)
        primero = nuevo;
    longitud++;
}

Aficionado Cola::eliminar()
{
    if (!primero)
    {
        cout << "\t[La cola está vacía]\n";
        return Aficionado(-1); // Devuelve un Aficionado "inválido"
    }

    pnodoCola nodo = primero;
    Aficionado v = nodo->valor;
    primero = nodo->siguiente;
    if (!primero)
        ultimo = NULL;

    delete nodo;
    longitud--;
    return v;
}

void Cola::mostrar() const
{
    if (!primero)
    {
        cout << "\t[La cola está vacía]\n";
        return;
    }

    pnodoCola aux = primero;
    cout << "\tContenido de la cola:\n";
    while (aux)
    {
        cout << "\t\t";
        aux->valor.mostrarInfo();
        aux = aux->siguiente;
    }
    cout << endl;
}

Aficionado Cola::verPrimero() const
{
    if (!primero)
    {
        cout << "\t[La cola está vacía]\n";
        return Aficionado(-1);
    }
    return primero->valor;
}

bool Cola::estaVacia() const
{
    return primero == NULL;
}

Cola::~Cola()
{
    while (primero)
        eliminar();
}
