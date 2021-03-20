#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "sense.h"
#include <stdbool.h>
#include "queenmove.h"
#include "bishopmove.h"
#include "rookmove.h"
#include "knightmove.h"

_Bool isValid(char *position, int start, int end, int CR, _Bool EP, int EPL){
    if(start==end){
        return false;
    }
    if((position[start]<'Z' & position[start]>'A') & (position[end]<'Z' & position[end]>'A')){
        return false;
    }
    if((position[start]<'z' & position[start]>'a') & (position[end]<'z' & position[end]>'a')){
        return false;
    }
    if(position[start]=='-'){
        return false;
    }
    char simp = position[start];
    int j = 7 - (start%8);
    int k = start/8;
    int m = 7 - (end%8);
    int n = end/8;
    int player = 2;
    if((simp <= 'Z') & (simp >= 'A')){
        player = 1;
    }
    //printf("%c\n",simp);
    switch(simp){
        case 'r':
            simp = 'R';
            break;
        case 'n':
            simp = 'N';
            break;
        case 'b':
            simp = 'B';
            break;
        case 'q':
            simp = 'Q';
            break;
        case 'k':
            simp = 'K';
            break;
        case 'p':
            simp = 'P';
            break;
    }
    //printf("%c\n",simp);
    switch(simp){
        case 'R':
            //printf("rook\n");
            return Rook(position, j, k, m, n);
            break;
        case 'N':
            //printf("knight\n");
            return Knight(position, j, k, m, n);
            break;
        case 'B':
            //printf("bishop\n");
            return Bishop(position, j, k, m, n);
            break;
        case 'Q':
            //printf("%d\n",Queen(position, j, k, m, n));
            return Queen(position, j, k, m, n);    
            break;
        case 'P':
            //printf("pawn\n");
            if((k==6 & n==4) & j==m){
                //printf("c1\n");
                if(position[start-8]=='-' & position[start-16]=='-'){
                    return true;
                }
                else{
                    return false;
                }
            }
            else if((k==1 & n==3) & j==m){
                //printf("c2\n");
                if(position[start+8]=='-' & position[start+16]=='-'){
                    return true;
                }
                else{
                    return false;
                }
            }
            else if(EP & (EPL==end)){
                //printf("c3\n");
                if((n==k-1 & end==EPL & (m==j+1 | m==j-1)) & player==1){
                }
                else if((n==k+1 & end==EPL & (m==j+1 | m==j-1)) & player==2) {
                }
                else{
                    return false;
                }
            }
            else{
                //printf("c4\n");
                if((player==1 & end==(start-8)) & position[end]=='-'){
                    //printf("c1\n");
                    return true;
                }
                else if((player==2 & end==(start+8)) & position[end]=='-'){
                    //printf("c2\n");
                    return true;
                }
                else if(player==1 & (end==(start-9) | end==(start-7))){
                    //printf("c1\n");
                    //printf("%c %c\n",position[start],position[end]);
                    if(position[end]!='-'){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else if(player==2 & (end==(start+7) | end==(start+9))){
                    //printf("c2\n");
                    if(position[end]!='-'){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    //printf("c3\n");
                    return false;
                }
            }
            break;
        case 'K':
            //printf("king %d %d\n", abs(j-m), abs(k-n)>1);
            if(CR>0 & (abs(j-m)==2 | abs(k-n)==2)){
                printf("c1\n");
                if(end==(start+2) & (CR%2)==1){
                    //castle short
                    if(position[end]=='-' & position[end-1]=='-'){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else if(end==(start-2) & (CR>1)){
                    //castle long
                    if(position[end]=='-' & (position[end-1]=='-' & position[end+1]=='-')){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            else{
                printf("c2\n");
                if(abs(j-m)<2 & abs(k-n)<2){
                    return true;
                }
                else{
                return false;
                }
            }
            break;
    }
    return true;
}
