#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include <list>
using namespace std;

template <typename T>
struct Nodo {
    T dato;
    Nodo<T>* izq;
    Nodo<T>* der;
    int altura;

    Nodo(const T& v) : dato(v), izq(nullptr), der(nullptr), altura(1) {}
};

template <typename T>
class arbolAVL {
private:
    Nodo<T>* raiz;

    // Privados (declaraciones)
    Nodo<T>* insertarNodo(Nodo<T>* nodo, const T& valor);
    int altura(Nodo<T>* nodo);
    int obtenerBalance(Nodo<T>* nodo);
    Nodo<T>* rotarDerecha(Nodo<T>* y);
    Nodo<T>* rotarIzquierda(Nodo<T>* x);

    void destruir(Nodo<T>* nodo);

    // Recorridos internos que llenan una lista (push_back)
    void recPreOrden(Nodo<T>* nodo, list<T>& out) const;
    void recInOrden(Nodo<T>* nodo, list<T>& out) const;
    void recPostOrden(Nodo<T>* nodo, list<T>& out) const;

public:
    arbolAVL();
    ~arbolAVL();

    void insert(const T& valor);
    void erase(const T& valor);


    // Métodos que la interfaz espera: reciben una lista y la llenan (push_back)
    void inordenEnLista(list<T>& out) const;
    void preordenEnLista(list<T>& out) const;
    void postordenEnLista(list<T>& out) const;
        Nodo<T>* eliminarNodo(Nodo<T>* nodo, const T& valor);
    Nodo<T>* nodoMinimo(Nodo<T>* nodo);


    // utilidad opcional
    int size() const;
};

#include "arbolAVL.hxx"
#endif
