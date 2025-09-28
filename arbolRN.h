#ifndef ARBOL_RN
#define ARBOL_RN

#include <set>
#include <list>
#include <string>

using namespace std;

// Declaración de la clase arbolRN.
template <class T>
class arbolRN {
    private:
        set<T> s;

    public:
        arbolRN();
        void insert(T &valor);
        void erase(T &valor);
        void inordenEnLista(list<T> &salida);
        int size();

};

// Incluimos la implementación.
#include "arbolRN.hxx"

#endif
