#include "monticulo.h"

template<class T>
monticulo<T>::monticulo() {
    // Constructor vacío
}

template<class T>
void monticulo<T>::insert(T &value) {
    if (find(data.begin(), data.end(), value) != data.end()) {
        return;
    }
    data.push_back(value);
    push_heap(data.begin(), data.end());
}

template<class T>
void monticulo<T>::erase(T &value) {
    typename vector<T>::iterator it = find(data.begin(), data.end(), value);
    if (it == data.end()) {
        return;
    }

    iter_swap(it, data.end() - 1);  
    data.pop_back();                
    if (!data.empty()) {
        make_heap(data.begin(), data.end());
    }
}

template<class T>
void monticulo<T>::inordenEnLista(list<T>& listaOrdenada) {
    vector<T> temp = data;          
    sort(temp.begin(), temp.end()); 
    listaOrdenada.clear();
    typename vector<T>::iterator it;
    for (it = temp.begin(); it != temp.end(); ++it) {
        listaOrdenada.push_back(*it);
    }
}

template<class T>
int monticulo<T>::size() {
    return data.size();
}

template<class T>
bool monticulo<T>::empty() {
    return data.empty();
}
