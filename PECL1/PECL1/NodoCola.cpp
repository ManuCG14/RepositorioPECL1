#include "NodoCola.hpp"

NodoCola::NodoCola(Aficionado v, NodoCola* sig)
{
	valor = v;
	siguiente = sig;
}

NodoCola::~NodoCola()
{
}