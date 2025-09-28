#include "ArbolAVL.h"

// Altura segura
template <class T>
int ArbolAVL<T>::altura(NodoAVL<T>* nodo) {
    return (nodo == nullptr) ? 0 : nodo->obtenerAltura();
}

// Factor de balance
template <class T>
int ArbolAVL<T>::factorBalance(NodoAVL<T>* nodo) {
    if (nodo == nullptr) return 0;
    return altura(nodo->obtenerIzq()) - altura(nodo->obtenerDer());
}

// Rotación simple derecha
template <class T>
NodoAVL<T>* ArbolAVL<T>::rotarDerecha(NodoAVL<T>* y) {
    NodoAVL<T>* x = y->obtenerIzq();
    NodoAVL<T>* T2 = x->obtenerDer();

    // Rotación
    x->fijarDer(y);
    y->fijarIzq(T2);

    // Actualizar alturas
    y->fijarAltura(1 + max(altura(y->obtenerIzq()), altura(y->obtenerDer())));
    x->fijarAltura(1 + max(altura(x->obtenerIzq()), altura(x->obtenerDer())));

    return x;
}

// Rotación simple izquierda
template <class T>
NodoAVL<T>* ArbolAVL<T>::rotarIzquierda(NodoAVL<T>* x) {
    NodoAVL<T>* y = x->obtenerDer();
    NodoAVL<T>* T2 = y->obtenerIzq();

    // Rotación
    y->fijarIzq(x);
    x->fijarDer(T2);

    // Actualizar alturas
    x->fijarAltura(1 + max(altura(x->obtenerIzq()), altura(x->obtenerDer())));
    y->fijarAltura(1 + max(altura(y->obtenerIzq()), altura(y->obtenerDer())));

    return y;
}

// Insertar balanceado
template <class T>
NodoAVL<T>* ArbolAVL<T>::insertarAVL(NodoAVL<T>* nodo, T val) {
    if (nodo == nullptr)
        return new NodoAVL<T>(val);

    if (val < nodo->obtenerDato())
        nodo->fijarIzq(insertarAVL(nodo->obtenerIzq(), val));
    else if (val > nodo->obtenerDato())
        nodo->fijarDer(insertarAVL(nodo->obtenerDer(), val));
    else
        return nodo; // No duplicados

    // Actualizar altura
    nodo->fijarAltura(1 + max(altura(nodo->obtenerIzq()), altura(nodo->obtenerDer())));

    // Verificar balance
    int balance = factorBalance(nodo);

    // Casos de rotación
    if (balance > 1 && val < nodo->obtenerIzq()->obtenerDato())
        return rotarDerecha(nodo);

    if (balance < -1 && val > nodo->obtenerDer()->obtenerDato())
        return rotarIzquierda(nodo);

    if (balance > 1 && val > nodo->obtenerIzq()->obtenerDato()) {
        nodo->fijarIzq(rotarIzquierda(nodo->obtenerIzq()));
        return rotarDerecha(nodo);
    }

    if (balance < -1 && val < nodo->obtenerDer()->obtenerDato()) {
        nodo->fijarDer(rotarDerecha(nodo->obtenerDer()));
        return rotarIzquierda(nodo);
    }

    return nodo;
}

// Encontrar mínimo
template <class T>
NodoAVL<T>* ArbolAVL<T>::nodoMinimo(NodoAVL<T>* nodo) {
    NodoAVL<T>* actual = nodo;
    while (actual->obtenerIzq() != nullptr)
        actual = actual->obtenerIzq();
    return actual;
}

// Eliminar balanceado
template <class T>
NodoAVL<T>* ArbolAVL<T>::eliminarAVL(NodoAVL<T>* nodo, T val) {
    if (nodo == nullptr) return nodo;

    if (val < nodo->obtenerDato())
        nodo->fijarIzq(eliminarAVL(nodo->obtenerIzq(), val));
    else if (val > nodo->obtenerDato())
        nodo->fijarDer(eliminarAVL(nodo->obtenerDer(), val));
    else {
        if (nodo->obtenerIzq() == nullptr || nodo->obtenerDer() == nullptr) {
            NodoAVL<T>* temp = nodo->obtenerIzq() ? nodo->obtenerIzq() : nodo->obtenerDer();
            if (temp == nullptr) {
                temp = nodo;
                nodo = nullptr;
            } else
                *nodo = *temp;
            delete temp;
        } else {
            NodoAVL<T>* temp = nodoMinimo(nodo->obtenerDer());
            nodo->fijarDato(temp->obtenerDato());
            nodo->fijarDer(eliminarAVL(nodo->obtenerDer(), temp->obtenerDato()));
        }
    }

    if (nodo == nullptr) return nodo;

    // Actualizar altura
    nodo->fijarAltura(1 + max(altura(nodo->obtenerIzq()), altura(nodo->obtenerDer())));

    int balance = factorBalance(nodo);

    // Balancear
    if (balance > 1 && factorBalance(nodo->obtenerIzq()) >= 0)
        return rotarDerecha(nodo);

    if (balance > 1 && factorBalance(nodo->obtenerIzq()) < 0) {
        nodo->fijarIzq(rotarIzquierda(nodo->obtenerIzq()));
        return rotarDerecha(nodo);
    }

    if (balance < -1 && factorBalance(nodo->obtenerDer()) <= 0)
        return rotarIzquierda(nodo);

    if (balance < -1 && factorBalance(nodo->obtenerDer()) > 0) {
        nodo->fijarDer(rotarDerecha(nodo->obtenerDer()));
        return rotarIzquierda(nodo);
    }

    return nodo;
}

// Recorridos
template <class T>
void ArbolAVL<T>::preOrden(NodoAVL<T>* nodo) {
    if (nodo != nullptr) {
        cout << nodo->obtenerDato() << " ";
        preOrden(nodo->obtenerIzq());
        preOrden(nodo->obtenerDer());
    }
}

template <class T>
void ArbolAVL<T>::inOrden(NodoAVL<T>* nodo) {
    if (nodo != nullptr) {
        inOrden(nodo->obtenerIzq());
        cout << nodo->obtenerDato() << " ";
        inOrden(nodo->obtenerDer());
    }
}

template <class T>
void ArbolAVL<T>::postOrden(NodoAVL<T>* nodo) {
    if (nodo != nullptr) {
        postOrden(nodo->obtenerIzq());
        postOrden(nodo->obtenerDer());
        cout << nodo->obtenerDato() << " ";
    }
}