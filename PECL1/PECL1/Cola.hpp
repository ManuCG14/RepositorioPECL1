#include <iostream>
#include "NodoCola.hpp"
using namespace std;

class Cola
{
public:
	Cola();
	~Cola();
	
	void insertar(Aficionado v);
    Aficionado eliminar();
    void mostrar() const;
    Aficionado verPrimero() const;
    bool estaVacia() const;
    int getLongitud() const { return longitud; }
	
private:
	pnodoCola primero, ultimo;
	int longitud;

};
