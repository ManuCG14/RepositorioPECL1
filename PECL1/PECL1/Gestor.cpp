#include "Gestor.hpp"

Gestor::Gestor()
{
    srand(time(nullptr));
    idInicio = 1;
}


// A) Generar 10 aficionados aleatorios y guardarlos en la pila

void Gestor::genera10Aficionados()
{
    cout << "\nGenerando 10 aficionados...\n";

    for (int i = 0; i < 10; ++i)
    {
        Aficionado* nuevo = new Aficionado(idInicio + i);
        pilaAficionados.insertar(nuevo);
    }

    idInicio += 10;
    muestraAficionados();
}


// B) Mostrar aficionados en la pila

void Gestor::muestraAficionados()
{
    cout << "\nAficionados en la pila:\n";
    pilaAficionados.mostrar();
}


// C) Borrar aficionados de la pila

void Gestor::borraAficionadosPila()
{
    cout << "\nVaciando pila de aficionados...\n";
    while (pilaAficionados.getLongitud() > 0)
    {
        Aficionado* aficionado = pilaAficionados.extraer();
        delete aficionado;
    }
    cout << "Pila vaciada correctamente.\n";
}


// D) Encolar aficionados en las colas según su tipo

void Gestor::encolarAficionados()
{
    if (pilaAficionados.getLongitud() == 0)
    {
        cout << "\nNo hay aficionados en la pila.\n";
        return;
    }

    cout << "\nEncolando aficionados...\n";
    while (pilaAficionados.getLongitud() > 0)
    {
        Aficionado* aficionado = pilaAficionados.extraer();
        if (aficionado->esSocio())
            colaSocios.insertar(aficionado);
        else
            colaSimpatizantes.insertar(aficionado);
    }

    cout << "Aficionados encolados correctamente.\n";
}


// E) Mostrar cola de socios

void Gestor::muestraSociosCola()
{
    cout << "\nCola de socios:\n";
    colaSocios.mostrar();
}


// F) Mostrar cola de simpatizantes

void Gestor::muestraSimpatizantesCola()
{
    cout << "\nCola de simpatizantes:\n";
    colaSimpatizantes.mostrar();
}


// G) Borrar aficionados en las colas

void Gestor::borraAficionadosColas()
{
    cout << "\nVaciando colas de socios y simpatizantes...\n";

    while (!colaSocios.estaVacia())
    {
        delete colaSocios.eliminar();
    }
    while (!colaSimpatizantes.estaVacia())
    {
        delete colaSimpatizantes.eliminar();
    }

    cout << "Colas vaciadas correctamente.\n";
}


// H) Pasar aficionados de las colas a la lista (ordenados)

void Gestor::enlistarAficionados()
{
    cout << "\nSimulando la entrada de los aficionados al estadio...\n";

    // 1️⃣ Primero entran los socios, en orden de llegada
    while (!colaSocios.estaVacia())
    {
        Aficionado* socio = colaSocios.eliminar();
        listaAcceso.insertarOrdenado(socio);
    }

    // 2️⃣ Luego entran los simpatizantes, también ordenados
    while (!colaSimpatizantes.estaVacia())
    {
        Aficionado* simpatizante = colaSimpatizantes.eliminar();
        listaAcceso.insertarOrdenado(simpatizante);
    }

    cout << "\nOrden final de entrada al estadio:\n";
    listaAcceso.mostrar();
}



// I) Buscar primeros y últimos aficionados

void Gestor::buscarAficionados()
{
    cout << "\nBuscando aficionados en la lista...\n";

    if (listaAcceso.estaVacia())
    {
        cout << "La lista está vacía. Usa la opción H primero.\n";
        return;
    }

    Aficionado* primero = listaAcceso.getPrimero();
    Aficionado* ultimo = listaAcceso.getUltimo();
    Aficionado* primerSocio = listaAcceso.getPrimerSocio();
    Aficionado* primerSimpatizante = listaAcceso.getPrimerSimpatizante();

    cout << "\nPrimer aficionado en acceder:\n";
    if (primero) primero->mostrar();

    cout << "\nÚltimo aficionado en acceder:\n";
    if (ultimo) ultimo->mostrar();

    cout << "\nPrimer socio en acceder:\n";
    if (primerSocio) primerSocio->mostrar();

    cout << "\nPrimer simpatizante en acceder:\n";
    if (primerSimpatizante) primerSimpatizante->mostrar();
}


// J) Reiniciar el programa

void Gestor::reiniciar()
{
    cout << "\nReiniciando programa...\n";
    borraAficionadosPila();
    borraAficionadosColas();
    listaAcceso = Lista();
    idInicio = 1;
    cout << "Programa reiniciado.\n";
}


// Métodos auxiliares para el contador del menú

int Gestor::AficionadosEnPila()  { return pilaAficionados.getLongitud(); }
int Gestor::SociosEnCola()  { return colaSocios.getLongitud(); }
int Gestor::SimpatizantesEnCola()  { return colaSimpatizantes.getLongitud(); }
int Gestor::AficionadosEnLista()  { return listaAcceso.getLongitud(); }
