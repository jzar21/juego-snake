#include "ConjuntoCuadrados.hpp"
#include "Cuadrado.hpp"
#include <assert.h>

ConjuntoCuadrados::ConjuntoCuadrados(){
    v = 0; 
    tam = 0;
}

void ConjuntoCuadrados::Limpiar(){
    delete [] v;
    v = 0;
    tam = 0;
}

ConjuntoCuadrados::~ConjuntoCuadrados(){
    Limpiar();
}

void ConjuntoCuadrados::Copiar(const ConjuntoCuadrados & otro){
    assert(v == 0);
    tam = otro.tam;
    v = new Cuadrado [tam];
    for(int i = 0; i < tam; i++)
        v[i] = otro[i];
}

ConjuntoCuadrados::ConjuntoCuadrados(const ConjuntoCuadrados & otro){
    Copiar(otro);
}

ConjuntoCuadrados & ConjuntoCuadrados::operator=(const ConjuntoCuadrados & otro){
    if(this != &otro){
        Limpiar();
        Copiar(otro);
    }
    return *this;
}

bool ConjuntoCuadrados::Pos_Valida(int pos) const{
    return pos >= 0 && pos < tam;
}

Cuadrado & ConjuntoCuadrados::operator[](int pos){
    assert(Pos_Valida(pos));
    return v[pos];
}

const Cuadrado & ConjuntoCuadrados::operator[](int pos) const{
    assert(Pos_Valida(pos));
    return v[pos];
}

int ConjuntoCuadrados::GetTamano() const{
    return tam;
}

void ConjuntoCuadrados::Redimensiona(int n){
    if(n > 0){
        Cuadrado * copia = new Cuadrado [n];
        for(int i = 0; i < tam && i < n; i++)
            copia[i] = v[i];

        delete [] v;
        v = copia;
        copia = 0;
    }
}

ConjuntoCuadrados & ConjuntoCuadrados::operator+=(const Cuadrado & otro){
    Redimensiona(tam + 1);
    v[tam++] = otro;
    return *this;
}

void ConjuntoCuadrados::MoverConjunto(int ancho, int alto){
    for(int i = tam - 1 ; i > 0; i--)
        v[i] = v[i - 1];
    v[0].Mover(ancho, alto);
}

void ConjuntoCuadrados::MoverConjunto(char dir, int ancho, int alto){
    for(int i = tam - 1 ; i > 0; i--)
        v[i] = v[i - 1];
    v[0].MoverFlechas(dir, ancho, alto);
}

ConjuntoCuadrados::ConjuntoCuadrados(const Cuadrado & c) :ConjuntoCuadrados(){
    (*this) += c;
}