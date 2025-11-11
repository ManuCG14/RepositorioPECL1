#ifndef AFICIONADO_HPP
#define AFICIONADO_HPP
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;


class Aficionado
{
private:
	int id;             // identificador único
	int tiempoLlegada;  // minutos desde las 18:00 hasta las 18:59
	bool socio;       // true = socio, false = simpatizante
	
public:
	Aficionado(int id);
		
		int getId();
		int getTiempoLlegada();
		bool esSocio();

		void setId(int id);
		void setTiempoLlegada(int h);
		void mostrar();
		
		void generarId();
	
	~Aficionado();

};

#endif // AFICIONADO_HPP
