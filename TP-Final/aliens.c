/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "aliens.h"
#include <stdbool.h>
#define ALIEN_POS_REFERENCE_X
#define ALIEN_POS_REFERENCE_Y
#define ALIEN_V 2
//la cantidad de aliens es siempre la misma, sin importar nivel
typedef struct {
    int x;
    int y;
    int lives;
    bool alive;
    bool shot;

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
            aliens[t].shot = true;
        }
        else {
            aliens[t].shot = false;
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
        if ((aliens[j].alive)&&((aliens[j].x >= BUFFER_W-ALIEN_W)||aliens[j].x<= 0)) {
            if (direccion)
                direccion=1;
            else
                direccion=-1;
            for (i=0;i<ALIENS_N;i++) {
                aliens.x += direccion*ALIEN_V;
                
            }
        }
        
    }
}