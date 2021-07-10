/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "aliens.h"
#include <stdbool.h>
#include "main.h"
#include <stdlib.h>
#include <time.h>
#include "ship.h"
#include "shots.h"

//la cantidad de aliens es siempre la misma, sin importar nivel

void aliens_init(ALIEN* aliens, int life) {

    int t;
    int columnas = 0;
    for (t = 0; t < ALIENS_N; t++) {
        int s = t / 11;
        columnas++;
        aliens[t].alive = true;
        if (t > ALIENS_N - 11) {
            aliens[t].fires = true;
        } else {
            aliens[t].fires = false;
        }
        aliens[t].lives = life;
        if (columnas >= COLS_N) {
            columnas = 0;
        }
        aliens[t].pos.x = REFERENCE_X + columnas;
        aliens[t].pos.y = REFERENCE_Y + s;
    }
}

void aliens_update(ALIEN aliens [], SHOT tiro) {
    int j;
    int i;
    int k = 0;
    bool fired = false;
    int columnas = COLS_N;
    srand(time(NULL));
    int direccion = 1;
    ALIEN p_disp [COLS_N];
    for (j = 0; j < ALIENS_N; j++) {
        aliens[j].pos.x += direccion*ALIEN_V;
        if ((aliens[j].alive)&&((aliens[j].pos.x >= DISP_W) || aliens[j].pos.x <= 0)) {
            direccion = -1 * direccion;
            for (i = 0; i < ALIENS_N; i++) {
                aliens[j].pos.x += direccion*ALIEN_V;
                aliens[j].pos.y += ALIEN_YV;
            }
        }
        if (aliens[j].shot)
            aliens[j].lives--;
        if (!aliens[j].lives) {
            aliens[j].alive = false;
            aliens[j].fires = false;
            aliens[j - COLS_N].fires = true;
        }
        if (aliens[j].fires) {
            p_disp [k] = aliens[j];
            k++;
        }
    }
    if (!fired) {
        int random = rand() % COLS_N;
        tiro.x = p_disp[random].pos.x;
        tiro.y = p_disp[random].pos.y;
        fired = true;
    }
    tiro.y += TIRO_V;
    //if (shots_collide()) {
    //fired=false;
    //}

    return;
}
/*
void mothership_init (MOTHERSHIP m) {
    m.alive=true;
    m.pos.y=SCREEN_HEIGHT/9;
    m.direccion=rand(time(NULL))/2;
    if (m.direccion) {
        m.pos.x=SCREEN_WIDTH-MOTHERSHIP_W;
    }
    else {
        m.pos.x=0;
    }
    m.timer=MOTHERSHIP_TIMER;
}

void mothership_update (MOTHERSHIP m) {
    
}*/