/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   allegro.h
 * Author: mateo
 *
 * Created on March 14, 2021, 10:56 AM
 */

#ifndef ALLEGRO_H
#define ALLEGRO_H
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <stdbool.h>
void must_init(bool test, const char *description);
unsigned char keyboard_update(ALLEGRO_EVENT* event, unsigned char* key);
//void ship_draw(SHIP ship,ALLEGRO_BITMAP* ship_image);
void keyboard_init();

#endif /* ALLEGRO_H */

