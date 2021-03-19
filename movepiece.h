#include <stdio.h>
#include <unistd.h>
#include "sense.h"
#include <stdbool.h>
#include "setposition.h"
#include "inCheck.h"
bool movePiece(char *position, int begin, int end, int CR, bool EP, int EPL){
    sleep(1);
    //note: include in here the ways to move in the event of castling i.e. move the rook too
    bool valid = isValid(position, begin, end, CR, EP, EPL);
    if(valid){
        //moving rook on castle
        if(CR%2==1 & (begin==(end-2))){
            //castle short
            if((position[begin]=='k' | position[begin]=='K') & (begin==(end-2))){
                position[begin+1] = position[begin+3];
                position[begin+3] = '-';
            }
        }
        else if(CR>1 & (begin==(end+2))){
            //castle long
            if((position[begin]=='k' | position[begin]=='K') & (begin==(end+2))){
                printf("long");
                position[begin-1] = position[begin-4];
                position[begin-4] = '-';
            }
        }
        if(EP & (EPL==end)){
            if(position[begin]=='p'){
                position[EPL-8]='-';
            }
            else if(position[begin]=='P'){
                position[EPL+8]='-';
            }
        }
        //normal piece move
        position[end] = position[begin];
        position[begin] = '-';
    }
    setPos(position);   
    return valid;
}
