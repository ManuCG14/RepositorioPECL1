#include "Gestor.hpp"

Gestor::Gestor()
{
    // El primer rango de IDs será 1-10.
    // Usamos 1 como inicio, se actualizará a 11 la próxima vez, etc.
    contadorID = 1;
    // Las estructuras se inicializan con sus constructores por defecto.
}

Gestor::~Gestor() {}
int Gestor::AficionadosEnPila() const { return pilaAficionados.getlongitud(); }
int Gestor::SociosEnCola() const { return colaSocios.getLongitud(); }
int Gestor::SimpatizantesEnCola() const { return colaSimpatizantes.getLongitud(); }
int Gestor::AficionadosEnLista() const { return listaAcceso.getLongitud(); }
void Gestor::genera10Aficionados()
{
    for(int i = 0; i < 10; ++i) {
        Aficionado nuevoAfi(contadorID);
    }
    pilaAficionados.insertar(nuevoAfi);
    contadorID++;
    std::cout << "Se han genrado 10 aficionados";
}
void Gestor::borraAficionadosPila()
{
    std::cout << "\nBorrando aficiondos de la pila";
    pilaAficionados.~Pila()
}
void Gestor::muestraAficionadosPila() const
{
    std::cout << "\nMostrando contenido en pila:\n";
    pilaAficionados.mostrar();
}
void Gestor::encolarAficionados()
{
    if(pilaAficionados.getlongitud() == 0) {
        std::cout << "\nNo hay suficientes aficionados para encolar";
        return;
    }
    std::cout << "\nEncolando aficionado por tipo";
    while(pilaAficionados.getlongitud() > 0) {
        Aficionado afi = pilaAficionados.extraer();
        if(afi.esSocio()) {
            colaSocios.insertar(afi);
            std::cout << "  -> Socio con ID " << afi.getId() << " encolado en cola Socios.\n";
        } else {
            colaSimpatizantes.insertar(afi);
            std::cout << "  -> Simpatizante con ID " << afi.getId() << " encolado en cola Simpatizantes.\n";
        }
    }
    std::cout << "Proceso completado. Pila vacía. Total Socios: " << colaSocios.getLongitud()
              << ", Total Simpatizantes: " << colaSimpatizantes.getLongitud() << ".\n";
}
void Gestor::muestraSociosCola() const
{
    std::cout << "\n[Opción E] Contenido de la Cola de Socios:\n";
    colaSocios.mostrar();
}
void Gestor::muestraSimpatizantesCola() const
{
    std::cout << "\n[Opción F] Contenido de la Cola de Simpatizantes:\n";
    colaSimpatizantes.mostrar();
}
void Gestor::borrarAficionaodosColas()
{
    std::cout << "\nBorrando aficionados de las Colas\n";
    while(!colaSocios.estaVacia()) {
        colaSocios.eliminar();
    }
    while(!colaSimpatizantes.estaVacia()) {
        colaSimpatizantes.eliminar();
    }
}
void Gestor::enlistarAficionados()
{
    if(colaSocios.estaVacia() && colaSimpatizantes.estaVacia()) {
        std::cout << "\nAmbas Colas están vacías. No hay aficionados para enlistar.\n";
        return;
    }
    if(!listaAcceso.estaVacia()) {
        std::cout << "\nLa lista de acceso ya contiene aficionados. Se vaciará primero.\n";
        listaAcceso.~Lista();
    }
    std::cout << "Insertando Socios en la Lista (ordenados por hora de llegada)\n";
    while(!colaSocios.estaVacia()) {
        Aficionado afi = colaSocios.eliminar();
        listaAcceso.insertarOrdenado(new Aficionado(afi.getId()));
    }
    std::cout << "Insertando Simpatizantes en la Lista (ordenados por hora de llegada)\n";
    while(!colaSimpatizantes.estaVacia()) {
        Aficionado afi = colaSimpatizantes.eliminar();
        listaAcceso.insertarOrdenado(new Aficionado(afi.getId()));
    }
    listaAcceso.mostrar();
}
void Gestor::buscarAficionados() const
{
    std::cout << "\nBúsqueda de Aficionados:\n";

    if(listaAcceso.estaVacia()) {
        std::cout << "La lista de acceso está vacía. Ejecute la Opción H primero.\n";
        return;
    }
    Aficionado* primero = listaAcceso.getPrimero();
    Aficionado* ultimoSocio = listaAcceso.getUltimoSocio();
    Aficionado* primerSimpatizante = listaAcceso.getPrimerSimpatizante();
    Aficionado* ultimo = listaAcceso.getUltimo();
    std::cout << "\n** Primer Aficionado en acceder al estadio (menor hora de llegada): **\n\t";
    if(primero)
        primero->mostrarInfo();
    else
        std::cout << "No encontrado.\n";

    std::cout << "\n** Último Socio en acceder al estadio: **\n\t";
    if(ultimoSocio)
        ultimoSocio->mostrarInfo();
    else
        std::cout << "No encontrado.\n";

    std::cout << "\n** Primer Simpatizante en acceder al estadio: **\n\t";
    if(primerSimpatizante)
        primerSimpatizante->mostrarInfo();
    else
        std::cout << "No encontrado.\n";

    std::cout << "\n** Último Aficionado en acceder al estadio (mayor hora de llegada): **\n\t";
    if(ultimo)
        ultimo->mostrarInfo();
    else
        std::cout << "No encontrado.\n";
}
void Gestor::reiniciar()
{
    std::cout << "\nReiniciando el estado del programa...\n";
    borraAficionadosPila();
    borraAficionadosColas();
    listaAcceso.~Lista();
    contadorID = 1;
    
}