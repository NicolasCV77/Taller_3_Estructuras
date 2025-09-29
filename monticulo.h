#ifndef MONTICULO_H
#define MONTICULO_H

#include <vector>
#include <list>
#include <algorithm>

using namespace std;

//Declaración de la clase monticulo.
template<class T>
class monticulo {
  private:
    vector<T> data; 

  public:
    monticulo();

    void insert(T &value);
    void erase(T &value);
    void inordenEnLista(list<T> &listaOrdenada);

    int size();
    bool empty();
};

// Incluimos la implementación.
#include "monticulo.hxx"

#endif
