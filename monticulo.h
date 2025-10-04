#ifndef MONTICULO
#define MONTICULO

#include <list> 
#include <vector> 

using namespace std;

// Clase template para un montículo (heap).
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

// Implementación de la clase monticulo.
#include "monticulo.hxx"

#endif
