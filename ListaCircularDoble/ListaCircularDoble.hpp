#ifndef LISTACIRCULARDOBLE_HPP_INCLUDED
#define LISTACIRCULARDOBLE_HPP_INCLUDED

template <typename T>
class ListaCircularDoble {
public:
    // MÉTODOS PARA EL BUEN FUNCIONAMIENTO DE LA CLASE.
    ListaCircularDoble();
    ~ListaCircularDoble();
    ListaCircularDoble(const ListaCircularDoble &lista);
    ListaCircularDoble& operator=(const ListaCircularDoble &lista);

    // MÉTODOS OPERATIVOS.
    void agregar(T valor);
    void eliminar();
    bool buscar(T valor) const;
    void avanzarCabeza();
    void retrocederCabeza();
    int obtenerTamano() const;
    T obtenerCabeza() const;
    bool estaVacia() const;
    void vaciar();
    void imprimir() const;
    void imprimirEnReversa() const;

private:
    struct Nodo{
        T valor;
        Nodo * siguiente, * anterior;
    } * cabeza;

    int tamano;
};

#include "ListaCircularDoble.tpp"
#endif // LISTACIRCULARDOBLE_HPP_INCLUDED
