#ifndef CUADRADO_HPP
#define CUADRADO_HPP

#include <cmath>

class Cuadrado{
private:
    int x, y, lado, dx, dy;

    void Ajustar(int ancho, int alto);
public:
    Cuadrado();
    Cuadrado(int x, int y, int lado, int dx, int dy);

    int GetX(void) const;
    int GetY(void) const;
    int GetLado(void) const;
    int GetDX(void) const;
    int GetDY(void) const;

    void SetX(int x);
    void SetY(int y);
    void SetLado(int lado);
    void SetDX(int dx);
    void SetDY(int dy);

    void Mover(int ancho, int alto);
    void MoverFlechas(char dir, int ancho, int alto);
    float Distancia(const Cuadrado & otro) const;
    bool operator ==(const Cuadrado & otro) const;
    bool operator !=(const Cuadrado & otro) const;
    Cuadrado & operator = (const Cuadrado & otro);
};

#endif