#include <stdio.h>
#include <unistd.h>
#include "sense.h"
#include "movepiece.h"
#include <stdbool.h>
#include "cursor.h"
int game=1;
int pturn=1;
int p1CR = 3;
int p2CR = 3;
int main(void){
    char position[] = "rnbqkbnrpppppppp--------------------------------PPPPPPPPRNBQKBNR";
//int main(void){  
    //
    pi_framebuffer_t *fb=getFrameBuffer();
    sense_fb_bitmap_t *bm=fb->bitmap;
    //
    setPos(position);
    //
    bm->pixel[3][4]=CC;
    //
    int start;
    int end;
    //en passant true/false, and location of capture
    bool EPP=false;
    int EPL=-1;
    //you can only move your own pieces
    int ownPiece=0;

    while(game){
        
        if(pturn==1){
            //add line to keep trying moves if still in check
            while((!isValid(position,start,end,p1CR,EPP,EPL)) | !ownPiece){
                ownPiece=0;
                start=getMove(position);
                end=getMove(position);
                if((position[start]>'A' & position[start]<'Z') | position[start]=='-'){
                    ownPiece=1;
                }
            }
            
            movePiece(position, start, end, p1CR, EPP, EPL);
            //En Passant
            if(EPP==1){
                EPP=0;
                EPL=-1;
            }
            if(end==(start-16) & position[end]=='P'){
                EPP=1;
                EPL=start-8;
            }
            //Castling Rights
            if(p1CR>0){
                if(position[60]!='K' | (position[63]!='R' & position[56]!='R')){
                    p1CR=0;
                }
                else if(position[63]!='R'){
                    p1CR=2;
                }
                else if(position[56]!='R'){
                    p1CR=1;
                }
            }

            ownPiece=0;
            printf("end P1 turn\n");
            pturn=2;
        }
        if(pturn==2){
            //add line to keep trying moves if still in check
            while((!isValid(position,start,end,p2CR,EPP,EPL)) | !ownPiece){
                ownPiece=0;
                start=getMove(position);
                end=getMove(position);
                if((position[start]>'a' & position[start]<'z') | position[start]=='-'){
                    ownPiece=1;
                }
            }
            movePiece(position, start, end, p2CR, EPP, EPL);
            //En Passant
            if(EPP==1){
                EPP=0;
                EPL=-1;
            }
            if(end==(start+16) & position[end]=='p'){
                EPP=1;
                EPL=start+8;
            }
            //Castling Rights
            if(p2CR>0){
                if(position[4]!='k' | (position[7]!='r' & position[0]!='r')){
                    p2CR=0;
                }
                else if(position[7]!='r'){
                    p2CR=2;
                }
                else if(position[0]!='r'){
                    p2CR=1;
                }
            }
            ownPiece=0;
            printf("end P2 turn\n");
            pturn=1;
        }
        //start=getMove(position);
        //printf("the piece is in %d place\n",start);
            
    
    
    
    }
    //
    /*
    movePiece(position, gridToPos(4,6), gridToPos(4,4), 3, false, -1);
    movePiece(position, gridToPos(1,1), gridToPos(1,2), 3, false, -1);
    movePiece(position, gridToPos(3,6), gridToPos(3,4), 3, false, -1);
    movePiece(position, gridToPos(1,0), gridToPos(2,2), 3, false, -1);
    movePiece(position, gridToPos(6,7), gridToPos(5,5), 3, false, -1);
    movePiece(position, gridToPos(2,0), gridToPos(1,1), 3, false, -1);
    movePiece(position, gridToPos(5,7), gridToPos(3,5), 3, false, -1);
    movePiece(position, gridToPos(3,0), gridToPos(1,0), 3, false, -1);
    movePiece(position, gridToPos(4,7), gridToPos(4,6), 3, false, -1);
    movePiece(position, gridToPos(1,0), gridToPos(0,0), 0, false, -1);
    movePiece(position, gridToPos(3,7), gridToPos(5,7), 3, false, -1);
    movePiece(position, gridToPos(2,2), gridToPos(3,4), 0, false, -1);
    movePiece(position, gridToPos(5,5), gridToPos(3,4), 0, false, -1);
    movePiece(position, gridToPos(1,1), gridToPos(3,3), 0, false, -1);
    movePiece(position, gridToPos(4,4), gridToPos(3,3), 0, false, -1);
    movePiece(position, gridToPos(4,1), gridToPos(4,3), 0, false, -1);
    movePiece(position, gridToPos(3,3), gridToPos(4,2), 0, true, gridToPos(4,2));
    */
    printf("%s\n",position);
    return 0;
}
