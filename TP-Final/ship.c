/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "ship.h"
#include "main.h"
#include <stdbool.h>





SHIP ship_init()
{
    SHIP ship;
    ship.x = SCREEN_WIDTH /2 ;
    ship.y = SCREEN_HEIGHT/2;
    ship.alive = 1;
    ship.shot_active = 0;
    return ship;
}


/*shift puede ser positivo o negativo*/
SHIP ship_update(SHIP ship ,int shift, bool shoot)
{
    if( !( ship.x + shift > SCREEN_WIDTH || ship.x + shift < 0 ) )
        ship.x += SHIFT_SPEED;
    if(shoot && !ship.shot_active)
    {
        ship.shot_active;
        ship.shot_x = ship.x;
        ship.shot_y = ship.y;
    }
    if(ship.shot_active)
    {
        ship.shot_x += SHOT_SPEED;
    }
    return ship;
}



