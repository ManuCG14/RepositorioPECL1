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

    for(int i = 0; i < 10; ++i) {
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
    while(pilaAficionados.getLongitud() > 0) {
        Aficionado* aficionado = pilaAficionados.extraer();
        delete aficionado;
    }
    cout << "Pila vaciada correctamente.\n";
}

// D) Encolar aficionados en las colas según su tipo

void Gestor::encolarAficionados()
{
    if(pilaAficionados.getLongitud() == 0) {
        cout << "\nNo hay aficionados en la pila.\n";
        return;
    }

    cout << "\nEncolando aficionados...\n";
    while(pilaAficionados.getLongitud() > 0) {
        Aficionado* aficionado = pilaAficionados.extraer();
        if(aficionado->esSocio())
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

    while(!colaSocios.estaVacia()) {
        delete colaSocios.eliminar();
    }
    while(!colaSimpatizantes.estaVacia()) {
        delete colaSimpatizantes.eliminar();
    }

    cout << "Colas vaciadas correctamente.\n";
}

// H) Pasar aficionados de las colas a la lista (ordenados)

void Gestor::enlistarAficionados()
{
    cout << "\nSimulando la entrada de los aficionados al estadio...\n";

    // 1️⃣ Primero entran los socios, en orden de llegada
    while(!colaSocios.estaVacia()) {
        Aficionado* socio = colaSocios.eliminar();
        listaAcceso.insertarOrdenado(socio);
    }

    // 2️⃣ Luego entran los simpatizantes, también ordenados
    while(!colaSimpatizantes.estaVacia()) {
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

    if(listaAcceso.estaVacia()) {
        cout << "La lista está vacía. Usa la opción H primero.\n";
        return;
    }

    Aficionado* primero = listaAcceso.getPrimero();
    Aficionado* ultimo = listaAcceso.getUltimo();
    Aficionado* primerSocio = listaAcceso.getPrimerSocio();
    Aficionado* primerSimpatizante = listaAcceso.getPrimerSimpatizante();

    cout << "\nPrimer aficionado en acceder:\n";
    if(primero)
        primero->mostrar();

    cout << "\nÚltimo aficionado en acceder:\n";
    if(ultimo)
        ultimo->mostrar();

    cout << "\nPrimer socio en acceder:\n";
    if(primerSocio)
        primerSocio->mostrar();

    cout << "\nPrimer simpatizante en acceder:\n";
    if(primerSimpatizante)
        primerSimpatizante->mostrar();
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
// K) Crear y dibujar el ABB en consola.
void Gestor::crearYDibujarABB()
{
    if(listaAcceso.getLongitud() == 0) {
        std::cout << "La lista de acceso está vacía. Use la opción H primero.\n";
        return;
    }

    std::cout << "\nCreando ABB a partir de la lista...\n";
    abbAficionados.crearABB(listaAcceso);

    std::cout << "\nDibujando el ABB:\n";
    abbAficionados.dibujarEnConsola();
}

// L) Mostrar los datos de todos los socios ordenados por sus IDs de menor a mayor.
void Gestor::mostrarSociosABB()
{
    if(abbAficionados.getLongitud() == 0) {
        std::cout << "El ABB está vacío. Use la opción K primero.\n";
        return;
    }
    abbAficionados.mostrarSocios();
}

// M) Mostrar los datos de todos los simpatizantes ordenados por sus IDs de menor a mayor.
void Gestor::mostrarSimpatizantesABB()
{
    if(abbAficionados.getLongitud() == 0) {
        std::cout << "El ABB está vacío. Use la opción K primero.\n";
        return;
    }
    abbAficionados.mostrarSimpatizantes();
}

// N) Mostrar los datos de todos los Aficionados recorriendo el arbol en inorden.
void Gestor::recorrerInordenABB()
{
    if(abbAficionados.getLongitud() == 0) {
        std::cout << "El ABB está vacío. Use la opción K primero.\n";
        return;
    }
    abbAficionados.recorrerInorden();
}

// O) Buscar en el ABB los 4 aficionados clave
void Gestor::buscarAficionadosABB()
{
    std::cout << "\nBuscando aficionados en el ABB (Opción O)...\n";

    if(abbAficionados.getLongitud() == 0) {
        std::cout << "El ABB está vacío. Use la opción K primero.\n";
        return;
    }

    // El orden de acceso sigue siendo el de la lista, pero la búsqueda en el ABB se realiza por ID.
    // Usaremos los métodos del ABB que encuentran los nodos con menor/mayor ID dentro de cada subárbol.

    Aficionado* primero = abbAficionados.getPrimerAficionado();              // Socio con menor ID
    Aficionado* ultimoSocio = abbAficionados.getUltimoSocio();               // Socio con mayor ID
    Aficionado* primerSimpatizante = abbAficionados.getPrimerSimpatizante(); // Simpatizante con menor ID
    Aficionado* ultimo = abbAficionados.getUltimoAficionado();               // Simpatizante con mayor ID

    std::cout << "\nSocio con menor ID (equivalente al primer socio por ID):\n";
    if(primero)
        primero->mostrar();

    std::cout << "\nSocio con mayor ID (equivalente al último socio por ID):\n";
    if(ultimoSocio)
        ultimoSocio->mostrar();

    std::cout << "\nSimpatizante con menor ID (equivalente al primer simpatizante por ID):\n";
    if(primerSimpatizante)
        primerSimpatizante->mostrar();

    std::cout << "\nSimpatizante con mayor ID (equivalente al último aficionado por ID):\n";
    if(ultimo)
        ultimo->mostrar();
}

// P) Mostrar el numero de aficionados en el ABB cuyos ID's son pares.
void Gestor::contarIdParesABB()
{
    if(abbAficionados.getLongitud() == 0) {
        std::cout << "El ABB está vacío. Use la opción K primero.\n";
        return;
    }
    int pares = abbAficionados.contarIdPares();
    std::cout << "\nNúmero de aficionados con ID par (Socios) en el ABB: " << pares << ".\n";
}

// Q) Mostrar los aficionados que se encuentran almacenados en un nodo hoja.
void Gestor::mostrarHojasABB()
{
    if(abbAficionados.getLongitud() == 0) {
        std::cout << "El ABB está vacío. Use la opción K primero.\n";
        return;
    }
    abbAficionados.mostrarHojas();
}

// R) Eliminar un aficionado indicado por su ID.
void Gestor::eliminarAficionadoABB()
{
    if(abbAficionados.getLongitud() == 0) {
        std::cout << "El ABB está vacío. Use la opción K primero.\n";
        return;
    }

    int id_a_eliminar;
    std::cout << "\n--- ELIMINACIÓN DE AFICIONADO (Opción R) ---\n";
    std::cout << "Introduzca el ID del aficionado a eliminar: ";
    std::cin >> id_a_eliminar;

    std::cout << "\nABB ANTES de la eliminación:\n";
    abbAficionados.dibujarEnConsola();

    abbAficionados.eliminarAficionado(id_a_eliminar);

    std::cout << "\nABB DESPUÉS de la eliminación:\n";
    abbAficionados.dibujarEnConsola();
}

// Métodos auxiliares para el contador del menú

int Gestor::AficionadosEnPila() { return pilaAficionados.getLongitud(); }
int Gestor::SociosEnCola() { return colaSocios.getLongitud(); }
int Gestor::SimpatizantesEnCola() { return colaSimpatizantes.getLongitud(); }
int Gestor::AficionadosEnLista() { return listaAcceso.getLongitud(); }
int Gestor::AficionadosEnArbol() { return abbAficionados.getLongitud(); }