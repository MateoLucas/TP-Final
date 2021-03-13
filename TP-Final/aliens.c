/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "aliens.h"
#include <stdbool.h>
#define ALIENS_N
//la cantidad de aliens es siempre la misma, sin importar nivel
typedef struct {
    int x;
    int y;
    int lives;
    bool alive;
    bool shot;

}ALIEN;

ALIEN alien[ALIENS_N];



