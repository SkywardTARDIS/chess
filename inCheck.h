#include <stdio.h>
#include <unistd.h>
#include "sense.h"
#include  "validmove.h"

bool check(char *position, int player){
    bool IC = false;
    int i = 0;
    char King='k';
    if(player==1){
    King='K';
    }
    while(position[i]!=King){
        i++;
    }
    int kingLoc = i;
    if(player==1){
        for(int a=0; a<64; a++){
            if(position[a]>'a' & position[a]<'z'){
                if(isValid(position, a, kingLoc, 0, false, 65)){
                    IC = true;
                }
            }
        }
    }
    else{
        for(int a=0; a<64; a++){
            if(position[a]>'A' & position[a]<'Z'){
                if(isValid(position, a, kingLoc, 0, false, 65)){
                    IC = true;
                }
            }
        }
    }
    return IC;
}
