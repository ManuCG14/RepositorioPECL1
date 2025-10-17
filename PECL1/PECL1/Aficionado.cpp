#include "Aficionado.hpp"


Aficionado::Aficionado(int id) {
    this->id = id;
    this->hora = rand() % 60;      
    this->socio = (id % 2 == 0);  
}

Aficionado::~Aficionado() {}

void Aficionado::mostrarInfo() const {
    std::cout << "Tipo: " << (socio ? "Socio" : "Simpatizante")
              << " | Hora de llegada: 18:" << (hora < 10 ? "0" : "") << hora
              << " | ID: " << id
              << std::endl;
}
