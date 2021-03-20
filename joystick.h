#include "sense.h"
#include <linux/input.h>
#include <stdio.h>
//
//NOW DEFUNCT PROGRAM
//
//
//
//

/* using a char as a number because it doesn't need to be large.
 * Doing it because I _can_, not because I need to */
char xPos = 7, yPos = 7;

/* Program stops when 'running' is zero */
int running=1;

void callbackFunc(unsigned int code);
int cursor(void) {
    pi_joystick_t* joystick=getJoystickDevice();
    while(running){
        int lastX=-1,lastY=-1;
        /* The 1000 here is supposed to be the amount of time in
         * milliseconds that the function spends checking for joystick
         * input. In fact, it appears to be 2x as long */
        pollJoystick(joystick,callbackFunc,1000);
        if(lastX!=xPos || lastY!=yPos) {
            lastX=xPos;
            lastY=yPos;
            display_dot(xPos,yPos);
        }
    }
    fprintf(stderr,"Looks like 'running' is zero!\n");
    freeJoystick(joystick);
}

/* Note that the codes don't really match any orientation of the joystick */
void callbackFunc(unsigned int code) {
    fprintf(stderr,"code: %u\t",code);
    if(code == KEY_UP) {
        fprintf(stderr,"up");
        if(yPos==0) {
            yPos=7;
        }else{
            yPos--;
        }
    }else if(code == KEY_DOWN) {
        fprintf(stderr,"down");
        if(yPos==7) {
            yPos=0;
        }else{
            yPos++;
        }
    }else if(code == KEY_RIGHT) {
        fprintf(stderr,"left");
        if(xPos==7) {
            xPos=0;
        }else{
            xPos++;
        }
    }else if(code == KEY_LEFT) {
        fprintf(stderr,"right");
        if(xPos==0) {
            xPos=7;
        }else{
            xPos--;
        }
    }else if(code == KEY_ENTER) {
        fprintf(stderr,"push");
        running = 0;
    }
    fprintf(stderr,"\n");
}

