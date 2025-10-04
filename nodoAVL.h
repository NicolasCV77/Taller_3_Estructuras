#ifndef NODO_AVL
#define NODO_AVL

// Clase template para un nodo de árbol AVL.
template <class T>
class nodoAVL {
    private:
        T dato;
        int altura;
        nodoAVL<T> *izq;
        nodoAVL<T> *der;

    public:
        nodoAVL(T val);
        T obtenerDato();
        int obtenerAltura();
        nodoAVL<T> *obtenerIzq();
        nodoAVL<T> *obtenerDer();
        void fijarDato(T val); 
        void fijarAltura(int h);
        void fijarIzq(nodoAVL<T> *nodo);
        void fijarDer(nodoAVL<T> *nodo);

};

// Implementación de la clase nodoAVL.
#include "nodoAVL.hxx"

#endif
