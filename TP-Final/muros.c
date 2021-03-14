/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdbool.h>
#include "muros.h"
#include "main.h"


void muro_init (MURO* muro_arr)
{

    muro_arr[0].life=2;

    muro_arr[0].x=SCREEN_WIDTH/9;
    muro_arr[0].y=MURO_H;// numeri magico?
    int j;
    for(j=1;j<MURO_N;j++)
    {   
        muro_arr[j].life=2;       
        muro_arr[j].x=muro_arr[j-1].x;
        if (j%3==0&&j%12!=0)
        {
            muro_arr[j].x+=MURO_S;   
            muro_arr[j].y=muro_arr[j-3].y;
        }
        else if (j%12==0)
        {
            muro_arr[j].x+=SCREEN_HEIGHT/6;   
            muro_arr[j].y=muro_arr[j-3].y;
        }
        else
            muro_arr[j].y=muro_arr[j-1].y-+MURO_S;      
    }
}
/*
void muro_update (MURO* muro_arr)
{
    for(int i=0;i<MURO_N;i++)
    {
        if((shots_collide(false,muro_arr[i].x,muro_arr[i].y,MURO_S,MURO_S))||(shots_collide(true,muro_arr[i].x,muro_arr[i].y,MURO_S,MURO_S)))
        {
            muro_arr[i].life--;
        }

    }        
}

*/