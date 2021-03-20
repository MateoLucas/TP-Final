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
        aliens[t].x = REFERENCE_X + columnas;
        aliens[t].y = REFERENCE_Y + s;
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
        aliens[j].x += direccion*ALIEN_V;
        if ((aliens[j].alive)&&((aliens[j].x >= SCREEN_WIDTH) || aliens[j].x <= 0)) {
            direccion = -1 * direccion;
            for (i = 0; i < ALIENS_N; i++) {
                aliens[j].x += direccion*ALIEN_V;
                aliens[j].y += ALIEN_YV;
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
        tiro.x = p_disp[random].x;
        tiro.y = p_disp[random].y;
        fired = true;
    }
    tiro.y += TIRO_V;
    //if (shots_collide()) {
    //fired=false;
    //}

    return;
}