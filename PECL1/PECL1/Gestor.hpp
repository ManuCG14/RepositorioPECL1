#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
class Gestor
{
public:
	Gestor();
	~Gestor();
	// Contadores para el menú principal
    int AficionadosEnPila() const;
    int SociosEnCola() const;
    int SimpatizantesEnCola() const;
    int AficionadosEnLista() const;
    
    // Opción A: Generar 10 Aficionados
    void genera10Aficionados();
    
    // Opción B: Mostrar Pila
    void muestraAficionadosPila() const;
    
    // Opción C: Borrar Pila
    void borraAficionadosPila();
    
    // Opción D: Pila -> Colas
    void encolarAficionados();
    
    // Opción E: Mostrar Cola Socios
    void muestraSociosCola() const;
    
    // Opción F: Mostrar Cola Simpatizantes
    void muestraSimpatizantesCola() const;
    
    // Opción G: Borrar Colas
    void borraAficionadosColas();
    
    // Opción H: Colas -> Lista Ordenada
    void enlistarAficionados();
    
    // Opción I: Búsqueda en Lista
    void buscarAficionados() const;

    // Opción J: Reiniciar el programa
    void reiniciar();

private:
    Pila pilaAficionados;
    Cola colaSocios;
    Cola colaSimpatizantes;
    Lista listaAcceso;
    
    // Variable para controlar el rango de IDs (1-10, 11-20, etc.)
    int contadorID;
};

#endif // GESTOR_HPP
