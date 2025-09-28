#include <iostream>
#include "ArbolAVL.h"
using namespace std;

int main() {
    
    ArbolAVL<int> avl;

    avl.insertar(10);
    avl.insertar(20);
    avl.insertar(30);
    avl.insertar(40);
    avl.insertar(50);
    avl.insertar(25);

    cout << "PreOrden: "; avl.mostrarPreOrden();
    cout << "InOrden: "; avl.mostrarInOrden();
    cout << "PostOrden: "; avl.mostrarPostOrden();

    avl.eliminar(40);
    cout << "InOrden tras eliminar 40: "; avl.mostrarInOrden();

    return 0;
}