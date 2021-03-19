#include <stdio.h>
#include <unistd.h>
#include "sense.h"

#define DARK 0x0000
#define LIGHT 0xFFF1
#define WR 0xF00F
#define BR 0xF101
#define WN 0xFCE0
#define BN 0xBAC4
#define WB 0x073F
#define BB 0x00FF
#define WQ 0x701F
#define BQ 0x30AE
#define WK 0x07E1
#define BK 0x3CA7
#define WP 0xEFE0
#define BP 0xADA8


int main(void) {
   
    pi_framebuffer_t *fb=getFrameBuffer();
    sense_fb_bitmap_t *bm=fb->bitmap;
 
    //setting up the pieces
    char position[64] = "rnbqkbnrpppppppp--------------------------------PPPPPPPPRNBQKBNR";
    int j,k;
    for(int i=0; i<64; i++){
        j = 7 - (i%8);
        k = i/8;
        switch(position[i]){
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
