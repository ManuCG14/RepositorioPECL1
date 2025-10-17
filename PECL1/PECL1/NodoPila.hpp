#ifndef NODOPILA_HPP
#define NODOPILA_HPP
#include "Aficionado.hpp"
using namespace std;
class NodoPila
{
public:
	NodoPila(Aficionado afi, NodoPila* sig =NULL);
	~NodoPila();

private:
	Aficionado aficionado;
	NodoPila* siguiente;
	friend class Pila;
	friend class Aficionado;
};
typedef NodoPila* p	nodoPila;
	

#endif // NODOPILA_HPP
