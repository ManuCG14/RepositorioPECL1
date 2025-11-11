#include "NodoCola.hpp"

NodoCola::NodoCola(Aficionado* aficionado, NodoCola* sig)
{
	dato = aficionado;
	siguiente = sig;
}

NodoCola::~NodoCola()
{
}

