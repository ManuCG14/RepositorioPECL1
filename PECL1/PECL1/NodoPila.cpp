#include "NodoPila.hpp"

NodoPila::NodoPila(Aficionado* aficionado, NodoPila* sig)
{
	dato = aficionado;
	siguiente = sig;
}

NodoPila::~NodoPila()
{
}
