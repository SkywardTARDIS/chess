#include "sense.h"
#include <linux/input.h>
#include <stdint.h>
#include <stdio.h>
#define P1 0x3249
#define P2 0x4986
#include "menuMaps.h"

int cursorpos=36;
int promPager=0;
int menPager=0;

void callbackFunc(unsigned int code){
    if(code == KEY_UP) {
        cursorpos+=1;
    }
    else if(code == KEY_DOWN) {
        cursorpos-=1;
    }
    else if(code == KEY_RIGHT) {
        cursorpos+=8;
    }
    else if(code == KEY_LEFT) {
        cursorpos-=8;
    }
    else if(code == KEY_ENTER) {
        cursorpos+=128;
    }
    if(cursorpos<0){
        cursorpos+=64;
    }
}

int getMove(char *position, int player) {
    int select=1;
    int lastcurse = cursorpos;
uint16_t CC=P1;
    if(player==2){
        CC=P2;
    }
    int oscillate=0;
    //
    pi_framebuffer_t *fb=getFrameBuffer();
    sense_fb_bitmap_t *bm=fb->bitmap;
    //
    pi_joystick_t* joystick=getJoystickDevice();
    while(select){
        pollJoystick(joystick,callbackFunc,1000);
        if(lastcurse!=cursorpos){
            //printf("%d\n",cursorpos);
            lastcurse=cursorpos;
            if(lastcurse>127){
                select=0;
            }
            cursorpos=cursorpos%64;
            lastcurse=lastcurse%64;
            setPos(position);
            bm->pixel[7-lastcurse%8][lastcurse/8]=CC;
            oscillate=0;
        }
        if(lastcurse==cursorpos){
            if(oscillate){
                bm->pixel[7-lastcurse%8][lastcurse/8]=CC;
                oscillate=0;
            }
            else{
                oscillate=1;
                setPos(position);
            }
        }
    }
    //printf("%d\n",lastcurse);
    return lastcurse;
}
//
//Promotion Functions

void promotionFunc(unsigned int code){
    if(code==KEY_UP | code==KEY_DOWN | code==KEY_RIGHT | code==KEY_LEFT){
        promPager+=1;
    }
    promPager=promPager%4;
    if(code==KEY_ENTER){
        promPager+=8;
    }
}


char promotion(char *position, int begin){
    int selected=1;
    promPager=0;
    int lastpager=promPager;
    //
    pi_framebuffer_t *fb=getFrameBuffer();
    sense_fb_bitmap_t *bm=fb->bitmap;
    //
    pi_joystick_t* joystick=getJoystickDevice();
    char piece='a';
    if(position[begin]=='p'){
        bm->pixel[7-cursorpos%8][cursorpos/8]=BQ;
        piece='q';
    }
    else{
        bm->pixel[7-cursorpos%8][cursorpos/8]=WQ;
        piece='Q';
    }

    while(selected){
        pollJoystick(joystick,promotionFunc,1000);
        //printf("previous %d\n",lastpager);
        //printf("current %d\n",promPager);
        if(lastpager!=promPager){
            switch(promPager%4){
                case 0:
                    if(position[begin]=='p'){
                        bm->pixel[7-cursorpos%8][cursorpos/8]=BQ;
                        piece='q';
                    }
                    else{
                        bm->pixel[7-cursorpos%8][cursorpos/8]=WQ;
                        piece='Q';
                    }
                    break;
                case 1:
                    if(position[begin]=='p'){
                        bm->pixel[7-cursorpos%8][cursorpos/8]=BR;
                        piece='r';
                    }
                    else{
                        bm->pixel[7-cursorpos%8][cursorpos/8]=WR;
                        piece='R';
                    }
                    break;
                case 2:
                    if(position[begin]=='p'){
                        bm->pixel[7-cursorpos%8][cursorpos/8]=BB;
                        piece='b';
                    }
                    else{
                        bm->pixel[7-cursorpos%8][cursorpos/8]=WB;
                        piece='B';
                    }
                    break;
                case 3:
                    if(position[begin]=='p'){
                        bm->pixel[7-cursorpos%8][cursorpos/8]=BN;
                        piece='n';
                    }
                    else{
                        bm->pixel[7-cursorpos%8][cursorpos/8]=WN;
                        piece='N';
                    }
                    break;
                default:
                    if(position[begin]=='p'){
                        bm->pixel[7-cursorpos%8][cursorpos/8]=BQ;
                        piece='q';
                    }
                    else{
                        bm->pixel[7-cursorpos%8][cursorpos/8]=WQ;
                        piece='Q';
                    }

                    break;
            }
            //printf("%c\n", piece);
            if(promPager>7){
                selected=0;
            }
            lastpager=promPager;
        }
    }
    return piece;
}

void menuFunc(unsigned int code){
    if(code==KEY_UP | code==KEY_DOWN | code==KEY_RIGHT | code==KEY_LEFT){
        menPager+=1;
    }
    menPager=menPager%4;
    if(code==KEY_ENTER){
        menPager+=8;
    }
}


int menu(char *position){
    int menSelect=1;
    int lastMen=menPager;
    int gameBreak;
    //
    pi_framebuffer_t *fb=getFrameBuffer();
    sense_fb_bitmap_t *bm=fb->bitmap;
    //
    pi_joystick_t* joystick=getJoystickDevice();
    resume();
    while(menSelect){
        pollJoystick(joystick, menuFunc,1000);
        if(lastMen!=menPager){
            switch(menPager%4){
                case 0:
                    resume();
                    gameBreak=1;
                    break;
                case 1:
                    draw();
                    gameBreak=0;
                    break;
                case 2:
                    whiteRes();
                    gameBreak=3;
                    break;
                case 3:
                    blackRes();
                    gameBreak=2;
                    break;
            }
            lastMen=menPager;
            if(menPager>7){
                menSelect=0;
            }
        }
    }
    if(gameBreak==1){
        setPos(position);
    }
    return gameBreak;
}





