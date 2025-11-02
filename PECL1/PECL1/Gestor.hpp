#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

class Gestor
{
public:
    Gestor();

    // Consultas de conteo
    int AficionadosEnPila() const;
    int SociosEnCola() const;
    int SimpatizantesEnCola() const;
    int AficionadosEnLista() const;

    // Funciones de menú
    void genera10Aficionados();
    void muestraAficionados();
    void borraAficionadosPila();
    void encolarAficionados();
    void muestraSociosCola();
    void muestraSimpatizantesCola();
    void borraAficionadosColas();
    void enlistarAficionados();
    void buscarAficionados();
    void reiniciar();

private:
    Pila pila;
    Cola colaSocios;
    Cola colaSimpatizantes;
    Lista lista;
    int bloqueActual; // controla el rango de IDs (1–10, 11–20, etc.)

    void generarBloque(int inicio, int fin);
};

#endif // GESTOR_HPP
