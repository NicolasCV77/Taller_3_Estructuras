#include <algorithm> // max
#include "arbolAVL.h"

// Constructor/Destructor
template <typename T>
arbolAVL<T>::arbolAVL() : raiz(nullptr) {}

template <typename T>
arbolAVL<T>::~arbolAVL() {
    destruir(raiz);
}

template <typename T>
void arbolAVL<T>::destruir(Nodo<T>* nodo) {
    if (nodo == nullptr) return;
    destruir(nodo->izq);
    destruir(nodo->der);
    delete nodo;
}

// Altura y balance
template <typename T>
int arbolAVL<T>::altura(Nodo<T>* nodo) {
    return (nodo == nullptr) ? 0 : nodo->altura;
}

template <typename T>
int arbolAVL<T>::obtenerBalance(Nodo<T>* nodo) {
    return (nodo == nullptr) ? 0 : (altura(nodo->izq) - altura(nodo->der));
}

// Rotaciones
template <typename T>
Nodo<T>* arbolAVL<T>::rotarDerecha(Nodo<T>* y) {
    Nodo<T>* x = y->izq;
    Nodo<T>* T2 = x->der;

    x->der = y;
    y->izq = T2;

    y->altura = 1 + max(altura(y->izq), altura(y->der));
    x->altura = 1 + max(altura(x->izq), altura(x->der));

    return x;
}

template <typename T>
Nodo<T>* arbolAVL<T>::rotarIzquierda(Nodo<T>* x) {
    Nodo<T>* y = x->der;
    Nodo<T>* T2 = y->izq;

    y->izq = x;
    x->der = T2;

    x->altura = 1 + max(altura(x->izq), altura(x->der));
    y->altura = 1 + max(altura(y->izq), altura(y->der));

    return y;
}

// Nodo mínimo (para encontrar sucesor en eliminación)
template <typename T>
Nodo<T>* arbolAVL<T>::nodoMinimo(Nodo<T>* nodo) {
    Nodo<T>* actual = nodo;
    while (actual->izq != nullptr) {
        actual = actual->izq;
    }
    return actual;
}

// Eliminar un valor manteniendo balance AVL
template <typename T>
Nodo<T>* arbolAVL<T>::eliminarNodo(Nodo<T>* nodo, const T& valor) {
    if (nodo == nullptr) {
        return nodo;
    }

    if (valor < nodo->dato) {
        nodo->izq = eliminarNodo(nodo->izq, valor);
    } else if (valor > nodo->dato) {
        nodo->der = eliminarNodo(nodo->der, valor);
    } else {
        // Caso 1 y 2: 0 o 1 hijo
        if (nodo->izq == nullptr || nodo->der == nullptr) {
            Nodo<T>* temp = nodo->izq ? nodo->izq : nodo->der;

            if (temp == nullptr) {
                temp = nodo;
                nodo = nullptr;
            } else {
                *nodo = *temp;
            }
            delete temp;
        } else {
            // Caso 3: dos hijos → reemplazar con sucesor inorder
            Nodo<T>* temp = nodoMinimo(nodo->der);
            nodo->dato = temp->dato;
            nodo->der = eliminarNodo(nodo->der, temp->dato);
        }
    }

    if (nodo == nullptr) {
        return nodo;
    }

    // Actualizar altura
    nodo->altura = 1 + std::max(altura(nodo->izq), altura(nodo->der));

    // Verificar balance
    int balance = obtenerBalance(nodo);

    // Casos de rotación
    if (balance > 1 && obtenerBalance(nodo->izq) >= 0) {
        return rotarDerecha(nodo);
    }

    if (balance > 1 && obtenerBalance(nodo->izq) < 0) {
        nodo->izq = rotarIzquierda(nodo->izq);
        return rotarDerecha(nodo);
    }

    if (balance < -1 && obtenerBalance(nodo->der) <= 0) {
        return rotarIzquierda(nodo);
    }

    if (balance < -1 && obtenerBalance(nodo->der) > 0) {
        nodo->der = rotarDerecha(nodo->der);
        return rotarIzquierda(nodo);
    }

    return nodo;
}

template <typename T>
void arbolAVL<T>::erase(const T& valor) {
    raiz = eliminarNodo(raiz, valor);
}


// Inserción balanceada
template <typename T>
Nodo<T>* arbolAVL<T>::insertarNodo(Nodo<T>* nodo, const T& valor) {
    if (nodo == nullptr) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        return nuevo;
    }

    if (valor < nodo->dato) {
        nodo->izq = insertarNodo(nodo->izq, valor);
    } else if (valor > nodo->dato) {
        nodo->der = insertarNodo(nodo->der, valor);
    } else {
        // duplicado -> no insertar
        return nodo;
    }

    // actualizar altura
    nodo->altura = 1 + max(altura(nodo->izq), altura(nodo->der));

    int balance = obtenerBalance(nodo);

    // LL case
    if (balance > 1 && valor < nodo->izq->dato)
        return rotarDerecha(nodo);

    // RR case
    if (balance < -1 && valor > nodo->der->dato)
        return rotarIzquierda(nodo);

    // LR case
    if (balance > 1 && valor > nodo->izq->dato) {
        nodo->izq = rotarIzquierda(nodo->izq);
        return rotarDerecha(nodo);
    }

    // RL case
    if (balance < -1 && valor < nodo->der->dato) {
        nodo->der = rotarDerecha(nodo->der);
        return rotarIzquierda(nodo);
    }

    return nodo;
}

template <typename T>
void arbolAVL<T>::insert(const T& valor) {
    raiz = insertarNodo(raiz, valor);
}

// Recorridos internos que hacen push_back en la lista OUT
template <typename T>
void arbolAVL<T>::recPreOrden(Nodo<T>* nodo, list<T>& out) const {
    if (nodo == nullptr) return;
    out.push_back(nodo->dato);
    recPreOrden(nodo->izq, out);
    recPreOrden(nodo->der, out);
}

template <typename T>
void arbolAVL<T>::recInOrden(Nodo<T>* nodo, list<T>& out) const {
    if (nodo == nullptr) return;
    recInOrden(nodo->izq, out);
    out.push_back(nodo->dato);
    recInOrden(nodo->der, out);
}

template <typename T>
void arbolAVL<T>::recPostOrden(Nodo<T>* nodo, list<T>& out) const {
    if (nodo == nullptr) return;
    recPostOrden(nodo->izq, out);
    recPostOrden(nodo->der, out);
    out.push_back(nodo->dato);
}

// MÉTODOS PÚBLICOS: reciben 'out' y lo rellenan mediante push_back.
// IMPORTANT: **NO** hacen clear ni borran 'out' (mismo comportamiento que arbolRN).
template <typename T>
void arbolAVL<T>::inordenEnLista(list<T>& out) const {
    recInOrden(raiz, out);
}

template <typename T>
void arbolAVL<T>::preordenEnLista(list<T>& out) const {
    recPreOrden(raiz, out);
}

template <typename T>
void arbolAVL<T>::postordenEnLista(list<T>& out) const {
    recPostOrden(raiz, out);
}

// size: construye una lista temporal y devuelve su tamaño (puedes evitar esto manteniendo contador)
template <typename T>
int arbolAVL<T>::size() const {
    list<T> tmp;
    recInOrden(raiz, tmp);
    // iterator explicit (no auto) to get size by iterating if you prefer, but tmp.size() is fine:
    return static_cast<int>(tmp.size());
}

