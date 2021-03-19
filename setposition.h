#include <stdio.h>
#include <unistd.h>
#include "sense.h"

#define DARK 0x0000
#define LIGHT 0x8C51
#define WR 0x9806
#define BR 0x7800
#define WN 0xC2E6
#define BN 0xdb60
#define WB 0x1B17
#define BB 0x210E
#define WQ 0x70D4
#define BQ 0x40AE//30AE
#define WK 0x07E2
#define BK 0x2424
#define WP 0xB5A0
#define BP 0xA380


int setPos(char *currPos) {
   
    pi_framebuffer_t *fb=getFrameBuffer();
    sense_fb_bitmap_t *bm=fb->bitmap;
 
    //setting up the pieces
    int j,k;
    for(int i=0; i<64; i++){
        j = 7 - (i%8);
        k = i/8;
        switch(currPos[i]){
            case 'r':
                bm->pixel[j][k]=BR;
                break;
            case 'n':
                bm->pixel[j][k]=BN;
                break;
            case 'b':
                bm->pixel[j][k]=BB;
                break;
            case 'q':
                bm->pixel[j][k]=BQ;
                break;
            case 'k':
                bm->pixel[j][k]=BK;
                break;
            case 'p':
                bm->pixel[j][k]=BP;
                break;
            case 'R':
                bm->pixel[j][k]=WR;
                break;
            case 'N':
                bm->pixel[j][k]=WN;
                break;
            case 'B':
                bm->pixel[j][k]=WB;
                break;
            case 'Q':
                bm->pixel[j][k]=WQ;
                break;
            case 'K':
                bm->pixel[j][k]=WK;
                break;
            case 'P':
                bm->pixel[j][k]=WP;
                break;
            case '-':
                if((j+k)%2==0){
                    bm->pixel[j][k]=DARK;
                    break;
                }
                else{
                    bm->pixel[j][k]=LIGHT;
                    break;
                }
        }
    }


    freeFrameBuffer(fb);
    return 0;
}
