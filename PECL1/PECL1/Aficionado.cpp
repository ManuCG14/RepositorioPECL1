#include "Aficionado.hpp"


Aficionado::Aficionado(int id) {

    this->id = id;
    this->hora = rand() % 60;      
    this->socio = (id % 2 == 0);  
}

Aficionado::~Aficionado() {}

void Aficionado::mostrarInfo() const {
    cout << "ID: " << id
         << ", Hora: " << hora
         << ", Socio: " << (socio ? "Si" : "No")
         << endl;
}
