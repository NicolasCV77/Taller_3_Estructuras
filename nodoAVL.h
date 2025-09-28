#ifndef NODOAVL_H
#define NODOAVL_H

template <class T>
class nodoAVL {
private:
    T dato;
    nodoAVL<T>* izq;
    nodoAVL<T>* der;
    int altura;

public:
    nodoAVL(T val);

    T obtenerDato() const;
    void fijarDato(T val);

    nodoAVL<T>* obtenerIzq() const;
    nodoAVL<T>* obtenerDer() const;

    void fijarIzq(nodoAVL<T>* nodo);
    void fijarDer(nodoAVL<T>* nodo);

    int obtenerAltura() const;
    void fijarAltura(int h);
};

#include "nodoAVL.hxx"

#endif
