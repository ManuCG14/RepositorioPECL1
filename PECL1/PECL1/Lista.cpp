#include "Lista.hpp"

Lista::Lista()
{
    primero = nullptr;
    ultimo = nullptr;
    longitud = 0;
}

Lista::~Lista()
{
    vaciar();
}

bool Lista::estaVacia() const
{
    return primero == nullptr;
}

void Lista::vaciar()
{
    while (primero)
    {
        NodoLista* aux = primero;
        primero = primero->siguiente;
        delete aux->aficionado;
        delete aux;
    }
    ultimo = nullptr;
    longitud = 0;
}

// Según la hora de llegada
void Lista::insertarOrdenado(Aficionado* a)
{
    NodoLista* nuevo = new NodoLista(a);

    if (!primero || a->getHora() < primero->aficionado->getHora())
    {
        nuevo->siguiente = primero;
        primero = nuevo;
        if (!ultimo)
            ultimo = nuevo;
    }
    else
    {
        NodoLista* actual = primero;
        while (actual->siguiente && actual->siguiente->aficionado->getHora() <= a->getHora())
        {
            actual = actual->siguiente;
        }
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
        if (!nuevo->siguiente)
            ultimo = nuevo;
    }

    longitud++;
}

void Lista::mostrar() const
{
    if (!primero)
    {
        cout << "\t[La lista está vacía]\n";
        return;
    }

    cout << "\n\tContenido de la lista (ordenado por hora de llegada):\n";
    NodoLista* aux = primero;
    while (aux)
    {
        cout << "\t";
        aux->aficionado->mostrarInfo();
        aux = aux->siguiente;
    }
    cout << endl;
}

// Consulta

int Lista::getLongitud() const
{
    return longitud;
}

Aficionado* Lista::getPrimero() const
{
    return (primero ? primero->aficionado : nullptr);
}

Aficionado* Lista::getUltimo() const
{
    return (ultimo ? ultimo->aficionado : nullptr);
}

// Devuelve el último socio que accede (recorremos hasta el final)
Aficionado* Lista::getPrimerSocio() const
{
    NodoLista* aux = primero;
    Aficionado* socio = nullptr;

    while (aux)
    {
        if (aux->aficionado->esSocio())
            socio = aux->aficionado;
        aux = aux->siguiente;
    }

    return socio;
}

// Devuelve el primer simpatizante en acceder
Aficionado* Lista::getPrimerSimpatizante() const
{
    NodoLista* aux = primero;
    while (aux)
    {
        if (!aux->aficionado->esSocio())
            return aux->aficionado;
        aux = aux->siguiente;
    }
    return nullptr;
}
