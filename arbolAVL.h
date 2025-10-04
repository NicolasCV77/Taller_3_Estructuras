#ifndef ARBOL_AVL
#define ARBOL_AVL

#include <list> 

// Estructura del nodo del árbol AVL.
template <typename T>
struct Nodo {
    T dato;
    Nodo<T>* izq;
    Nodo<T>* der;
    int altura;

    Nodo(const T& v) : dato(v), izq(nullptr), der(nullptr), altura(1) {}
};

// Clase árbol AVL.
template <typename T>
class arbolAVL {
    private:
        Nodo<T> *raiz;
        Nodo<T> *insertarNodo(Nodo<T> *nodo, T &valor);
        int altura(Nodo<T> *nodo);
        int obtenerBalance(Nodo<T> *nodo);
        Nodo<T> *rotarDerecha(Nodo<T> *y);
        Nodo<T> *rotarIzquierda(Nodo<T> *x);
        void destruir(Nodo<T>* nodo);
        void recPreOrden(Nodo<T> *nodo, list<T> &out);
        void recInOrden(Nodo<T> *nodo, list<T> &out);
        void recPostOrden(Nodo<T> *nodo, list<T> &out);

    public:
        arbolAVL();
        ~arbolAVL();
        void insert(T &valor);
        void erase(T &valor);
        void inordenEnLista(list<T> &out);
        void preordenEnLista(list<T> &out);
        void postordenEnLista(list<T> &out);
        Nodo<T> *eliminarNodo(Nodo<T> *nodo, T &valor);
        Nodo<T> *nodoMinimo(Nodo<T> *nodo);
        int size();

};

// Implementación de la clase arbolAVL.
#include "arbolAVL.hxx"

#endif
