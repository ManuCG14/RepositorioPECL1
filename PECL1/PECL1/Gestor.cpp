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
	std::cout << "Se han genrado 10 aficionados"
}
void Gestor::borraAficionadosPila(){
	
}