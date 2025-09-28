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
        void insert(T &v);
        void erase(T &v);
        void inordenEnLista(list<T> &out);
        int size();

};

// Incluimos la implementación.
#include "arbolRN.hxx"

#endif
