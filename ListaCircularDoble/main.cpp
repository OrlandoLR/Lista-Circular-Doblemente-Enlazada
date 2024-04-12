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
    A.imprimir();
    return 0;
}
