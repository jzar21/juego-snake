#ifndef CONJUNTOCUADRADOS_HPP
#define CONJUNTOCUADRADOS_HPP

#include "Cuadrado.hpp"
#include <assert.h>

class ConjuntoCuadrados{
private:
    Cuadrado * v;
    int tam;

    void Copiar(const ConjuntoCuadrados & otro);
    void Limpiar();
    bool Pos_Valida(int pos) const;
    void Redimensiona(int n);
public:
    ConjuntoCuadrados();
    ConjuntoCuadrados(const ConjuntoCuadrados & otro);
    ConjuntoCuadrados(const Cuadrado & c);

    ~ConjuntoCuadrados();
    

    int GetTamano() const;
    void MoverConjunto(int ancho, int alto);
    void MoverConjunto(char dir, int ancho, int alto);

    ConjuntoCuadrados & operator=(const ConjuntoCuadrados & otro);
    ConjuntoCuadrados & operator += (const Cuadrado &otro);

    Cuadrado & operator[](int pos);
    const Cuadrado & operator[](int pos) const;

};

#endif