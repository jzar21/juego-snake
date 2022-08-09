#include "Cuadrado.hpp"
#include <cmath>

Cuadrado::Cuadrado(){
    x = y = lado = dx = dy = 0;
}

Cuadrado::Cuadrado(int x, int y, int lado, int dx, int dy){
    this->x = x;
    this->y = y;
    this->lado = std::abs(lado);
    this->dx = dy;
    this->dy = dy;
}

int Cuadrado::GetDX(void) const{
    return dx;
}
int Cuadrado::GetDY(void) const{
    return dy;
}
int Cuadrado::GetX(void) const{
    return x;
}
int Cuadrado::GetY(void) const{
    return y;
}
int Cuadrado::GetLado(void) const{
    return lado;
}

void Cuadrado::SetDX(int dx){
    this->dx = dx;
}
void Cuadrado::SetDY(int dy){
    this->dy = dy;
}
void Cuadrado::SetX(int x){
    this->x = x;
}
void Cuadrado::SetY(int y){
    this->y = y;
}
void Cuadrado::SetLado(int lado){
    this->lado = std::abs(lado);
}

void Cuadrado::Ajustar(int ancho, int alto){
    if(x < 0)//se sale por la izd
        x = 0;
    if(x > ancho - lado)//se sale por la derecha
        x = ancho - lado;
    if(y < 0)//se sale por arriba
        y = 0;
    if(y > alto - lado)//se sale por abajo
        y = alto - lado;
}

void Cuadrado::Mover(int ancho, int alto){
    x += dx;
    y += dy;
    Ajustar(ancho, alto);
}

void Cuadrado::MoverFlechas(char dir, int ancho, int alto){
    if(dir == 'U')
        y -= dy;
    else if(dir == 'D')
        y += dy;
    else if(dir == 'L')
        x -= dx;
    else if(dir == 'R')
        x += dx;
    Ajustar(ancho, alto);
    
}

float Cuadrado::Distancia(const Cuadrado & otro) const{
    float diff_x = x - otro.x;
    float diff_y = y - otro.y;

    return sqrt(diff_x * diff_x  +  diff_y * diff_y);
}

bool Cuadrado::operator==(const Cuadrado & otro) const{
    bool iguales = Distancia(otro) <= lado;
    return iguales;
}

Cuadrado & Cuadrado::operator=(const Cuadrado & otro){
    x = otro.x;
    y = otro.y;
    lado = otro.lado;
    dx = otro.dx;
    dy = otro.dy;
    return *this;
}

bool Cuadrado::operator !=(const Cuadrado & otro) const{
    bool no_iguales = !( (*this) == otro );
    return no_iguales;
}