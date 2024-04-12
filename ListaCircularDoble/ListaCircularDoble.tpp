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
    while(cabeza != nullptr) eliminar(); //ESTO ES EQUIVALENTE A VACIAR
}

//********************************************************* Constructor de copias
template <typename T>
ListaCircularDoble<T>::ListaCircularDoble(const ListaCircularDoble &lista){
    // Elimina los nodos de la instancia que llame al operador.
    if(this != lista) while(cabeza != nullptr) eliminar();

    // Copia los nodos de lista a la instancia que llama el operador.
    Nodo * nodoActual = lista.cabeza;
    for(int i = 0; i < tamano; ++i){
        agregar(nodoActual->valor);
        nodoActual = nodoActual->siguiente;
    }
}

//********************************************************* Sobrecarga operador =
template <typename T>
ListaCircularDoble<T>& ListaCircularDoble<T>::operator=(const ListaCircularDoble<T> &lista){
    // Elimina los nodos de la instancia que llame al operador.
    if(this != lista) while(cabeza != nullptr) eliminar();

    // Copia los nodos de lista a la instancia que llama el operador.
    Nodo * nodoActual = lista.cabeza;
    for(int i = 0; i < tamano; ++i){
        agregar(nodoActual->valor);
        nodoActual = nodoActual->siguiente;
    }

    return *this;
};

//********************************************************* Agregar
template <typename T>
void ListaCircularDoble<T>::agregar(T valor){
    Nodo * nodoNuevo = new Nodo{valor, nullptr, nullptr};

    if(cabeza == nullptr){
        cabeza = nodoNuevo;
        nodoNuevo->siguiente = nodoNuevo;
        nodoNuevo->anterior = nodoNuevo;
    } else{
        Nodo * ultimoNodo = cabeza->anterior;

        nodoNuevo->siguiente = cabeza;
        nodoNuevo->anterior = ultimoNodo;
        ultimoNodo->siguiente = nodoNuevo;
        cabeza->anterior = nodoNuevo;
        cabeza = nodoNuevo;
    }

    ++tamano;
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

//********************************************************* Buscar
template <typename T>
bool ListaCircularDoble<T>::buscar(T valor) const{
    Nodo * nodoActual = cabeza;
    for(int i = 0; i < tamano; ++i){
        if(nodoActual->valor == valor) return true;
        nodoActual = nodoActual->siguiente;
    }
    return false;
}

//********************************************************* Avanzar cabeza
template <typename T>
void ListaCircularDoble<T>::avanzarCabeza(){
    cabeza = cabeza->siguiente;
};

//********************************************************* Retroceder cabeza
template <typename T>
void ListaCircularDoble<T>::retrocederCabeza(){
    cabeza = cabeza->anterior;
}

//********************************************************* Obtener tamano
template <typename T>
int ListaCircularDoble<T>::obtenerTamano() const{
    return tamano;
};

//********************************************************* Obtener cabeza (valor)
template <typename T>
T ListaCircularDoble<T>::obtenerCabeza() const{
    return cabeza->valor;
};

//********************************************************* Esta vacia
template <typename T>
bool ListaCircularDoble<T>::estaVacia() const{
    return tamano == 0;
};

//********************************************************* Vaciar
template <typename T>
void ListaCircularDoble<T>::vaciar(){
    while(cabeza != nullptr) eliminar();
};

//********************************************************* Imprimir
template <typename T>
void ListaCircularDoble<T>::imprimir() const{
    Nodo * nodoActual = cabeza;

    std::cout << "Tope->";
    for(int i = 0; i < tamano; ++i){
        std::cout << nodoActual->valor << ", ";
        nodoActual = nodoActual->siguiente;
    }
    std::cout << "\b\b.";
}

//********************************************************* Imprimir en reversa.
template <typename T>
void ListaCircularDoble<T>::imprimirEnReversa() const{
    Nodo * nodoActual = cabeza->anterior;

    std::cout << "Ultimo->";
    for(int i = 0; i < tamano; ++i){
        std::cout << nodoActual->valor << ", ";
        nodoActual = nodoActual->anterior;
    }
    std::cout << "\b\b.";
}

