#include "NodoAVL.h"

// Constructor
template <class T>
NodoAVL<T>::NodoAVL(T val) : dato(val), izq(nullptr), der(nullptr), altura(1) {}

// Métodos
template <class T>
T NodoAVL<T>::obtenerDato() { return dato; }

template <class T>
void NodoAVL<T>::fijarDato(T val) { dato = val; }

template <class T>
NodoAVL<T>* NodoAVL<T>::obtenerIzq() { return izq; }

template <class T>
NodoAVL<T>* NodoAVL<T>::obtenerDer() { return der; }

template <class T>
void NodoAVL<T>::fijarIzq(NodoAVL<T>* nodo) { izq = nodo; }

template <class T>
void NodoAVL<T>::fijarDer(NodoAVL<T>* nodo) { der = nodo; }

template <class T>
int NodoAVL<T>::obtenerAltura() { return altura; }

template <class T>
void NodoAVL<T>::fijarAltura(int h) { altura = h; }

