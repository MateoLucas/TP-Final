/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: mateo
 *
 * Created on December 20, 2020, 11:33 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>

#include "aliens.h"
#include "ship.h"
#include "main.h"

int main(int argc, char** argv) {

    ALIEN alien[ALIENS_N];
    SHIP ship;
    MURO muro_arr[MURO_N];

    
    ship = SHIP ship_init(SHIP ship);
    
    
    int i;
    for(i=0;i<ALIENS_N;i++)
    {
        alien[i] = alien_init();
    }
    
    
    
    
    
    
    
    return (EXIT_SUCCESS);
}

