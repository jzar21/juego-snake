#include "ConjuntoCuadrados.hpp"
#include "Cuadrado.hpp"
#include "raylib.h"
#include "Parametros.hpp"
#include "Pintar.hpp"
#include <random>
#include <time.h>

char Direccion(){
    char dir = ' ';
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        dir = 'U';
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
        dir = 'D';
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
        dir = 'L';
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        dir = 'R';
    return dir;
}


int main(){
    InitWindow(ANCHO_PANTALLA, ALTO_PANTALLA, "SNAKE");
    SetTargetFPS(FPS);
    std::srand(time(0));

    Cuadrado comida(30, 30, LADO, 0, 0), inicial(100, 30, LADO, VELOCIDAD, VELOCIDAD);
    ConjuntoCuadrados serpiente(inicial);
    char dir = ' ';
    bool jugando = true;
    int p_x = LADO + rand() % ANCHO_PANTALLA - LADO;
    int p_y = LADO + rand() % ALTO_PANTALLA - LADO ;
    comida.SetX(p_x);
    comida.SetY(p_y);

    while(!WindowShouldClose()){
        if(jugando){

            if(Direccion() != ' '){
                dir = Direccion();
            }
            
            serpiente.MoverConjunto(dir, ANCHO_PANTALLA, ALTO_PANTALLA);
            for(int i = 1 ; i < serpiente.GetTamano() && jugando; i++)
                jugando = serpiente[0] != serpiente[i];

            if(serpiente[0] == comida){

                std::srand(time(0));
                int p_x = rand() % (ANCHO_PANTALLA - LADO);
                int p_y = rand() % (ALTO_PANTALLA - LADO);
                comida.SetX(p_x);
                comida.SetY(p_y);
                serpiente += serpiente[serpiente.GetTamano() - 1];
            }
            
            
        }
    
        BeginDrawing();
        if(! jugando)
            DrawText("HAS PERDIDO", ANCHO_PANTALLA / 2 - 12*10, ALTO_PANTALLA / 2- 20, 40, BLUE);
       
        ClearBackground(BLACK);
        PintaCuadrado(comida, GREEN);
        PintaConjunto(serpiente, WHITE);
        DrawFPS(10,10);
        EndDrawing();

    }

    CloseWindow();
    return 0;
}