#include <iostream>
#include "lista.h"
#include "libro.h"
#include <cstring>
#include <fstream>
#include <clocale>

using namespace std;
//INICIO FUNCIONES DEL PROBLEMA 1
void convertirminusculas(string & palabra)
{
    for (int i=0;i<palabra.length();i++){
        palabra[i]=tolower(palabra[i]);
    }
}

void imprimir_generos(Lista<string>*generos){
    string genero;
    for (int i=0;i<generos->longlista();i++){
        genero=generos->devolver_siguiente();
        cout<<genero<<"|";
    }
}

void imprimirlibro(Libro libro,int & i){
    cout<<"libro: "<<i<<endl;
    Lista<string>*generos;
    string genero;
    generos=libro.generosL();
    cout<<"TITULO: "<<libro.tituloL()<<endl;
    cout<<"AUTOR: "<<libro.autorL()<<endl;
    cout<<"PAGINA: "<<libro.paginasL()<<endl;
    cout<<"PRECIO: "<<libro.precioL()<<endl;
    cout<<"EDITORIAL: "<<libro.editorialL()<<endl;
    cout<<"ANIO EDITORIAL: "<<libro.anioedL()<<endl;
    imprimir_generos(libro.generosL());
    cout<<endl<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
}


bool matcheo (char* buscado, char*  nombre)
{
    if (*buscado == '\0'&& *nombre=='\0'){
        return true;
    }
    if(*buscado=='*'&& *(buscado+1) != '\0' && *nombre =='\0'){
        return false;}
    if (*buscado=='?'||*buscado==*nombre){
        return matcheo((buscado+1),(nombre+1));
    }
    if (*buscado=='*'){
        return matcheo((buscado+1),nombre) || matcheo(buscado,(nombre+1));
    }
    return false;
}

void problema1(Lista<Libro>*biblioteca){
    string buscar,extraido;
    Libro data_libro=biblioteca->devolver_siguiente();
    extraido=data_libro.tituloL();
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"ingrese libro a buscar: ";
    cin.ignore();
    getline(cin,buscar);
    convertirminusculas(buscar); //convertirminusculas--->es una funcion que convierte todos los caracteres en minuscula
    convertirminusculas(extraido);
    int j=1;
    bool encontro=false;
    cout<<"------------------------------------------------------------------"<<endl;
    for (int i=0; i<biblioteca->longlista();i++){
        Libro data_libro=biblioteca->devolver_siguiente();
        extraido=data_libro.tituloL();
        convertirminusculas(extraido);
        if (matcheo(&buscar[0],&extraido[0])){
            encontro=true;
            imprimirlibro(data_libro,j);
            j++;
        }
    }
    if (encontro==false){
        cout<<"No se encontraron coincidencias."<<endl;
        cout<<"------------------------------------------------------------------"<<endl;
    }
}
//FIN FUNCIONES PROBLEMA 1

/* aclarar en la documentacion que el asterisco toma todas las palabras que hay despues de el
En caso de tener tildes la palabra,esta funcion nos ayudaria a quitar las tildes
terminan las funciones del problema 1*/

//FUNCIONES DEL PROBLEMA 2
void imprimir_entre_anios(Lista<Libro>* libreria,int p, int q,int posicion){
    //este imprimir imprime los libros del problema 2
    int numero=1;
    cout<<"los libros correspondientes a esos años son : "<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    for (int i =0; i<libreria->longlista();i++){
        Libro data_libro = libreria->devolver_siguiente();
        if ((data_libro.anioedL() >=p) && (data_libro.anioedL()<=q)){
        //corrobora que el libro actual este entre cotas
            imprimirlibro(data_libro,numero);
            numero++;
        }
    }
}

void problema2(Lista<Libro>*libreria){
    cout<<"entro a problema 2"<<endl;
    int p,q;
    cout<<"ingrese el primer anio"<<endl;
    cin>>p;
    cout<<"ingrese hasta que anio quiere buscar"<<endl;
    cin>>q;
    cout<<"------------------------------------------------------------------"<<endl;
    if (p<=q)
        imprimir_entre_anios(libreria,p,q,0);
    else
        imprimir_entre_anios(libreria,q,p,0);
}
//FIN FUNCIONES PROBLEMA 2

//INICIO FUNCIONES PROBLEMA 3
void imprimir_diez(Lista<Libro>* listamasvendidos){
    int solo_diez=0;
    //solo_diez es una variable que cuenta hasta 10 para solamente imprimir los 10 mas vendidos
    for (int i =0; i<listamasvendidos->longlista();i++){
        if (solo_diez<10){
        Libro data_libro = listamasvendidos->devolver_siguiente();
        cout<<"libro: "<<solo_diez<<endl;
        cout<<"------------------------------------------------------------------"<<endl;
        cout<<"titulo: "<<data_libro.tituloL()<<endl;
        cout<<"autor: "<<data_libro.autorL()<<endl;
        cout<<"editorial: "<<data_libro.editorialL()<<endl;
        cout<<"anio de edicion: "<<data_libro.anioedL()<<endl;
        cout<<"precio: "<<data_libro.precioL()<<endl;
        cout<<"------------------------------------------------------------------"<<endl;
        solo_diez++;
        }
        else {return;}
    }
}
bool coincide (Lista<string>*generoL,string genero){
    string genero_libro;
    for (int i =0; i<generoL->longlista();i++){  //recorro la lista
        genero_libro=generoL->devolver_siguiente(); //le doy valor al string genero
        convertirminusculas(genero_libro);
        convertirminusculas(genero);
        if(genero_libro.compare(genero)==0){ //compare es una funcion que compara dos tipo strings y devuelve 0 si coinnciden
            return true;
        }
    return false;
    }
}
void recorrer_agregar(Lista<Libro>*libreria,Lista<Libro>*& listamasvendidos,string genero){
    //recorre la libreria y va agregando a la lista mas vendidos
    for (int i =0; i<libreria->longlista();i++){
        Libro data_libro = libreria->devolver_siguiente();
        if (coincide(data_libro.generosL(),genero)){
            listamasvendidos->insertar_ordenado(data_libro);
        }
    }
}

void problema3(Lista<Libro>* libreria){
    cout<<"seleccione un genero"<<endl;
    string genero;
    cin>>genero;
    Lista<Libro>* listamasvendidos= new Lista<Libro>;
    recorrer_agregar(libreria,listamasvendidos,genero);
    cout<<"los libros que pertenecen al genero "<<genero<<" son:"<<endl;
    imprimir_diez(listamasvendidos);
    //No ha sido reutilizado el imprimir,ya que este tiene como condicion que no ocupe mas de 10 espacios de memoria(formando asi el top 10)
    listamasvendidos->~Lista();
    if (listamasvendidos!=nullptr)
        cout<<"se elimino lista"<<endl;
    //elimino el espacio en memoria de la lista
}
//FIN FUNCIONES PROBLEMA 3

//FUNCION EXTRA:IMPRIMIR LISTA
void imprimir_libreria(Lista<Libro>*libreria){
    Libro libro;
    for (int i=1;i<=libreria->longlista();i++){
        libro=libreria->devolver_siguiente();
        imprimirlibro(libro,i);
    }
}

//MENU PRINCIPAL
void servicio_libreria(Lista<Libro>*libreria){
    cout<<"                    BIENVENIDO AL SERVICIO DE BUSQUEDA "<<endl<<endl;
    cout<<"Seleccione una opcion: "<<endl<<endl;
    cout<<"(0)Salir"<<endl;
    cout<<"(1)Buscar libro por titulo (puede usar * para ignorar letras y ? para palabras)"<<endl;
    cout<<"(2)Buscar libros entre un rango de anios"<<endl;
    cout<<"(3)Buscar libros a partir de su genero"<<endl;
    cout<<"(4)Ver todos los libros disponibles"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    int c;
    cout<<"ingrese numero:"<<endl;cin>>c;
    while (c !=0){
        if ((c !=0)&&(c!=1)&&(c!=2)&&(c!=3)&&(c!=4)){
            cout<<"- ¡selecciono un numero incorrecto,por favor vuelva a ingresar un numero!-"<<endl<<endl;
            cout<<"(0)Salir"<<endl;
            cout<<"(1)Buscar libro por titulo (puede usar * para ignorar letras y ? para palabras)"<<endl;
            cout<<"(2)Buscar libros entre un rango de anios"<<endl;
            cout<<"(3)Buscar libros a partir de su genero"<<endl;
            cout<<"(4)Ver todos los libros disponibles"<<endl;
            cout<<"------------------------------------------------------------------"<<endl;
            cout<<"Ingrese numero:"<<endl;cin>>c;
            }
        if (c==1){
            cout<<"Problema 1: "<<endl<<endl;
            problema1(libreria);
            }
        else if (c==2){
            cout<<"Problema 2: "<<endl<<endl;
            problema2(libreria);
            }
        else if(c==3){
            cout<<"Problema 3: "<<endl<<endl;
            problema3(libreria);
            }
        else if (c==4){
            cout<<"LIBRERIA: "<<endl;
            imprimir_libreria(libreria);
        }
        cout<<"(0)Salir"<<endl;
        cout<<"(1)Buscar libro por titulo (puede usar * para ignorar letras y ? para palabras)"<<endl;
        cout<<"(2)Buscar libros entre un rango de anios"<<endl;
        cout<<"(3)Buscar libros a partir de su genero"<<endl;
        cout<<"(4)Ver todos los libros disponibles"<<endl;

        cout<<"------------------------------------------------------------------"<<endl;
        cout<<"Ingrese numero:"<<endl;cin>>c;

        if ((c !=0)&&(c!=1)&&(c!=2)&&(c!=3)&&(c!=4)){
            cout<<"-¡selecciono un numero incorrecto,por favor vuelva a ingresarlo!-"<<endl;
            cout<<"(0)Salir"<<endl;
            cout<<"(1)Buscar libro por titulo (puede usar * para ignorar letras y ? para palabras)"<<endl;
            cout<<"(2)Buscar libros entre un rango de anios"<<endl;
            cout<<"(3)Buscar libros a partir de su genero"<<endl;
            cout<<"(4)Ver todos los libros disponibles"<<endl;
            cout<<"------------------------------------------------------------------"<<endl;
            cout<<"ingrese numero:"<<endl;cin>>c;}
    }
    cout<<"¡GRACIAS POR USAR NUESTRO SERVICIO :D!"<<endl;
}

//Comentarios: atoi y atof requieren un char * para converter a número, usamos c_str de la clase string.
void procesar_archivo_entrada(string origen,Lista<Libro>* libros)
{
    ifstream archivo(origen);
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else{
        string linea;
        getline(archivo, linea);
        int cantidad_libros = atoi(linea.c_str());
        //Leemos de una linea completa por vez (getline).
        int nroLibro = 1;
        while (getline(archivo, linea)) {
            //Primer posición del separador ;
            int pos_inicial = 0;
            int pos_final = linea.find(',');

            //int idLibro = 1;

            //Informacion entre pos_inicial y pos_final
            string idLibro = linea.substr(pos_inicial, pos_final);

            //Segunda posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string titulo = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Tercera posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string autor = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Cuarta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string editorial = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Quinta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            int anio = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            //Sexta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string nro_edicion = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Septima posición del separador ;
            //Creacion de la lista de generos(cada genero tiene su respectivo puntero)
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string genero = linea.substr(pos_inicial, pos_final - pos_inicial);
            Lista <string>*generos=new Lista<string>;
            int i=1,f=genero.find("|",i);
            string genero2;
            while (f !=-1){
                genero2=genero.substr(i,f-i);
                //cout<<"GENERO: "<<genero2<<endl;
                i=f+1;
                f=genero.find("|" ,i);
                generos->agregar_inicio(genero2);
                }
            f=genero.find("]" ,i);
            genero2=genero.substr(i,f-i);
            //cout<<"GENERO: "<<genero2<<endl;
            generos->agregar_inicio(genero2);

            //Octava posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            int nro_paginas = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            //Novena posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            int ejemplares_vendidos = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            //Decima posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string precio = linea.substr(pos_inicial, pos_final - pos_inicial);
            Libro *libro=new Libro();
            //Lista<Libro> libros=new Lista<Libro>;
            libro->cargarL(idLibro,titulo,autor,editorial,nro_paginas,anio,nro_edicion,precio,ejemplares_vendidos,generos);
            libros->agregar_inicio(*libro);

            nroLibro++;
        }
    }
}


int main(){
    setlocale(LC_ALL, ""); //asegurarse que el archivo de texto fue guardado como Ansi y no como Unicode
    Lista<Libro>*libreria= new Lista<Libro>;
    procesar_archivo_entrada("libros.csv",libreria); //la lista libreria es la lista que representa la libreria
    servicio_libreria(libreria);
    libreria->~Lista(); //elimino el espacio de memoria de la libreria
    return 0;
}
//TPE VERSION FINAL.
