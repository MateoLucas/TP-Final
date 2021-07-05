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

int main() 
{
    
    must_init(al_init(), "allegro");    
    
    must_init(al_install_keyboard(), "keyboard");
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
     must_init(timer, "timer");
  ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");
    
    ALIEN alien[ALIENS_N];
    SHIP ship;
    MURO muro_arr[MURO_N];

    
    ship = ship_init();
    
    
#ifndef RASP
    ALLEGRO_DISPLAY* disp;//display
    disp = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    ALLEGRO_BITMAP* ship_image = al_load_bitmap("x-wing.png");
#endif
    
    unsigned char key[ALLEGRO_KEY_MAX];
    memset(key, 0, sizeof(key));
   
    
     must_init(al_init_image_addon(), "image");
     must_init(al_init_primitives_addon(), "primitives");



  
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
      al_register_event_source(queue, al_get_timer_event_source(timer));
    ALLEGRO_EVENT event;
    bool done = false;
    bool pause = false;
    bool redraw = true;
    al_start_timer(timer);
    while(1)//juego
    {
        printf("entra al while\n");
        al_wait_for_event(queue, &event);

        switch(event.type)
        {


            case ALLEGRO_EVENT_TIMER:
                printf("allegro event timer\n");
                if(!pause)
                {                   
                    printf("ship update\n");
                    ship_update(ship ,0, false);
                    ship_draw(ship, ship_image);
                    al_flip_display();
                    printf("sale del ship update\n");
                    //aliens_update();
                    //muro_update();
                }
                /*
                if(key[ALLEGRO_KEY_P])//corregir
                {
                    printf("entra a la pausa\n");
                    pause = pause ? false : true;
                    //al_rest(1);
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
                {
                    printf("entra al escape\n");
                    done = true;
                }
                redraw = true;
                break;

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                printf("entra a disp close\n");
                done = true;
                break;
           
        }
        printf("antes de checkear el donde");

        if(done)
            break;

        keyboard_update(&event,0);
        printf("antes de ponerse a dibujar\n");
        if(redraw && al_is_event_queue_empty(queue))
        {
            printf("se pone a dibujar\n");
            al_clear_to_color(al_map_rgb(0,255,0));

            //aliens_draw();

            ship_draw(ship, ship_image);
            //muro_draw();


            al_flip_display();
            redraw = false;
        }

    }
        
    
    
    
    al_destroy_display(disp);
    al_destroy_bitmap(ship_image);
    al_destroy_event_queue(queue);
    return 0;
}

