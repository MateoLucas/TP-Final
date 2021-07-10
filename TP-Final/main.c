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
/*
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
    
    //ALIEN alien[ALIENS_N];
    SHIP ship;
    //MURO muro_arr[MURO_N];

    
    ship = ship_init();
    
    

    ALLEGRO_DISPLAY* disp;//display
    disp = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    ALLEGRO_BITMAP* ship_image = al_load_bitmap("x-wing.png");

    
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
                    printf("entra a ship draw y ve que esta vivo el ship\n");
                    al_draw_bitmap(ship_image, ship.x, ship.y, 0);
                    printf("le sale dibujar el ship\n");
                    al_flip_display();
                    
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
                 * 
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

            
            //ship_draw(ship, ship_image);
            //muro_draw();


            al_flip_display();
            redraw = false;
        }

    }
        
    
    
    
    al_destroy_display(disp);
    al_destroy_bitmap(ship_image);
    al_destroy_event_queue(queue);
    return 0;
}*/




#include "allegro.h"
#include "aliens.h"
#include "ship.h"
#include "main.h"




#define DEBUG


/*SAVE GAME 
 * 
 * 
 * guarda en el siguiente orden: Score ; 55 aliens(x,y,tipo,,shot timer, blink, life, used ),ship(x,y,shot_timer,lives,respawn_timer,invincible_timer)*/




// --- main ---




int main()
{
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");
    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    ALLEGRO_DISPLAY* disp;//display
    ALLEGRO_BITMAP* buffer;
    disp = al_create_display(DISP_W, DISP_H);
    must_init(disp, "display");
#ifdef DEBUG
    printf("display\n");
#endif
    buffer = al_create_bitmap(BUFFER_W, BUFFER_H);
    must_init(buffer, "bitmap buffer");
    long score;
    long frames;
#ifdef DEBUG
    printf("buffer\n");
#endif
    
    
    

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

#ifdef DEBUG
    printf("timer y queue\n");
#endif


    must_init(al_init_image_addon(), "image");
    must_init(al_init_primitives_addon(), "primitives");
#ifdef DEBUG
    printf("image y debug\n");
#endif
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));
#ifdef DEBUG
    printf("register event sources\n");
#endif
    unsigned char key[ALLEGRO_KEY_MAX];
    memset(key, 0, sizeof(key));//keyboard int.
#ifdef DEBUG
    printf("key y ship init\n");
#endif
    
    ALLEGRO_EVENT event;
   
     bool done = false;
     
     SHIP ship = ship_init();
     ALLEGRO_BITMAP* ship_image = al_load_bitmap("x-wing.png");
     SHIP* pship = &ship;
    
    al_start_timer(timer);
    while(1)//menu
    {
#ifdef DEBUG
    printf("entro al primer while\n");
#endif
        //menu();
        /*
        while(event.type!=ALLEGRO_KEY_D)
        {
            new_game_select();
        }
        while(event.type!=ALLEGRO_KEY_D)
        {
            load_game_select();
        }*/
        if (true)
        {
            frames = 0;
            score = 0;
           
            bool redraw = true;
            bool pause = false;
            while(1)//juego
            {
#ifdef DEBUG
    printf("entro al segundo while\n");
#endif
                al_wait_for_event(queue, &event);

                switch(event.type)
                {
                    

                    case ALLEGRO_EVENT_TIMER:
                        if(!pause)
                        {
                            
                            ship_update(ship,1,false);
                        }

                        if(key[ALLEGRO_KEY_P])//corregir
                        {
                            pause = pause ? false : true;
                            al_rest(1);
                        } 
                        if(key[ALLEGRO_KEY_S])
                        {
                            int save;
                            //save = save_game();
                            if(!save==-1)
                                printf("save error!");
                        }
                        if(key[ALLEGRO_KEY_L])//corregir
                        {
                            int load;
                            //load = load_game();
                            if(load == -1)
                                printf("load error!");
                        } 
                        if(key[ALLEGRO_KEY_ESCAPE])
                            done = true;

                        redraw = true;
                        frames++;
                        break;

                    case ALLEGRO_EVENT_DISPLAY_CLOSE:
                        done = true;
                        break;
                }
#ifdef DEBUG
                printf("salgo de switch case\n");
#endif
                if(done)
                    break;
#ifdef DEBUG
                printf("intento updatear el keyboard\n");
#endif
                //keyboard update
                switch(event.type)
                {
                    case ALLEGRO_EVENT_TIMER:
                        for(int i = 0; i < ALLEGRO_KEY_MAX; i++)
                            key[i] &= KEY_SEEN;
                        break;

                    case ALLEGRO_EVENT_KEY_DOWN:
                        key[event.keyboard.keycode] = KEY_SEEN | KEY_RELEASED;
                        break;
                    case ALLEGRO_EVENT_KEY_UP:
                        key[event.keyboard.keycode] &= KEY_RELEASED;
                        break;
                }
#ifdef DEBUG
                printf("updatea el keyboard\n");
#endif

                if(redraw && al_is_event_queue_empty(queue))
                {
#ifdef DEBUG
                    printf("me pongo a dibujar\n");
#endif
                    al_set_target_bitmap(buffer);
                    al_clear_to_color(al_map_rgb(0,255,0));

                    al_draw_bitmap(ship_image, ship.x,ship.y, 0);

                    al_set_target_backbuffer(disp);
                    al_draw_scaled_bitmap(buffer, 0, 0, BUFFER_W, BUFFER_H, 0, 0, DISP_W, DISP_H, 0);
                    al_flip_display();
                    redraw = false;
                }

            }
        }
        if(done)
            break;
    }
    al_destroy_bitmap(buffer);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}

