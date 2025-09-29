#include "monticulo.h"

template<typename T>
monticulo<T>::monticulo() {
  // Constructor vacío
}

template<typename T>
void monticulo<T>::insert(const T &value) {
    if (find(data.begin(), data.end(), value) != data.end()) 
    return; // ya existe → no insertar
    data.push_back(value);
    push_heap(data.begin(), data.end());
}

template<typename T>
void monticulo<T>::erase(const T &value) {
    typename vector<T>::iterator it = find(data.begin(), data.end(), value);
    if (it == data.end()) return; 

    iter_swap(it, data.end() - 1);  
    data.pop_back();                
    if (!data.empty()) {
        make_heap(data.begin(), data.end());
    }
}

template<typename T>
void monticulo<T>::inordenEnLista(list<T>& listaOrdenada)const {
    vector<T> temp = data;          
    sort(temp.begin(), temp.end()); 
    listaOrdenada.clear();

    for (typename vector<T>::const_iterator it = temp.begin(); it != temp.end(); ++it) {
        listaOrdenada.push_back(*it);
    }
}

template<typename T>
int monticulo<T>::size()const {
    return data.size();
}

template<typename T>
bool monticulo<T>::empty()const {
    return data.empty();
}
