#ifndef MONTICULO_H
#define MONTICULO_H

#include <vector>
#include <list>
#include <algorithm>

using namespace std;

//Declaración de la clase monticulo.
template<typename T>
class monticulo {
private:
  vector<T> data; 

public:
  monticulo();

  void insert(const T &value);
  void erase(const T &value);
  void inordenEnLista(list<T> &listaOrdenada)const;

  int size()const;
  bool empty()const;
};

// Incluimos la implementación.
#include "monticulo.hxx"

#endif
