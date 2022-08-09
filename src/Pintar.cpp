#include "ConjuntoCuadrados.hpp"
#include "Cuadrado.hpp"
#include "raylib.h"
#include "Parametros.hpp"
#include "Pintar.hpp"


void PintaCuadrado(const Cuadrado & c, Color color){
    DrawRectangle(c.GetX(), c.GetY(), c.GetLado(), c.GetLado(), color);
}

void PintaConjunto(const ConjuntoCuadrados & c, Color color){
    for(int i = c.GetTamano() - 1; i >= 0; i--)
        if(i == 0)
            PintaCuadrado(c[i], RED);
        else
            PintaCuadrado(c[i], color);


}