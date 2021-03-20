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
#include <stdbool.h>

#include "aliens.h"
#include "ship.h"
#include "main.h"
#include "aliens.h"
#include "muros.h"
#include "allegro.h"
#define COLS_N 11

int main(int argc, char** argv) 
{
    
    must_init(al_init(), "allegro");    
    must_init(al_install_keyboard(), "keyboard");

    ALIEN alien[ALIENS_N];
    SHIP ship;
    MURO muro_arr[MURO_N];

    
    ship = ship_init(ship);
    
    
    
    ALLEGRO_DISPLAY* disp;//display
    disp = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    unsigned char key[ALLEGRO_KEY_MAX];
    memset(key, 0, sizeof(key));
   
    

    ALLEGRO_BITMAP* ship_image = al_load_bitmap("x-wing.png");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    ALLEGRO_EVENT event;
    bool done = false;
    bool pause = false;
    while(1)//juego
    {
        al_wait_for_event(queue, &event);

        switch(event.type)
        {


            case ALLEGRO_EVENT_TIMER:
                if(!pause)
                {                          
                    ship_update(ship ,0, false);
                    //aliens_update();
                    //muro_update();
                }

                if(key[ALLEGRO_KEY_P])//corregir
                {
                    pause = pause ? false : true;
                    al_rest(1);
                }
                /*
                if(key[ALLEGRO_KEY_S])
                {
                    int save;
                    //save = save_game();
                    if(!save==NULL)
                        printf("save error!");
                }
                if(key[ALLEGRO_KEY_L])//corregir
                {
                    int load;
                    //load = load_game();
                    if(load == NULL)
                        printf("load error!");
                }
                 * */
                if(key[ALLEGRO_KEY_ESCAPE])
                    done = true;

                break;

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }

        if(done)
            break;

        keyboard_update(&event,0);

        if(al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(0,0,0));

            //aliens_draw();

            ship_draw(ship, ship_image);
            //muro_draw();


            al_flip_display();
        }

    }
        
    
    
    
    al_destroy_display(disp);
    al_destroy_bitmap(ship_image);
    al_destroy_event_queue(queue);
    return 0;
}

