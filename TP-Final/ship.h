/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ship.h
 * Author: mateo
 *
 * Created on March 13, 2021, 11:38 AM
 */

#ifndef SHIP_H
#define SHIP_H
#include <stdbool.h>

typedef struct{
    int x;
    int y;
    bool alive;//1 esta vivo, 0 muerto
    int shot_x;//posicion del tiro en x
    int shot_y;//posicion del tiro en y
    bool shot_active;//1 es que su disparo esta en el aire
}SHIP;

SHIP ship_init(SHIP ship);
SHIP ship_update(SHIP ship ,int shift, bool shoot);

#endif /* SHIP_H */

