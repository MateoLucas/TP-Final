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

#ifndef ALIENS_H
#define ALIENS_H

#define ALIEN_POS_REFERENCE_X
#define ALIEN_POS_REFERENCE_Y
#define ALIEN_V 2
#define ALIEN_YV 5
#include <stdbool.h>

typedef struct {
    int x;
    int y;
    int lives;
    bool alive;
    bool shot;
    bool fires;
    int shot_x;
    int shot_y;

}ALIEN;

#endif /* ALIENS_H */

