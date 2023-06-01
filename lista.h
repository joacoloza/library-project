#ifndef LISTA_H
#define LISTA_H
using namespace std;
template <typename T>
class Lista
{
    public:
    Lista();

    void agregar_inicio (const T & elem);
    //agrega un nodo al incio

    void insertar_lista(const T & elem, unsigned int pos );
    //agrega un nodo entre dos nodos, de manera ordenada

    void agregar_alfinal(const T & elem);
    //agrega un nodo al final

    int longlista ()const;
    //devuelve la longitud de la lista

    void insertar_ordenado(const T & elemento);
    //inserta un nodo en la lista de manera ordenada se usa en el punto  3

    const T & devolver_siguiente ();
    //recorre la lista

    ~Lista();
    //destructor

    private:
    struct nodo
    {
        nodo *siguiente;
        //el puntero al siguiente nodo
        T elemento;
        // elementos que puede contener la lista
    };
    //la estructura del nodo
    nodo *inicio;
    nodo* fin;
    unsigned int cantidad;
    //lleva un control de la longituda de la lista
    nodo* ultimo_accedido;
    //para tener una referencia
    void eliminar(nodo*inicio);
    //elimina un nodo de la lista
};
#endif // LISTASIMPLE_H_INCLUDED
