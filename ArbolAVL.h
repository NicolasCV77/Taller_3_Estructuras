#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include <iostream>
#include <algorithm>
#include "NodoAVL.h"

using namespace std;

template <class T>
class ArbolAVL {
private:
    NodoAVL<T>* raiz;

    // Funciones auxiliares
    int altura(NodoAVL<T>* nodo);
    int factorBalance(NodoAVL<T>* nodo);
    NodoAVL<T>* rotarDerecha(NodoAVL<T>* y);
    NodoAVL<T>* rotarIzquierda(NodoAVL<T>* x);
    NodoAVL<T>* insertarAVL(NodoAVL<T>* nodo, T val);
    NodoAVL<T>* eliminarAVL(NodoAVL<T>* nodo, T val);
    NodoAVL<T>* nodoMinimo(NodoAVL<T>* nodo);

    void preOrden(NodoAVL<T>* nodo);
    void inOrden(NodoAVL<T>* nodo);
    void postOrden(NodoAVL<T>* nodo);

public:
    ArbolAVL() : raiz(nullptr) {}

    void insertar(T val) { raiz = insertarAVL(raiz, val); }
    void eliminar(T val) { raiz = eliminarAVL(raiz, val); }

    void mostrarPreOrden() { preOrden(raiz); cout << endl; }
    void mostrarInOrden() { inOrden(raiz); cout << endl; }
    void mostrarPostOrden() { postOrden(raiz); cout << endl; }
};

#include "ArbolAVL.hxx"

#endif