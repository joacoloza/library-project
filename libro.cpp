#include "libro.h"
#include "lista.h"

Libro::Libro(){
}

Libro::Libro(string isbn, string titulo, string autor, string editorial,int paginas, int anioed, string nroed,string precio,int ventas,Lista<string>*generos)
{
    this->isbn=isbn;
    this->titulo=titulo;
    this->autor=autor;
    this->editorial=editorial;
    this->paginas=paginas;
    this->anioed=anioed;
    this->nroed=nroed;
    this->precio=precio;
    this->ventas=ventas;
    this->generos=generos;
}

void Libro::cargarL(string isbn, string titulo, string autor, string editorial,int paginas, int anioed, string nroed,string precio,int ventas,Lista<string>*generos)
{
    this->isbn=isbn;
    this->titulo=titulo;
    this->autor=autor;
    this->editorial=editorial;
    this->paginas=paginas;
    this->anioed=anioed;
    this->nroed=nroed;
    this->precio=precio;
    this->ventas=ventas;
    this->generos=generos;
    //creo que  generos no va con this
}

string Libro::isbnL()const{
return this->isbn;
}

string Libro::tituloL()const{
return this->titulo;
}

string Libro::autorL()const{
return this->autor;
}

string Libro::editorialL()const{
return this->editorial;
}

int Libro::paginasL()const{
return this->paginas;
}

int Libro::anioedL()const{
return this->anioed;
}

string Libro::nroedL()const{
    return this->nroed;
}

string Libro::precioL()const{
    return this->precio;
}

int Libro::ventasL()const{
    return this->ventas;
}

Lista<string> *Libro::generosL()const{
    return this->generos;
}

bool Libro::operator<(const Libro& libro_comparacion)const{
    if (this->ventas < libro_comparacion.ventasL()){
        return true;
    }
    else
    return false;
}

bool Libro::operator<=(const Libro& libro_comparacion)const{
    if (this->ventas <= libro_comparacion.ventasL()){
        return true;
    }
    else
    return false;
}

bool Libro::operator>(const Libro& libro_comparacion)const{
    if (this->ventas > libro_comparacion.ventasL()){
        return true;
    }
    else
    return false;
}

bool Libro::operator>=(const Libro& libro_comparacion)const{
    if (this->ventas >= libro_comparacion.ventasL()){
        return true;
    }
    else
    return false;
}
