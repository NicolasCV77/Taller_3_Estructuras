#include "arbolRN.h"

template <typename T>
arbolRN<T>::arbolRN() {
    // Constructor vacío.
}

template <typename T>
void arbolRN<T>::insert(T &v) {
    s.insert(v);
}

template <typename T>
void arbolRN<T>::erase(T &v) {
    s.erase(v);
}

template <typename T>
void arbolRN<T>::inordenEnLista(list<T> &out) {
    typename set<T>::iterator it = s.begin();
    while (it != s.end()) {
        out.push_back(*it);
        it++;
    }
}

template <typename T>
int arbolRN<T>::size() {
    return s.size();
}