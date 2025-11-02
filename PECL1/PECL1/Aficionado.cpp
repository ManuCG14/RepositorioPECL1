#include "Aficionado.hpp"


Aficionado::Aficionado()
{
    id = -1;
    hora = 0;
    socio = false;
}

Aficionado::Aficionado(int id)
{
    this->id = id;
    this->hora = rand() % 60;     
    this->socio = (id % 2 == 0);  
}

Aficionado::Aficionado(int id, int hora, bool socio)
{
    this->id = id;
    this->hora = hora;
    this->socio = socio;
}

// Destructor
Aficionado::~Aficionado() {}

// Getters
int Aficionado::getId() const { return id; }
int Aficionado::getHora() const { return hora; }
bool Aficionado::esSocio() const { return socio; }
int Aficionado::getTiempoLlegada() const { return hora; }

// Setters
void Aficionado::setId(int nuevoId) { id = nuevoId; }
void Aficionado::setHora(int nuevaHora) { hora = nuevaHora; }
void Aficionado::setSocio(bool nuevoSocio) { socio = nuevoSocio; }

// Mostrar información 
void Aficionado::mostrarInfo() const
{
    std::cout << "Tipo: " << (socio ? "Socio" : "Simpatizante")
              << " | Hora de llegada: 18:"<< hora
              << " | ID: " << id
              << std::endl;
}

void Aficionado::mostrar() const
{
    mostrarInfo();
}
