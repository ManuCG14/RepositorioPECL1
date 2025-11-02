#include "Gestor.hpp"
using namespace std;

Gestor::Gestor()
{
    srand(time(0));
    bloqueActual = 0;
}

// Consultas
int Gestor::AficionadosEnPila() const { return pila.getlongitud(); }
int Gestor::SociosEnCola() const { return colaSocios.getLongitud(); }
int Gestor::SimpatizantesEnCola() const { return colaSimpatizantes.getLongitud(); }
int Gestor::AficionadosEnLista() const { return lista.getLongitud(); }
// ------------------------------------------------------

// Generar 10 aficionados nuevos y apilarlos
void Gestor::genera10Aficionados()
{
    bloqueActual++;
    int inicio = (bloqueActual - 1) * 10 + 1;
    int fin = bloqueActual * 10;
    generarBloque(inicio, fin);
    cout << "\tSe han generado 10 aficionados (" << inicio << "-" << fin << ") en la pila.\n";
}

void Gestor::generarBloque(int inicio, int fin)
{
    for (int i = inicio; i <= fin; i++)
    {
        int llegada = rand() % 60;
        bool socio = (i % 2 == 0);
        Aficionado a(i, llegada, socio);
        pila.insertar(a);
    }
}

// Mostrar pila
void Gestor::muestraAficionados()
{
    pila.mostrar();
}

// Borrar pila
void Gestor::borraAficionadosPila()
{
    while (pila.getlongitud() > 0)
        pila.extraer();
    cout << "\tPila vaciada correctamente.\n";
}

// Pasar aficionados de pila a colas
void Gestor::encolarAficionados()
{
    while (pila.getlongitud() > 0)
    {
        Aficionado a = pila.extraer();
        if (a.esSocio())
            colaSocios.insertar(a);
        else
            colaSimpatizantes.insertar(a);
    }
    cout << "\tAficionados movidos a colas según su tipo.\n";
}

// Mostrar colas
void Gestor::muestraSociosCola() { colaSocios.mostrar(); }
void Gestor::muestraSimpatizantesCola() { colaSimpatizantes.mostrar(); }

// Borrar colas
void Gestor::borraAficionadosColas()
{
    while (!colaSocios.estaVacia()) colaSocios.eliminar();
    while (!colaSimpatizantes.estaVacia()) colaSimpatizantes.eliminar();
    cout << "\tColas vaciadas correctamente.\n";
}

// Pasar aficionados de colas a lista (ordenada por hora de llegada)
void Gestor::enlistarAficionados()
{
    while (!colaSocios.estaVacia())
    {
        Aficionado a = colaSocios.eliminar();
        lista.insertarOrdenado(new Aficionado(a));
    }
    while (!colaSimpatizantes.estaVacia())
    {
        Aficionado a = colaSimpatizantes.eliminar();
        lista.insertarOrdenado(new Aficionado(a));
    }
    cout << "\tLista generada y ordenada por hora de llegada.\n";
    lista.mostrar();
}

// Buscar aficionados especiales
void Gestor::buscarAficionados()
{
    Aficionado* primero = lista.getPrimero();
    Aficionado* ultimo = lista.getUltimo();
    Aficionado* primerSocio = lista.getPrimerSocio();
    Aficionado* primerSimpatizante = lista.getPrimerSimpatizante();

    cout << "\n\t-- Resultados de búsqueda en lista --\n";
    if (primero)
    {
        cout << "\tPrimer aficionado en acceder:\n\t";
        primero->mostrar();
    }
    if (primerSocio)
    {
        cout << "\tÚltimo socio en acceder:\n\t";
        primerSocio->mostrar();
    }
    if (primerSimpatizante)
    {
        cout << "\tPrimer simpatizante en acceder:\n\t";
        primerSimpatizante->mostrar();
    }
    if (ultimo)
    {
        cout << "\tÚltimo aficionado en acceder:\n\t";
        ultimo->mostrar();
    }
}

// Reiniciar gestor
void Gestor::reiniciar()
{
    pila = Pila();
    colaSocios = Cola();
    colaSimpatizantes = Cola();
    lista = Lista();
    bloqueActual = 0;
    cout << "\tSistema reiniciado.\n";
}
