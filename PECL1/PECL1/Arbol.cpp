#include "Arbol.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define pnodoAbb pnodoArbol

Arbol::Arbol()
{
    raiz = nullptr;
    longitud = 0;
}

Arbol::~Arbol()
{
    if(raiz) {
        _destruir(raiz);
    }
}

void Arbol::_destruir(pnodoArbol nodo)
{
    if(nodo) {
        _destruir(nodo->izquierdo);
        _destruir(nodo->derecho);

        if(nodo->dato) {
            delete nodo->dato;
        }
        delete nodo;
    }
}

int Arbol::getLongitud() { return (longitud > 0) ? longitud - 1 : 0; }

// --- Operación K: Crear e Insertar ---

void Arbol::_insertar(pnodoArbol& nodo, Aficionado* aficionado)
{
    if(nodo == nullptr) {
        nodo = new NodoArbol(aficionado);
        longitud++;
        return;
    }

    if(aficionado->getId() < nodo->dato->getId()) {
        _insertar(nodo->izquierdo, aficionado);
    } else if(aficionado->getId() > nodo->dato->getId()) {
        _insertar(nodo->derecho, aficionado);
    }
}

void Arbol::crearABB(Lista& lista)
{
    if(lista.estaVacia()) {
        std::cout << "La lista está vacía, no se puede crear el ABB.\n";
        return;
    }

    Aficionado* ficticio = new Aficionado(0);
    ficticio->setSocio(true);

    if(raiz) {
        _destruir(raiz);
        raiz = nullptr;
        longitud = 0;
    }

    raiz = new NodoArbol(ficticio);
    longitud = 1;

    pnodoLista aux = lista.primero;

    while(aux) {
        Aficionado* aficionado = aux->dato;

        if(aficionado->esSocio()) {
            _insertar(raiz->izquierdo, aficionado);
        } else {
            _insertar(raiz->derecho, aficionado);
        }
        aux = aux->siguiente;
    }
}

// Auxiliar para dibujar
void Arbol::dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int p, char linkChar)
{
    if(!nodo)
        return;

    int h = output.size();
    string SP = " ";

    // Obtener el ID para el dibujo
    int id_a_mostrar = nodo->dato ? nodo->dato->getId() : -1;

    if(p < 0) {
        string extra(-p, ' ');
        for(string& s : output) if(!s.empty()) s = extra + s;
        for(string& s : linkAbove) if(!s.empty()) s = extra + s;
	}
    if(nivel < h - 1) p = max(p, (int)output[nivel + 1].size());
    if(nivel > 0) p = max(p, (int)output[nivel - 1].size());
    p = max(p, (int)output[nivel].size());

    if(nodo->izquierdo){
		int izq_id = nodo->izquierdo->dato ? nodo->izquierdo->dato->getId() : -1;
        string izqdato = SP + to_string(izq_id) + SP;
        dibujarNodo(output, linkAbove, nodo->izquierdo, nivel + 1, p - izqdato.size(), 'L');
        p = max(p, (int)output[nivel + 1].size());
		}

    int space = p - output[nivel].size();
    if(space > 0) output[nivel] += string(space, ' ');
	string nododato = SP + to_string(id_a_mostrar) + SP;
	output[nivel] += nododato;

	space = p + SP.size() - linkAbove[nivel].size();
    if(space > 0) linkAbove[nivel] += string(space, ' ');
    linkAbove[nivel] += linkChar;

    if(nodo->derecho)
		dibujarNodo(output, linkAbove, nodo->derecho, nivel + 1, output[nivel].size(), 'R');
}

int Arbol::altura(pnodoAbb nodo)
{
    if(!nodo)
        return 0;
    return 1 + max(altura(nodo->izquierdo), altura(nodo->derecho));
}

void Arbol::dibujar()
{
    if(raiz == nullptr) {
        cout << "El ABB está vacío.\n";
        return;
    }
    int h = altura(raiz);
    vector<string> output(h), linkAbove(h);
    dibujarNodo(output, linkAbove, raiz, 0, 5, ' ');

    for(int i = 1; i < h; i++) {
        for(int j = 0; j < linkAbove[i].size(); j++) {
            if(linkAbove[i][j] != ' ') {
                int size = output[i - 1].size();
                if(size < j + 1)
                    output[i - 1] += string(j + 1 - size, ' ');
                int jj = j;
                if(linkAbove[i][j] == 'L') {
                    while(output[i - 1][jj] == ' ')
                        jj++;
                    for(int k = j + 1; k < jj - 1; k++)
                        output[i - 1][k] = '_';
                } else if(linkAbove[i][j] == 'R') {
                    while(output[i - 1][jj] == ' ')
                        jj--;
                    for(int k = j - 1; k > jj + 1; k--)
                        output[i - 1][k] = '_';
                }
                linkAbove[i][j] = '|';
            }
        }
    }

    cout << '\n' << '\n';
    for(int i = 0; i < h; i++) {
        if(i)
            cout << linkAbove[i] << '\n';
        cout << output[i] << '\n';
    }
    cout << '\n' << '\n';
}

void Arbol::dibujarEnConsola() { dibujar(); }

// --- Recorridos y Consultas (Adaptación de pintar) ---

void Arbol::_inorden(pnodoArbol nodo, bool soloSocios, bool soloSimpatizantes)
{
    if(nodo == nullptr)
        return;

    _inorden(nodo->izquierdo, soloSocios, soloSimpatizantes);

    if(nodo->dato && nodo->dato->getId() != 0) {
        bool esSocio = nodo->dato->esSocio();

        if((soloSocios && esSocio) || (soloSimpatizantes && !esSocio) || (!soloSocios && !soloSimpatizantes)) {
            nodo->dato->mostrar();
        }
    }

    _inorden(nodo->derecho, soloSocios, soloSimpatizantes);
}

void Arbol::mostrarSocios()
{
    std::cout << "\nSocios ordenados por ID (menor a mayor):\n";
    // Optimizamos recorriendo solo el subárbol izquierdo (Socios)
    _inorden(raiz->izquierdo, true, false);
}

void Arbol::mostrarSimpatizantes()
{
    std::cout << "\nSimpatizantes ordenados por ID (menor a mayor):\n";
    // Optimizamos recorriendo solo el subárbol derecho (Simpatizantes)
    _inorden(raiz->derecho, false, true);
}

void Arbol::recorrerInorden()
{
    std::cout << "\nAficionados en Inorden (ordenados por ID):\n";
    _inorden(raiz, false, false);
}

// --- Operaciones O: Búsqueda de Extremos (por ID) ---

pnodoArbol Arbol::_encontrarMinimo(pnodoArbol nodo)
{
    pnodoArbol actual = nodo;
    while(actual && actual->izquierdo != nullptr) {
        actual = actual->izquierdo;
    }
    return actual;
}

Aficionado* Arbol::getPrimerAficionado()
{
    if(raiz == nullptr || raiz->izquierdo == nullptr)
        return nullptr;
    pnodoArbol min_nodo = _encontrarMinimo(raiz->izquierdo);
    return min_nodo->dato;
}

Aficionado* Arbol::getUltimoSocio()
{
    if(raiz == nullptr || raiz->izquierdo == nullptr)
        return nullptr;
    pnodoArbol actual = raiz->izquierdo;
    while(actual && actual->derecho != nullptr) {
        actual = actual->derecho;
    }
    return actual->dato;
}

Aficionado* Arbol::getPrimerSimpatizante()
{
    if(raiz == nullptr || raiz->derecho == nullptr)
        return nullptr;
    pnodoArbol min_nodo = _encontrarMinimo(raiz->derecho);
    return min_nodo->dato;
}

Aficionado* Arbol::getUltimoAficionado()
{
    if(raiz == nullptr || raiz->derecho == nullptr)
        return nullptr;
    pnodoArbol actual = raiz->derecho;
    while(actual && actual->derecho != nullptr) {
        actual = actual->derecho;
    }
    return actual->dato;
}

// --- Operación P: Contar IDs Pares ---

void Arbol::_contarIdPares(pnodoArbol nodo, int& contador)
{
    if(nodo == nullptr)
        return;

    if(nodo->dato && nodo->dato->getId() != 0 && nodo->dato->getId() % 2 == 0) {
        contador++;
    }

    _contarIdPares(nodo->izquierdo, contador);
    _contarIdPares(nodo->derecho, contador);
}

int Arbol::contarIdPares()
{
    int contador = 0;
    if(raiz) {
        _contarIdPares(raiz->izquierdo, contador);
    }
    return contador;
}

// --- Operación Q: Mostrar Hojas ---

void Arbol::_mostrarHojas(pnodoArbol nodo)
{
    if(nodo == nullptr)
        return;

    if(nodo->izquierdo == nullptr && nodo->derecho == nullptr) {
        if(nodo->dato && nodo->dato->getId() != 0) {
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
    while(actual && actual->derecho != nullptr) {
        actual = actual->derecho;
    }
    return actual;
}

pnodoArbol Arbol::_eliminar(pnodoArbol nodo, int id)
{
    if(nodo == nullptr)
        return nodo;

    if(id < nodo->dato->getId()) {
        nodo->izquierdo = _eliminar(nodo->izquierdo, id);
    } else if(id > nodo->dato->getId()) {
        nodo->derecho = _eliminar(nodo->derecho, id);
    } else {
        // Caso A: Nodo con 0 o 1 hijo
        if(nodo->izquierdo == nullptr) {
            pnodoArbol temp = nodo->derecho;
            if(nodo->dato != nullptr)
                delete nodo->dato;
            delete nodo;
            longitud--;
            return temp;
        } else if(nodo->derecho == nullptr) {
            pnodoArbol temp = nodo->izquierdo;
            if(nodo->dato != nullptr)
                delete nodo->dato;
            delete nodo;
            longitud--;
            return temp;
        }

        // Caso B: Nodo con 2 hijos (Predecesor: máximo de la izquierda)
        pnodoArbol predecesor = _encontrarMaximo(nodo->izquierdo);

        // Intercambiar datos
        Aficionado* temp_dato = nodo->dato;
        nodo->dato = predecesor->dato;
        predecesor->dato = temp_dato;

        // Eliminar el predecesor
        nodo->izquierdo = _eliminar(nodo->izquierdo, predecesor->dato->getId());
    }
    return nodo;
}

void Arbol::eliminarAficionado(int id)
{
    if(raiz == nullptr)
        return;

    if(id == raiz->dato->getId()) {
        std::cout << "No se puede eliminar el aficionado ficticio (ID: 0) de la raíz.\n";
        return;
    }

    if(id % 2 == 0) {
        raiz->izquierdo = _eliminar(raiz->izquierdo, id);
    } else {
        raiz->derecho = _eliminar(raiz->derecho, id);
    }
}