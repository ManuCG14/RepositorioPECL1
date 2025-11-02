#include "Pila.hpp"

Pila::Pila()
{
    ultimo = nullptr;
    longitud = 0;
}

void Pila::insertar(Aficionado afi)
{
    pnodoPila nuevo = new NodoPila(afi, ultimo);
    ultimo = nuevo;
    longitud++;
}

Aficionado Pila::extraer()
{
    if (!ultimo)
    {
        cout << "\t[La pila está vacía]\n";
        return Aficionado(-1, 0, false); 
    }

    pnodoPila nodo = ultimo;
    Aficionado afi = nodo->aficionado;
    ultimo = nodo->siguiente;
    delete nodo;
    longitud--;
    return afi;
}

Aficionado Pila::cima() const
{
    if (!ultimo)
    {
        cout << "\t[La pila está vacía]\n";
        return Aficionado(-1, 0, false);
    }
    return ultimo->aficionado;
}

void Pila::mostrar() const
{
    if (!ultimo)
    {
        cout << "\t[La pila está vacía]\n";
        return;
    }

    pnodoPila aux = ultimo;
    cout << "\n\tContenido de la pila (de arriba a abajo):\n";
    while (aux)
    {
        cout << "\t\t";
        aux->aficionado.mostrarInfo();
        aux = aux->siguiente;
    }
    cout << endl;
}

int Pila::getlongitud() const
{
    return longitud;
}

Pila::~Pila()
{
    while (ultimo)
        extraer();
}
