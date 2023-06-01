#include "lista.h"
#include "libro.h"
#include <iostream>
#include <assert.h>
//esta es para usar el assert
using namespace std;

template <typename T>
Lista<T>::Lista() {     //complejidad lineal
//crea nodos basicamente
    this -> inicio= nullptr;
    //entiendo que creo al nodo no se bien
    this -> fin=nullptr;
    //el siguiente no apunta a nada porque todavia no existe la lista en si
    this -> cantidad=0;
    ultimo_accedido=inicio;
};

template <typename T>
void Lista<T>:: agregar_inicio(const T & elemento) //complejidad lineal
{
nodo* aux=new nodo;
    //creo un nodo
    aux->elemento=elemento;
    //meto la info del libro en el nodo
    aux->siguiente=inicio;
    //hago que apunte al que era el primero
    inicio=aux;
    if (fin==nullptr){
        fin=inicio;}
    cantidad++;
    //el puntero toma el valor de aux=incio
    ultimo_accedido=inicio;
}

template <typename T>
void Lista<T>::insertar_ordenado(const T & elemento){ //complejidad log n?
    this->cantidad++;
    nodo* insertar= new nodo;
    //creo los nodos
    //pongo el puntero al incio
    insertar->elemento=elemento;
    if (inicio==nullptr || inicio->elemento < elemento){
        insertar->siguiente=inicio;
        inicio = insertar;
        ultimo_accedido=inicio;
        return;
    }
    nodo * aux = new nodo;
    aux=inicio;
    //para cuando se cumpla en el primero
    while (aux->siguiente!=nullptr && elemento < aux->siguiente->elemento){
            aux=aux->siguiente;
    }
    //recorre
    insertar->siguiente=aux->siguiente;
    aux->siguiente=insertar;
    ultimo_accedido=inicio;
    //engancha la lista
}

template <typename T>
void Lista<T>::agregar_alfinal(const T & elemento) //complejidad lineal
{
    nodo * aux = new nodo;
    //creo nuevo nodo para la lista
    aux->elemento=elemento;
    aux->siguiente=nullptr;
    if (inicio==nullptr){
    //si la fila esta vacia
        inicio=aux;
        fin=aux;
    }
    else{
        fin->siguiente=aux;
        fin=aux;
    }
    cantidad++;
    ultimo_accedido=inicio;
    //para asegurarme que vuelva al principio
}

template <typename T>
int Lista<T>::longlista() const //complejidad lineal
{ //este te tira la longitud de la lista
    return this->cantidad;
}

template <typename T>
void Lista <T> :: insertar_lista (const T & elemento, unsigned int pos) //complejidad n
{
//inserta un nodo en la lista
assert ((pos>=1) and (pos <= cantidad+1));
//para que no se pase de rango
    if (pos ==1){
        nodo* aux=new nodo;
    //creo un nodo
    aux->elemento=elemento;
    //meto la info del libro en el nodo
    aux->siguiente=inicio;
    //hago que apunte al que era el primero
    inicio=aux;
    if (fin==nullptr){
        fin=inicio;}
    cantidad++;
    }
    else{
        if(pos==cantidad+1){
        // si quiero agregar añl final
            agregar_alfinal(elemento);
        }
        else{
            nodo* nodo_nuevo=new nodo;
            nodo* aux = new nodo;
            //creo el nuevo nodo y un auxiliar que va a recorrer hasta llegar a la pos
            nodo_nuevo->elemento=elemento;
            // le asigno lo debido a mi nuevo nodo
            nodo_nuevo->siguiente=nullptr;
            aux=inicio;
            int pos2;pos2=1;
            while (pos2 < pos-1){
                aux=aux->siguiente;
                pos2++;
            //hasta no llegar a la pocision deseada avanzo
            }
            nodo_nuevo->siguiente=aux->siguiente;
            aux->siguiente=nodo_nuevo;
            //asigno
            cantidad++;
            //sumo 1 a la longitud
            ultimo_accedido=inicio;
          }
        }
}

template< typename T>
void Lista<T>:: eliminar(nodo*nodo)
{
    if (nodo!=nullptr){
    // si no llegue al final
        eliminar(nodo->siguiente);
    //paso al siguiente
        delete nodo;
        nodo=nullptr;
    }
}

template< typename T>
const T &  Lista<T> :: devolver_siguiente() //complejidad lineal creo
{
    assert(inicio!=nullptr);
    nodo* aux = new nodo;
    if (ultimo_accedido->siguiente == nullptr){
    //para ver si es el ultimo elemento
        aux=ultimo_accedido;
        ultimo_accedido=inicio;
        //le asigno el inicio para que se pueda volver a loopear
    }
    else {
        aux=ultimo_accedido;
        ultimo_accedido=ultimo_accedido->siguiente;
    }
    return aux->elemento;
}

template <typename T>
Lista<T>:: ~Lista() //complejidad lineal creo
{
    eliminar(inicio);
    inicio=nullptr;
    ultimo_accedido=nullptr;
    fin=nullptr;
    cantidad=0;
}

template class Lista<Libro>;
template class Lista <int>;
template class Lista<string>;
template class Lista<char>;
//obvio que hay que corregirle cosas, onda lo que imprime y eso
