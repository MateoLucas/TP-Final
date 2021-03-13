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

#define SHIFT_ALLEGRO_SPEED 5
SHIP ship_init(SHIP ship);
SHIP ship_update(SHIP ship ,int shift, bool shoot,bool die);

#endif /* SHIP_H */

