#ifndef GESTOR_HPP
#define GESTOR_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Aficionado.hpp"
#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
using namespace std;

class Gestor
{
public:
    Gestor();

    // Parte 1 del guion
    void genera10Aficionados();     // A
    void muestraAficionados();      // B
    void borraAficionadosPila();    // C
    void encolarAficionados();      // D
    void muestraSociosCola();       // E
    void muestraSimpatizantesCola();// F
    void borraAficionadosColas();   // G
    void enlistarAficionados();     // H
    void buscarAficionados();       // I
    void reiniciar();               // J

    // Para mostrar contadores en el menú del profesor
    int AficionadosEnPila();
    int SociosEnCola();
    int SimpatizantesEnCola();
    int AficionadosEnLista();

private:
    Pila pilaAficionados;
    Cola colaSocios;
    Cola colaSimpatizantes;
    Lista listaAcceso;
    int idInicio;
};

#endif // GESTOR_HPP

