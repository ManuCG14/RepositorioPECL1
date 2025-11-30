#include "Aficionado.hpp"

Aficionado::Aficionado(int id)
{
	this->id = id;
	this->tiempoLlegada = rand() % 60; //genera un tiempo de llegada random entre 0 y 59, ambos incluídos.
	this->socio = (this->id % 2 == 0);
}

int Aficionado::getId()
{
	return this->id;
}
bool Aficionado::esSocio()
{
	return this->socio; //1 es socio, 0 es simpatizante
}
int Aficionado::getTiempoLlegada()
{
	return this->tiempoLlegada;
}

void Aficionado::setId(int id)
{
	this->id = id;
}

void Aficionado::setTiempoLlegada(int tiempoLlegada)
{
	this->tiempoLlegada = tiempoLlegada;
}
void Aficionado::setSocio(bool s) // 
{
    this->socio = s;
}

void Aficionado::mostrar()
{
    cout << "ID: " << setw(3) << id
         << " | Llegada: " << setw(2) << tiempoLlegada << "min"
         << " | Tipo: " << (socio ? "Socio" : "Simpatizante")
         << endl;
}

Aficionado::~Aficionado()
{
}
