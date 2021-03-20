/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   aliens.h
 * Author: mateo
 *
 * Created on March 13, 2021, 11:38 AM
 */

#include "position.h"

#ifndef ALIENS_H
#define ALIENS_H

#define ALIEN_POS_REFERENCE_X
#define ALIEN_POS_REFERENCE_Y
#define ALIEN_V 2
#define ALIEN_YV 5
#define REFERENCE_X 10
#define REFERENCE_Y 10
#include <stdbool.h>

typedef struct {
    POSITION pos; 
    int lives;
    bool alive;
    bool shot;
    bool fires;
}ALIEN;

typedef struct {
    POSITION pos;
    bool alive;
    short direccion;
    int timer;
}MOTHERSHIP;
#endif /* ALIENS_H */

