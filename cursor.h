#include "sense.h"
#include <linux/input.h>
#include <stdio.h>
#define CC 0x3249

int cursorpos=36;

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

int getMove(char *position) {
    int select=1;
    int lastcurse = cursorpos;
    //
    pi_framebuffer_t *fb=getFrameBuffer();
    sense_fb_bitmap_t *bm=fb->bitmap;
    //
    pi_joystick_t* joystick=getJoystickDevice();
    while(select){
        pollJoystick(joystick,callbackFunc,1000);
        if(lastcurse!=cursorpos){
            printf("%d\n",cursorpos);
            lastcurse=cursorpos;
            if(lastcurse>127){
                select=0;
            }
            cursorpos=cursorpos%64;
            lastcurse=lastcurse%64;
            setPos(position);
            bm->pixel[7-lastcurse%8][lastcurse/8]=CC;
        }
    }
    printf("%d\n",lastcurse);
    return lastcurse;
}

