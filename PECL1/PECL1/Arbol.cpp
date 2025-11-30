#include "Arbol.hpp"
#include <iomanip>

// Constructor y Destructor
Arbol::Arbol()
{
	raiz = nullptr;
	longitud = 0;
}

Arbol::~Arbol()
{
	if (raiz) {
        _destruir(raiz);
    }
}

void Arbol::_destruir(pnodoArbol nodo)
{
	if (nodo) {
		_destruir(nodo->izquierdo);
		_destruir(nodo->derecho);
		
		if (nodo->dato) {
			delete nodo->dato; // Libera el Aficionado*
		}
		delete nodo; // Libera el nodo
	}
}

int Arbol::getLongitud()
{
	// Descontamos el aficionado ficticio
	return (longitud > 0) ? longitud - 1 : 0; 
}


// --- Operación K: Crear e Insertar ---

void Arbol::_insertar(pnodoArbol& nodo, Aficionado* aficionado)
{
	if (nodo == nullptr) {
		nodo = new NodoArbol(aficionado);
		longitud++;
		return;
	}

	// Ordenación por ID
	if (aficionado->getId() < nodo->dato->getId()) {
		_insertar(nodo->izquierdo, aficionado);
	}
	else if (aficionado->getId() > nodo->dato->getId()) {
		_insertar(nodo->derecho, aficionado);
	}
	// Si los IDs son iguales, no se inserta (ID es único)
}

void Arbol::crearABB(Lista& lista)
{
	if (lista.estaVacia()) {
		std::cout << "La lista está vacía, no se puede crear el ABB.\n";
		return;
	}

	// 1. Crear Aficionado ficticio para la raíz (Socio)
	// Asumimos ID 0 para el ficticio, que es par (Socio)
	Aficionado* ficticio = new Aficionado(0); 
	ficticio->setSocio(true);
	
	if (raiz) {
		// Destruir árbol previo antes de crear uno nuevo
		_destruir(raiz);
		raiz = nullptr;
		longitud = 0;
	}

	// Insertar el ficticio como raíz
	raiz = new NodoArbol(ficticio);
	longitud = 1;

	// 2. Insertar Socios y Simpatizantes desde la Lista
	pnodoLista aux = lista.primero;

	while (aux) {
		Aficionado* aficionado = aux->dato;
		
		// El árbol se bifurca inmediatamente después de la raíz ficticia.
		// Socios (par) van a la izquierda, Simpatizantes (impar) a la derecha.
		if (aficionado->esSocio()) {
			_insertar(raiz->izquierdo, aficionado);
		} else {
			_insertar(raiz->derecho, aficionado);
		}
		aux = aux->siguiente;
	}
}

// Dibujo simple en preorden para Opción K y R
void Arbol::_preordenDibujo(pnodoArbol nodo, int nivel, char rama)
{
    if (nodo != nullptr)
    {
        std::cout << std::setw(nivel * 4) << "" << rama << "--";
        if (nodo->dato) {
            std::cout << "ID: " << nodo->dato->getId() << " (" << (nodo->dato->esSocio() ? "Socio" : "Simpatizante") << ")\n";
        } else {
            std::cout << "ID: [Dato Nulo]\n";
        }
        
        _preordenDibujo(nodo->izquierdo, nivel + 1, 'L');
        _preordenDibujo(nodo->derecho, nivel + 1, 'R');
    }
}

void Arbol::dibujarEnConsola()
{
	if (raiz == nullptr) {
		std::cout << "El ABB está vacío.\n";
		return;
	}
	_preordenDibujo(raiz, 0, 'R');
}


// --- Operaciones L, M, N: Recorridos ---

void Arbol::_inorden(pnodoArbol nodo, bool soloSocios, bool soloSimpatizantes)
{
	if (nodo == nullptr || (soloSocios && nodo->dato && !nodo->dato->esSocio()) || (soloSimpatizantes && nodo->dato && nodo->dato->esSocio())) {
		return;
	}

	if (soloSocios && nodo == raiz) {
		_inorden(nodo->izquierdo, soloSocios, soloSimpatizantes);
		return;
	}

	if (soloSimpatizantes && nodo == raiz) {
		_inorden(nodo->derecho, soloSocios, soloSimpatizantes);
		return;
	}

	_inorden(nodo->izquierdo, soloSocios, soloSimpatizantes);
	
	// Mostrar solo si no es el nodo ficticio
	if (nodo->dato && nodo->dato->getId() != 0) {
		nodo->dato->mostrar();
	}
	
	_inorden(nodo->derecho, soloSocios, soloSimpatizantes);
}

void Arbol::mostrarSocios()
{
	std::cout << "\nSocios ordenados por ID (menor a mayor):\n";
	if (raiz && raiz->izquierdo) {
		_inorden(raiz->izquierdo, false, true); // Recorre solo el subárbol izquierdo (Socios)
	} else {
		std::cout << "No hay socios en el ABB.\n";
	}
}

void Arbol::mostrarSimpatizantes()
{
	std::cout << "\nSimpatizantes ordenados por ID (menor a mayor):\n";
	if (raiz && raiz->derecho) {
		_inorden(raiz->derecho, false, false); // Recorre solo el subárbol derecho (Simpatizantes)
	} else {
		std::cout << "No hay simpatizantes en el ABB.\n";
	}
}

void Arbol::recorrerInorden()
{
	std::cout << "\nAficionados en Inorden (ordenados por ID):\n";
	_inorden(raiz, false, false);
}


// --- Operaciones O: Búsqueda de Extremos ---

pnodoArbol Arbol::_encontrarMinimo(pnodoArbol nodo)
{
    pnodoArbol actual = nodo;
    while (actual && actual->izquierdo != nullptr) {
        actual = actual->izquierdo;
    }
    return actual;
}

Aficionado* Arbol::getPrimerAficionado() // El primer aficionado de la lista SIEMPRE es el socio con menor hora,
                                        // pero el ABB solo ordena por ID. Devolvemos el Socio con menor ID.
{
	if (raiz == nullptr || raiz->izquierdo == nullptr) return nullptr;
	pnodoArbol min_nodo = _encontrarMinimo(raiz->izquierdo);
	return min_nodo->dato;
}

Aficionado* Arbol::getUltimoSocio() // El socio con mayor ID
{
	if (raiz == nullptr || raiz->izquierdo == nullptr) return nullptr;
    pnodoArbol actual = raiz->izquierdo;
    while (actual && actual->derecho != nullptr) {
        actual = actual->derecho;
    }
    return actual->dato;
}

Aficionado* Arbol::getPrimerSimpatizante() // El simpatizante con menor ID
{
	if (raiz == nullptr || raiz->derecho == nullptr) return nullptr;
	pnodoArbol min_nodo = _encontrarMinimo(raiz->derecho);
	return min_nodo->dato;
}

Aficionado* Arbol::getUltimoAficionado() // El simpatizante con mayor ID
{
	if (raiz == nullptr || raiz->derecho == nullptr) return nullptr;
    pnodoArbol actual = raiz->derecho;
    while (actual && actual->derecho != nullptr) {
        actual = actual->derecho;
    }
    return actual->dato;
}


// --- Operación P: Contar IDs Pares ---

void Arbol::_contarIdPares(pnodoArbol nodo, int& contador)
{
	if (nodo == nullptr) return;

	if (nodo->dato && nodo->dato->getId() != 0 && nodo->dato->getId() % 2 == 0) {
		contador++;
	}

	// El recorrido preorden es eficiente para contar
	_contarIdPares(nodo->izquierdo, contador);
	_contarIdPares(nodo->derecho, contador);
}

int Arbol::contarIdPares()
{
	int contador = 0;
	if (raiz) {
		// Solo se necesita contar los nodos del subárbol izquierdo (Socios)
		// ya que solo los IDs pares son socios, y los socios están en el subárbol izquierdo.
		_contarIdPares(raiz->izquierdo, contador);
	}
	return contador;
}


// --- Operación Q: Mostrar Hojas ---

void Arbol::_mostrarHojas(pnodoArbol nodo)
{
	if (nodo == nullptr) return;

	if (nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
		// Mostrar solo si no es el nodo ficticio
		if (nodo->dato && nodo->dato->getId() != 0) {
			nodo->dato->mostrar();
		}
		return;
	}

	_mostrarHojas(nodo->izquierdo);
	_mostrarHojas(nodo->derecho);
}

void Arbol::mostrarHojas()
{
	std::cout << "\nAficionados almacenados en nodos hoja:\n";
	_mostrarHojas(raiz);
}


// --- Operación R: Eliminar (Usando Predecesor) ---

pnodoArbol Arbol::_encontrarMaximo(pnodoArbol nodo)
{
    pnodoArbol actual = nodo;
    while (actual && actual->derecho != nullptr) {
        actual = actual->derecho;
    }
    return actual;
}

pnodoArbol Arbol::_eliminar(pnodoArbol nodo, int id)
{
    if (nodo == nullptr) return nodo;

    if (id < nodo->dato->getId()) {
        nodo->izquierdo = _eliminar(nodo->izquierdo, id);
    }
    else if (id > nodo->dato->getId()) {
        nodo->derecho = _eliminar(nodo->derecho, id);
    }
    else {
        // Caso A: Nodo con 0 o 1 hijo
        if (nodo->izquierdo == nullptr) {
            pnodoArbol temp = nodo->derecho;
            if (nodo->dato != nullptr) delete nodo->dato; 
            delete nodo;
            longitud--;
            return temp;
        }
        else if (nodo->derecho == nullptr) {
            pnodoArbol temp = nodo->izquierdo;
            if (nodo->dato != nullptr) delete nodo->dato; 
            delete nodo;
            longitud--;
            return temp;
        }

        // Caso B: Nodo con 2 hijos (Usamos el predecesor: máximo de la izquierda)
        pnodoArbol predecesor = _encontrarMaximo(nodo->izquierdo);

        // Intercambiar datos (transferir puntero)
        Aficionado* temp_dato = nodo->dato;
        nodo->dato = predecesor->dato;
        predecesor->dato = temp_dato;
        
        // Eliminar el predecesor (ya tiene el dato original)
        nodo->izquierdo = _eliminar(nodo->izquierdo, predecesor->dato->getId());
    }
    return nodo;
}

void Arbol::eliminarAficionado(int id)
{
	if (raiz == nullptr) return;
	
    // La raíz ficticia no se puede eliminar (ID 0)
    if (id == raiz->dato->getId()) {
        std::cout << "No se puede eliminar el aficionado ficticio (ID: 0) de la raíz.\n";
        return;
    }

	// Como el ABB está bifurcado en la raíz ficticia:
    if (id % 2 == 0) { // Si el ID es par (es socio)
        raiz->izquierdo = _eliminar(raiz->izquierdo, id);
    } else { // Si el ID es impar (es simpatizante)
        raiz->derecho = _eliminar(raiz->derecho, id);
    }
}