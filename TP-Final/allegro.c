/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include "ship.h"

#define BUFFER_W 280
#define BUFFER_H 250

#define DISP_SCALE 3
#define DISP_W (BUFFER_W * DISP_SCALE)
#define DISP_H (BUFFER_H * DISP_SCALE)
#define KEY_SEEN     1
#define KEY_RELEASED 2
void must_init(bool test, const char *description)
{
    if(test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}
unsigned char keyboard_update(ALLEGRO_EVENT* event, unsigned char* key)
{
    switch(event->type)
    {
        case ALLEGRO_EVENT_TIMER:
            for(int i = 0; i < ALLEGRO_KEY_MAX; i++)
                return (key[i] &= KEY_SEEN);
            break;

        case ALLEGRO_EVENT_KEY_DOWN:
            return (key[event->keyboard.keycode] = KEY_SEEN | KEY_RELEASED);
            break;
        case ALLEGRO_EVENT_KEY_UP:
            return (key[event->keyboard.keycode] &= KEY_RELEASED);
            break;
    }
}

void ship_draw(SHIP ship,ALLEGRO_BITMAP* ship_image)
{
    if(ship.alive == false)
        return;
    al_draw_bitmap(ship_image, ship.x, ship.y, 0);
}


