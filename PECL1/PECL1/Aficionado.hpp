#ifndef AFICIONADO_HPP
#define AFICIONADO_HPP

#include <iostream>
#include <iostream>
#include <cstdlib>
using namespace std;

class Aficionado
{
private:
    int id;
    int hora;
    bool socio;

public:
    Aficionado();
    Aficionado(int id);
    ~Aficionado();

    int getId() const { return id; }
    int getHora() const { return hora; }
    bool esSocio() const { return socio; }

    void setId(int nuevoId) { id = nuevoId; }
    void setHora(int nuevaHora) { hora = nuevaHora; }
    void setSocio(bool nuevoSocio) { socio = nuevoSocio; }

    void mostrarInfo() const;
};

#endif // AFICIONADO_HPP
