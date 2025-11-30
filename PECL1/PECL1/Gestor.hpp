#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Aficionado.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include "Pila.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Gestor
{
public:
    Gestor();

    // Parte 1 del guion
    void genera10Aficionados();      // A
    void muestraAficionados();       // B
    void borraAficionadosPila();     // C
    void encolarAficionados();       // D
    void muestraSociosCola();        // E
    void muestraSimpatizantesCola(); // F
    void borraAficionadosColas();    // G
    void enlistarAficionados();      // H
    void buscarAficionados();        // I
    void reiniciar();                // J
    void crearYDibujarABB();         // K
    void mostrarSociosABB();         // L
    void mostrarSimpatizantesABB();  // M
    void recorrerInordenABB();       // N
    void buscarAficionadosABB();     // O
    void contarIdParesABB();         // P
    void mostrarHojasABB();          // Q
    void eliminarAficionadoABB();    // R

    
    int AficionadosEnPila();
    int SociosEnCola();
    int SimpatizantesEnCola();
    int AficionadosEnLista();
	int AficionadosEnArbol();

private:
    Pila pilaAficionados;
    Cola colaSocios;
    Cola colaSimpatizantes;
    Lista listaAcceso;
    int idInicio;
};

#endif // GESTOR_HPP
