#ifndef PINTAR_H
#define PINTAR_H

#include "ConjuntoCuadrados.hpp"
#include "Cuadrado.hpp"
#include "raylib.h"
#include "Parametros.hpp"

void PintaCuadrado(const Cuadrado & c, Color color);
void PintaConjunto(const ConjuntoCuadrados & c, Color color);


#endif