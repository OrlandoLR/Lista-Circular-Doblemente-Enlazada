#include <iostream>
#include "ListaCircularDoble.hpp"

using namespace std;

int main()
{
    //ListaCircularDoble<int> A;
    ListaCircularDoble<int> A;
    A.agregar(1);
    A.agregar(2);
    A.agregar(3);
    A.agregar(5);
    A.imprimir();

    A.retrocederCabeza();
     A.imprimir();
    A.avanzarCabeza();
     A.imprimir();
     A.imprimirEnReversa();
    cout << "\nTamano:" << A.obtenerTamano();
    cout << "\nCabeza:" << A.obtenerCabeza();
    return 0;
}
