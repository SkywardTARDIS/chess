#include <stdio.h>
#include <unistd.h>
#include "sense.h"
#include <stdbool.h>

int castleCheck(char *position, int player, int CR){
    int temp = CR;
    if(player==1 & position[60]=='K'){
        for(int i=0; i<64; i++){
            if(position[i]>'a' & position[i]<'z'){
                    //cannot castle if king is in check
                    if(isValid(position, i, 60, 0, 0, -1)){
                        temp = 0;
                    }
                    //cannot castle into or through BOTH sides
                    else if((isValid(position, i, 59, 0, 0, -1) | isValid(position, i, 58, 0, 0, -1)) & (isValid(position, i, 61, 0, 0, -1) | isValid(position, i, 62, 0, 0, -1))){
                        temp = 0;
                    }
                    //cannot castle short side
                    else if(isValid(position, i, 61, 0, 0, -1) | isValid(position, i, 62, 0, 0, -1)){
                        temp = 2;
                    }
                    //cannot castle long side
                    else if(isValid(position, i, 59, 0, 0, -1) | isValid(position, i, 58, 0, 0, -1)){
                        temp = 1;
                    }
            }
        }
    }
    if(player==2 & position[4]=='k'){
        for(int i=0; i<64; i++){
            if(position[i]>'A' & position[i]<'Z'){
                    //cannot castle if king is in check
                    if(isValid(position, i, 4, 0, 0, -1)){
                        temp = 0;
                    }
                    //cannot castle into or through BOTH sides
                    else if((isValid(position, i, 3, 0, 0, -1) | isValid(position, i, 2, 0, 0, -1)) & (isValid(position, i, 5, 0, 0, -1) | isValid(position, i, 6, 0, 0, -1))){
                        temp = 0;
                    }
                    //cannot castle short side
                    else if(isValid(position, i, 5, 0, 0, -1) | isValid(position, i, 6, 0, 0, -1)){
                        temp = 2;
                    }
                    //cannot castle long side
                    else if(isValid(position, i, 3, 0, 0, -1) | isValid(position, i, 2, 0, 0, -1)){
                        temp = 1;
                    }
            }
        }
    }
    
    if(CR>0 & player==2){
        if((position[7]!='r' & temp==1) | (position[0]!='r' & temp==2)){
            temp=0;
        }
    }
    if(CR>0 & player==1){
        if((position[63]!='R' & temp==1) | (position[56]!='R' & temp==2)){
            temp=0;
        }
    }
    return temp;
}
