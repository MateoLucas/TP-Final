/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "ship.h"
#include "main.h"
#include <stdbool.h>
//#define DEBUG




SHIP ship_init()
{
    SHIP new_ship;
    new_ship.x = BUFFER_W/2 ;
    new_ship.y = (70*BUFFER_H)/100;//10%
    new_ship.alive = true;
    return new_ship;
}


/*shift puede ser positivo o negativo*/
SHIP ship_update(SHIP ship ,int shift, bool shoot)
{
    if( !( ship.x + shift > DISP_W|| ship.x + shift < 0 ) )
        ship.x += SHIFT_SPEED;
    if(shoot && !ship.shot_active)
    {
        ship.shot_active;
        ship.shot_x = ship.x;
        ship.shot_y = ship.y;
    }
    if(ship.shot_active)
    {
        ship.shot_y += SHOT_SPEED;
    }
    return ship;
}







