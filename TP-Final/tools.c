/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "aliens.h"
#include "main.h"
#include "ship.h"
#include "muros.h"
#include <stdbool.h>
typedef struct {
    int active;
    int x;
    int y;
    
}SHOT;
/*
bool shots_collide(SHOT shot, POSITION pos, int mode) {
    bool ret = false;
    switch mode {
        case ALIEN_S:
            if ((shot.x>pos.x)&&(shot.x<pos.x+ALIEN_W)&&(shot.y<pos.y+ALIEN_H)&&(shot.y>pos.y))
                ret = true;
            break;
        case WALL_S:
            if ((shot.x>pos.x)&&(shot.x<pos.x+MURO_H)&&(shot.y<pos.y+MURO_H)&&(shot.y>pos.y))
                ret = true;
            break;
        case MOTHERSHIP_S:
            if ((shot.x>pos.x)&&(shot.x<pos.x+MOTHERSHIP_W)&&(shot.y<pos.y+MOTHERSHIP_H)&&(shot.y>pos.y))
                ret = true;
            break;
        case SHIP_S:
            if ((shot.x>pos.x)&&(shot.x<pos.x+SHIP_W)&&(shot.y<pos.y+SHIP_H)&&(shot.y>pos.y))
                ret = true;
            break;
    } 
    return ret;
}*/

