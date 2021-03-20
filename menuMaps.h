#include "sense.h"
#include <linux/input.h>
#include <stdio.h>
#define WHITE 0x4A49
#define BLACK 0x0000

//main menu
int resume(void){
    pi_framebuffer_t *fb=getFrameBuffer();
    sense_fb_bitmap_t *bm=fb->bitmap;
    clearFrameBuffer(fb,BLACK);
    bm->pixel[7][3]=WHITE;
    bm->pixel[7][4]=WHITE;
    bm->pixel[6][3]=WHITE;
    bm->pixel[6][4]=WHITE;
    bm->pixel[4][0]=WHITE;
    bm->pixel[4][1]=WHITE;
    bm->pixel[4][3]=WHITE;
    bm->pixel[4][4]=WHITE;
    bm->pixel[4][6]=WHITE;
    bm->pixel[4][7]=WHITE;
    bm->pixel[3][0]=WHITE;
    bm->pixel[3][1]=WHITE;
    bm->pixel[3][3]=WHITE;
    bm->pixel[3][4]=WHITE;
    bm->pixel[3][6]=WHITE;
    bm->pixel[3][7]=WHITE;
    bm->pixel[1][3]=WHITE;
    bm->pixel[1][4]=WHITE;
    bm->pixel[0][3]=WHITE;
    bm->pixel[0][4]=WHITE;
    return 0;
}
//agree to draw
int draw(void){
    pi_framebuffer_t *fb=getFrameBuffer();
    sense_fb_bitmap_t *bm=fb->bitmap;
    clearFrameBuffer(fb,BLACK);
    for(int i=0; i<=7; i++){
        for(int j=0; j<=i; j++){
            bm->pixel[i][j]=WHITE;
        }
    }
    return 0;
}
//White resigns
int whiteRes(void){
    pi_framebuffer_t *fb=getFrameBuffer();
    sense_fb_bitmap_t *bm=fb->bitmap;
    clearFrameBuffer(fb,BLACK);
    for(int i=0; i<=7; i++){
        for(int j=0; j<=6; j++){
            bm->pixel[7-j][i]=WHITE;
        }
    }
    return 0;
}
//Black resigns
int blackRes(void){
    pi_framebuffer_t *fb=getFrameBuffer();
    sense_fb_bitmap_t *bm=fb->bitmap;
    clearFrameBuffer(fb,BLACK);
    for(int i=0; i<=7; i++){
        bm->pixel[7][i]=WHITE;
    }
    return 0;
}
