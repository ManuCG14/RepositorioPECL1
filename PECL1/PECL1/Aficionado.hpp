#ifndef AFICIONADO_HPP
#define AFICIONADO_HPP

#include <iostream>
#include <cstdlib>

class Aficionado
{
private:
    int id;     
    int hora;   
    bool socio; 

public:
    // Constructores y destructor
    Aficionado();                                
    Aficionado(int id);                          
    Aficionado(int id, int hora, bool socio);    
    ~Aficionado();                               

    // Getters
    int getId() const;
    int getHora() const;
    bool esSocio() const;
    int getTiempoLlegada() const; 

    // Setters
    void setId(int nuevoId);
    void setHora(int nuevaHora);
    void setSocio(bool nuevoSocio);

    // Mostrar información
    void mostrarInfo() const;
    void mostrar() const; 
};

#endif // AFICIONADO_HPP
