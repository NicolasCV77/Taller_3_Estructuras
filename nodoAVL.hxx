#include "nodoAVL.h" 

template <class T>
nodoAVL<T>::nodoAVL(T val) : dato(val), izq(nullptr), der(nullptr), altura(1) {}

template <class T>
T nodoAVL<T>::obtenerDato() { 
    return dato;
}

template <class T>
int nodoAVL<T>::obtenerAltura() { 
    return altura;
}

template <class T>
nodoAVL<T>* nodoAVL<T>::obtenerIzq() { 
    return izq;
}

template <class T>
nodoAVL<T>* nodoAVL<T>::obtenerDer() { 
    return der;
}

template <class T>
void nodoAVL<T>::fijarDato(T val) { 
    dato = val;
}

template <class T>
void nodoAVL<T>::fijarAltura(int h) { 
    altura = h;
}

template <class T>
void nodoAVL<T>::fijarIzq(nodoAVL<T> *nodo) { 
    izq = nodo;
}

template <class T>
void nodoAVL<T>::fijarDer(nodoAVL<T> *nodo) { 
    der = nodo;
}
