#include "Gestor.hpp"
#include <iostream>
#include <cstdlib> // Para toupper y system("cls")

int main(int argc, char** argv)
{
	Gestor gestor; 
	char opcion;

	do {

		std::cout << "\n\t--------------------------------------------------------------"
				"--------\n";
		std::cout << "\tAficionados en la pila -> " << gestor.AficionadosEnPila()
			 << "\n\tAficionados en las colas:\n \t\tSocios-> " << gestor.SociosEnCola() << "\tSimpatizantes-> "
			 << gestor.SimpatizantesEnCola()
			 << " \n\tAficionados en la lista -> " << gestor.AficionadosEnLista()
			 << "\n\tAficionados en el arbol -> " << gestor.AficionadosEnArbol()
			 << "\n";
		std::cout << "\t----------------------------------------------------------------"
				"------\n\n";

		std::cout << "\tA. Generar 10 Aficionados de forma aleatoria y almacenarlos en la Pila.\n";
		std::cout << "\tB. Consultar todos los Aficionados generados en la Pila.\n";
		std::cout << "\tC. Borrar los Aficionados generados en la pila.\n";
		std::cout << "\tD. Simular llegada de los Aficionados en las colas.\n";
		std::cout << "\tE. Consultar los Aficionados en las cola de socios.\n";
		std::cout << "\tF. Consultar los Aficionados en la cola de simpatizantes.\n";
		std::cout << "\tG. Borrar todos los Aficionados de las colas.\n";
		std::cout << "\tH. Simular la entrada de los Aficionados a la lista.\n";
		std::cout << "\tI. Buscar en la lista el primer Aficionado, el ultimo socio, el primer simpatizante y el ultimo Aficionado que acceden al estadio.\n";
		std::cout << "\tJ. Reiniciar el programa.\n";
		std::cout << "\tK. Crear y dibujar el ABB en consola.\n";
		std::cout << "\tL. Mostrar los datos de todos los socios ordenados por sus IDs de menor a mayor.\n";
		std::cout << "\tM. Mostrar los datos de todos los simpatizantes ordenados por sus IDs de menor a mayor.\n";
		std::cout << "\tN. Mostrar los datos de todos los Aficionados recorriendo el arbol en inorden.\n";
		std::cout << "\tO. Buscar en el ABB el primer Aficionado, el ultimo socio, el primer simpatizante y el ultimo Aficionado que acceden al estadio.\n";
		std::cout << "\tP. Mostrar el numero de aficionados en el ABB cuyos ID's son pares.\n";
		std::cout << "\tQ. Mostrar los aficionados que se encuentran almacenados en un nodo hoja.\n";
		std::cout << "\tR. Eliminar un aficionado indicado por su ID. Mostrar el arbol antes y despues tras la eliminacion de dicho aficionado.\n";
		std::cout << "\tS. Salir.\n\n";

		std::cout << "\tIndique la opcion deseada: ";
		std::cin >> opcion;
		opcion = toupper(opcion);
		system("cls");

		switch(opcion) {

		case 'A':
			gestor.genera10Aficionados();
			break;
		case 'B':
			gestor.muestraAficionados();
			break;
		case 'C':
			gestor.borraAficionadosPila();
			break;
		case 'D':
			gestor.encolarAficionados();
			break;
		case 'E':
			gestor.muestraSociosCola();
			break;
		case 'F':
			gestor.muestraSimpatizantesCola();
			break;
		case 'G':
			gestor.borraAficionadosColas();
			break;
		case 'H':
			gestor.enlistarAficionados();
			break;
		case 'I':
			gestor.buscarAficionados();
			break;
		case 'J':
			gestor.reiniciar();
			break;
		case 'K':
			gestor.crearYDibujarABB();
			break;
		case 'L':
			gestor.mostrarSociosABB();
			break;
		case 'M':
			gestor.mostrarSimpatizantesABB();
			break;
		case 'N':
			gestor.recorrerInordenABB();
			break;
		case 'O':
			gestor.buscarAficionadosABB();
			break;
		case 'P':
			gestor.contarIdParesABB();
			break;
		case 'Q':
			gestor.mostrarHojasABB();
			break;
		case 'R':
			gestor.eliminarAficionadoABB();
			break;
		case 'S':
			std::cout << "Saliendo del programa...\n";
			break;
		default:
			std::cout << "Opcion incorrecta!\n\n";
			break;
		}
	} while(opcion != 'S');

	return 0;
}