#include "arbolRN.h"

template <class T>
arbolRN<T>::arbolRN() {
    // Constructor vacío.
}

template <class T>
void arbolRN<T>::insert(T &valor) {
    s.insert(valor);
}

template <class T>
void arbolRN<T>::erase(T &valor) {
    s.erase(valor);
}

template <class T>
void arbolRN<T>::inordenEnLista(list<T> &salida) {
    typename set<T>::iterator it = s.begin();
    while (it != s.end()) {
        salida.push_back(*it);
        ++it;
    }
}

template <class T>
int arbolRN<T>::size() {
    return s.size();
}