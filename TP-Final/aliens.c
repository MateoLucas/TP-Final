/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "aliens.h"
#include <stdbool.h>
#include "main.h"

//la cantidad de aliens es siempre la misma, sin importar nivel
typedef struct {
    int x;
    int y;
    int lives;
    bool alive;
    bool shot;
    bool fires;
    int shot_x;
    int shot_y;

}ALIEN;


void aliens_init(ALIEN* aliens,int life)
{

    int t;
    int columnas = 0;
    for(t=0; t < ALIENS_N; t++)
    {
        int s = t/11;
        columnas++;
        aliens[t].alive = true;
        if (t > ALIENS_N-11) {
            aliens[t].fires = true;
        }
        else {
            aliens[t].fires = false;
        }
        aliens[t].lives = life;
        if(columnas >= N_COLS)
        {
            columnas=0;
        }
        aliens[t].x = REFERENCE_X + columnas*ALIEN_SPACE_BUFFER;
        aliens[t].y = REFERENCE_Y+ s* ALIEN_SPACE_BUFFER;
    }
}

void aliens_update (ALIEN* aliens) {
    int j;
    int i;
    int direccion = 1;
    for (j=0;j<ALIENS_N;J++) {
        aliens.x += direccion*ALIEN_V;
        if ((aliens[j].alive)&&((aliens[j].x >= SCREEN_W-ALIEN_W)||aliens[j].x<= 0)) {
                direccion=-1*direccion;
            for (i=0;i<ALIENS_N;i++) {
                aliens.x += direccion*ALIEN_V;
                aliens.y += ALIEN_YV
            }
        }
        if (shot)
            aliens.lives--;
        if (!aliens.lives)
            aliens.alive=false;
        
    }
}