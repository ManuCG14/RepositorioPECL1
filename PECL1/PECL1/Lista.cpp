#include "Lista.hpp"

Lista::Lista()
{
    primero = nullptr;
    longitud = 0;
}

bool Lista::estaVacia()
{
    return primero == nullptr;
}

int Lista::getLongitud()
{
    return longitud;
}

void Lista::insertarOrdenado(Aficionado* aficionado)
{
    pnodoLista nuevo = new NodoLista(aficionado);
    pnodoLista actual = primero;
    pnodoLista anterior = nullptr;

    // Insertar en orden: primero los socios, luego los simpatizantes
    while (actual)
    {
        // Caso 1: si el nuevo es simpatizante y el actual es socio → seguimos avanzando
        if (!aficionado->esSocio() && actual->dato->esSocio())
        {
            anterior = actual;
            actual = actual->siguiente;
            continue;
        }

        // Caso 2: si son del mismo tipo, ordenamos por hora de llegada
        if (aficionado->esSocio() == actual->dato->esSocio() &&
            actual->dato->getTiempoLlegada() <= aficionado->getTiempoLlegada())
        {
            anterior = actual;
            actual = actual->siguiente;
            continue;
        }

        // Caso 3: encontramos la posición donde insertar
        break;
    }

    // Inserción normal
    if (anterior == nullptr)
    {
        nuevo->siguiente = primero;
        primero = nuevo;
    }
    else
    {
        nuevo->siguiente = actual;
        anterior->siguiente = nuevo;
    }

    longitud++;
}


void Lista::mostrar()
{
    if (estaVacia())
    {
        cout << "La lista está vacía." << endl;
        return;
    }

    pnodoLista aux = primero;
    cout << "\nOrden de entrada al estadio:\n";
    while (aux)
    {
        aux->dato->mostrar();
        aux = aux->siguiente;
    }
    cout << endl;
}

Aficionado* Lista::getPrimero()
{
    if (estaVacia())
        return nullptr;
    return primero->dato;
}

Aficionado* Lista::getUltimo()
{
    if (estaVacia())
        return nullptr;

    pnodoLista aux = primero;
    while (aux->siguiente)
        aux = aux->siguiente;

    return aux->dato;
}

Aficionado* Lista::getPrimerSocio()
{
    pnodoLista aux = primero;
    while (aux)
    {
        if (aux->dato->esSocio()) 
            return aux->dato;
        aux = aux->siguiente;
    }
    return nullptr;
}

Aficionado* Lista::getPrimerSimpatizante()
{
    pnodoLista aux = primero;
    while (aux)
    {
        if (!aux->dato->esSocio()) 
            return aux->dato;
        aux = aux->siguiente;
    }
    return nullptr;
}

Lista::~Lista()
{
    pnodoLista aux;
    while (primero)
    {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
}

