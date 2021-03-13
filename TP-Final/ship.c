/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "ship.h"
#include "main.h"
#include <stdbool.h>

typedef struct{
    int x;
    int y;
    bool alive;//1 esta vivo, 0 muerto
    bool shot;//1 es que su disparo esta activo
}SHIP;



SHIP ship_init(SHIP ship)
{
    ship.x = SCREEN_WIDTH /2 ;
    ship.y = 10*SCREEN_HEIGHT/100;
    ship.alive = 1;
    ship.shot = 0;
    return SHIP;
}


/*shift puede ser positivo o negativo*/
SHIP ship_update(SHIP ship ,int shift, bool shoot,bool die)
{
    if( !( ship.x + shift > SCREEN_WIDTH || ship.x + shift < 0 ) )
        ship.x += SHIFT_ALLEGRO_SPEED;
    if(shoot)
        ;//shoot(ship.x, upwards)
    if(die)
        ship.alive = 0;
    return SHIP;
}



