/*
  --------------------------------
  Taller 3: Comparación de árboles
  --------------------------------
  Clase de Estructuras de Datos
  Modificado por: Ing. Alejandro Castro Martinez
  Pontificia Universidad Javeriana
  Bogotá, Colombia
*/

#include <ctime>
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>
#include <iomanip>   // setw, fixed, setprecision

using namespace std;

// TODO #01: Incluir cabecera de la implementación propia del árbol AVL
// #include "arbolAVL.h"

// TODO #06: Incluir cabecera de la STL correspondiente al árbol rojinegro
#include "arbolRN.h"

// TODO #11: Incluir cabecera de la STL correspondiente al montículo
// #include "monticulo.h"

typedef list<string> TList;

// TODO #02: Definir árbol AVL de tipo string
// typedef arbolAVL<string> TAVL;

// TODO #07: Definir árbol rojinegro de tipo string
typedef arbolRN<string> TRN;

// TODO #12: Definir Montículo de tipo string
// typedef monticulo<string> THeap;

struct ReadStats {
  size_t ops_total   = 0;
  size_t ops_add     = 0;
  size_t ops_del     = 0;
  double secs_total  = 0.0;
  double secs_add    = 0.0;
  double secs_del    = 0.0;
};

template <class TArbol>
bool LeerArbol(TArbol &arbol, const string &nomArch, bool medirCadaOperacion, ReadStats &stats);

static inline double to_ms(double seconds) { return seconds * 1000.0; }

void ImprimirResumen(const string& titulo, const ReadStats& s, bool detalle) {
  cout << "\n============================================================\n";
  cout << " " << titulo << "\n";
  cout << "------------------------------------------------------------\n";
  cout << fixed << setprecision(3);

  cout << " Operaciones procesadas : " << s.ops_total << "\n";
  cout << " Tiempo TOTAL           : " << to_ms(s.secs_total) << " ms\n";

  if (detalle) {
    cout << "------------------------------------------------------------\n";
    cout << " Detalle por operación:\n";
    cout << "   add -> " << setw(6) << s.ops_add
              << " ops | " << setw(9) << to_ms(s.secs_add) << " ms";
    if (s.ops_add) {
      cout << " | promedio: " << to_ms(s.secs_add / double(s.ops_add)) << " ms/op";
    }
    cout << "\n";

    cout << "   del -> " << setw(6) << s.ops_del
              << " ops | " << setw(9) << to_ms(s.secs_del) << " ms";
    if (s.ops_del) {
      cout << " | promedio: " << to_ms(s.secs_del / double(s.ops_del)) << " ms/op";
    }
    cout << "\n";
  }
  cout << "============================================================\n";
}

int main(int argc, char *argv[])
{
  if (argc < 3)
  {
    cerr << "Uso: " << argv[0] << " archivo_entrada  Y|N\n";
    return (-1);
  }

  const string archivo = argv[1];
  const char modo = toupper(static_cast<unsigned char>(argv[2][0]));
  if (modo != 'Y' && modo != 'N') {
    cerr << "Error: el segundo parametro debe ser 'Y' o 'N'.\n";
    return (-1);
  }
  const bool medirCadaOperacion = (modo == 'Y');

  // TODO #03: Definir variable tipo árbol AVL.
  // TAVL miArbolAVL;

  // TODO #08: Definir variable tipo árbol rojinegro.
  TRN miArbolRN;

  // TODO #13: Definir variable tipo Montículo.
  // THeap miMonticulo;

  ReadStats statsAVL;
  chrono::steady_clock::time_point t0AVL = chrono::steady_clock::now();
  // bool lecturaAVL = LeerArbol(miArbolAVL, archivo, medirCadaOperacion, statsAVL);
  chrono::steady_clock::time_point t1AVL = chrono::steady_clock::now();
  double tiempoLecturaAVL = chrono::duration<double>(t1AVL - t0AVL).count();
  statsAVL.secs_total = tiempoLecturaAVL;

  ReadStats statsRN;
  chrono::steady_clock::time_point t0RN = chrono::steady_clock::now();
  bool lecturaRN = LeerArbol(miArbolRN, archivo, medirCadaOperacion, statsRN);
  chrono::steady_clock::time_point t1RN = chrono::steady_clock::now();
  double tiempoLecturaRN = chrono::duration<double>(t1RN - t0RN).count();
  statsRN.secs_total = tiempoLecturaRN;

  ReadStats statsHeap;
  chrono::steady_clock::time_point t0Heap = chrono::steady_clock::now();
  // bool lecturaHeap = LeerArbol(miMonticulo, archivo, medirCadaOperacion, statsHeap);
  chrono::steady_clock::time_point t1Heap = chrono::steady_clock::now();
  double tiempoLecturaHeap = chrono::duration<double>(t1Heap - t0Heap).count();
  statsHeap.secs_total = tiempoLecturaHeap;

  /*
    =============================================
    Comparar los árboles y mostrar el resultado
    =============================================
  */
  TList inordenAVL, inordenRN, inordenHeap;

  // TODO #05: Llamar la función que genera el recorrido en inorden del árbol AVL y lo guarda en una lista dada como parámetro.
  // miArbolAVL.inordenEnLista(inordenAVL);

  // TODO #10: Llamar la función que genera el recorrido en inorden del árbol rojinegro y lo guarda en una lista dada como parámetro.
  miArbolRN.inordenEnLista(inordenRN);

  // TODO #15: Llamar la función que genera el recorrido en inorden del montículo y lo guarda en una lista dada como parámetro.
  // miMonticulo.inordenEnLista(inordenHeap);


  size_t sizeAVL  = inordenAVL.size();
  size_t sizeRN   = inordenRN.size();
  size_t sizeHeap = inordenHeap.size();

  size_t minSize = min({sizeAVL, sizeRN, sizeHeap});

  cout << "\n------------------ Resumen de tamaños (inorden) ------------------\n";
  cout << " AVL               : " << sizeAVL  << " elementos\n";
  cout << " Árbol Rojo-Negro  : " << sizeRN   << " elementos\n";
  cout << " Heap              : " << sizeHeap << " elementos\n";

  if (sizeAVL == sizeRN && sizeRN == sizeHeap) {
    cout << " ==> Las tres estructuras tienen la misma cantidad de elementos.\n";
  } else {
    cout << " ==> La estructura con menos elementos tiene " << minSize << " elemento(s).\n";
  }
  
  /*
    ===============================================================
    Comparar los elementos y su posición de cada uno de los árboles
    ===============================================================
  */

  // TODO #16: Crear iteradores para recorrer cada una de las estructuras lineales 
  // TList::iterator itAVL  = inordenAVL.begin();
  TList::iterator itRN   = inordenRN.begin();
  // TList::iterator itHeap = inordenHeap.begin();
  
  // TODO #17: Recorrer las estructuras lineales y comparar elemento a elemento la igualdad o desigualdad
  // bool todosIguales = true;
  // for (size_t i = 0; i < minSize; ++i, ++itAVL, ++itRN, ++itHeap) {
  //   if (!(*itAVL == *itRN && *itRN == *itHeap)) {
  //     cout << " Diferencia en la posicion " << i
  //               << " | AVL: " << *itAVL
  //               << " | RN: "  << *itRN
  //               << " | Heap: "<< *itHeap << "\n";
  //     todosIguales = false;
  //   }
  // }

  // TODO #18: Informar si los árboles coinciden en la totalidad de los elementos teniendo en cuenta su posición
  // if (todosIguales && sizeAVL == sizeRN && sizeRN == sizeHeap) {
  //   cout << " ==> Coincidencia total: los tres recorridos inorden son idénticos.\n";
  // } else if (todosIguales) {
  //   cout << " ==> Coincidencia parcial: igualdad en posiciones comparadas, pero tamaños distintos.\n";
  // } else {
  //   cout << " ==> No hay coincidencia total entre las tres estructuras.\n";
  // }

  return (0);
}

template <class TArbol>
bool LeerArbol(TArbol &arbol, const string &nomArch, bool medirCadaOperacion, ReadStats &stats)
{
  ifstream entrada(nomArch.c_str());
  if (!entrada) return false;

  string codigo, valor;
  using clock_t = chrono::steady_clock;

  while (entrada >> codigo >> valor)
  {
    chrono::steady_clock::time_point t0 = clock_t::now();

    if (codigo == "add") {
      arbol.insert(valor);
      chrono::steady_clock::time_point t1 = clock_t::now();
      if (medirCadaOperacion) {
        double secs = chrono::duration<double>(t1 - t0).count();
        stats.secs_add += secs;
      }
      ++stats.ops_add;
      ++stats.ops_total;
    }
    else if (codigo == "del") {
      arbol.erase(valor);
      chrono::steady_clock::time_point t1 = clock_t::now();
      if (medirCadaOperacion) {
        double secs = chrono::duration<double>(t1 - t0).count();
        stats.secs_del += secs;
      }
      ++stats.ops_del;
      ++stats.ops_total;
    }
  }

  entrada.close();
  return true;
}

// eof - taller_3_ordenamiento_busqueda.cxx
