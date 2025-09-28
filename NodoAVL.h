#ifndef NODOAVL_H
#define NODOAVL_H

template <class T>
class NodoAVL {
private:
    T dato;
    NodoAVL<T>* izq;
    NodoAVL<T>* der;
    int altura;

public:
    NodoAVL(T val);

    T obtenerDato();
    void fijarDato(T val);

    NodoAVL<T>* obtenerIzq();
    NodoAVL<T>* obtenerDer();

    void fijarIzq(NodoAVL<T>* nodo);
    void fijarDer(NodoAVL<T>* nodo);

    int obtenerAltura();
    void fijarAltura(int h);
};

#include "NodoAVL.hxx"  // 👈 Se incluye la implementación

#endif
