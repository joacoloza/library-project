#ifndef LIBRO_H
#define LIBRO_H
#include <iostream>
#include "lista.h"
using namespace std;

class Libro{
    private:
        string isbn;
        string titulo;
        string autor;
        string editorial;
        int paginas;
        int anioed;
        string nroed;
        string precio;
        int ventas;
        Lista<string>* generos;
        //Variables que conforman el libro
    public:
        Libro();
        Libro(string isbn, string titulo, string autor, string editorial,int paginas, int anioed, string nroed,string precio,int ventas,Lista<string> *generos);
        void cargarL(string isbn, string titulo, string autor, string editorial,int paginas, int anioed, string nroed,string precio,int ventas,Lista<string> *generos); //constructora
        string isbnL()const;
        string tituloL()const;
        string autorL ()const;
        string editorialL()const;
        int paginasL()const;
        int anioedL ()const;
        string nroedL ()const;
        string precioL()const;
        int ventasL()const;
        Lista<string>* generosL()const;
        bool operator<(const Libro & libro_comparacion)const;
        bool operator<=(const Libro & libro_comparacion)const;
        bool operator>(const Libro & libro_comparacion)const;
        bool operator>=(const Libro & libro_comparacion)const;
        //Cada funcion retorna lo que se describe en su nombre
};
#endif



