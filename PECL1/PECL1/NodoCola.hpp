#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP
#include "Aficionado.hpp"
#include <iostream>
using namespace std;

class NodoCola
{
public:
	NodoCola(Aficionado* aficionado, NodoCola* sig = nullptr);
	~NodoCola();

private:
	Aficionado* dato;
	NodoCola* siguiente;
	friend class Cola;
};
typedef NodoCola* pnodoCola;

#endif // NODOCOLA_HPP

