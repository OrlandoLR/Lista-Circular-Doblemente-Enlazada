#include "ListaCircularDoble.hpp"

//********************************************************* Constructor
template <typename T>
ListaCircularDoble<T>::ListaCircularDoble(){
    tamano = 0;
    cabeza = nullptr;
}

//********************************************************* Destructor
template <typename T>
ListaCircularDoble<T>::~ListaCircularDoble(){

}

//********************************************************* Constructor de copias
template <typename T>
ListaCircularDoble<T>::ListaCircularDoble(const ListaCircularDoble &lista){

}

//********************************************************* Sobrecarga operador =
/*


ListaCircularDoble& operator=(const ListaCircularDoble &lista);
*/

template <typename T>
void ListaCircularDoble<T>::agregar(T valor){

}

//********************************************************* Eliminar
template <typename T>
void ListaCircularDoble<T>::eliminar(){
    //TODO: Excepcion se intenta eliminar con lista vacia
    Nodo * nodoActual = cabeza;

    if(tamano > 1){
        nodoActual->anterior->siguiente = nodoActual->siguiente;
        nodoActual->siguiente->anterior = nodoActual->anterior;
    } else cabeza = nullptr;

    delete nodoActual;
    --tamano;
}

//*********************************************************
