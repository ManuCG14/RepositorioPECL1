#include "NodoPila.hpp"

NodoPila::NodoPila(Aficionado afi, NodoPila* sig)
{
    aficionado = afi;
    siguiente = sig;
}

NodoPila::~NodoPila() {}
