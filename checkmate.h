#include <stdio.h>
#include <unistd.h>
#include "sense.h"
#include <stdbool.h>

bool checkmate(char *position, int player, bool EP, int EPL){
    char dummy[]="----------------------------------------------------------------";
    for(int i=0; i<64; i++){
        dummy[i]=position[i];
    }
    //printf("%s\n",dummy);
    char holder='-';
    if(player==1){
        for(int i=0; i<64; i++){
            if(position[i]>'A' & position[i]<'Z'){
                for(int j=0; j<64; j++){
                    if(isValid(position, i, j, 0, EP, EPL)){
                        holder=dummy[j];
                        dummy[j]=dummy[i];
                        dummy[i]='-';
                        if(!check(dummy, player)){
                            //printf("%s\n",dummy);
                            return false;
                        }
                        dummy[i]=dummy[j];
                        dummy[j]=holder;
                    }
                }
            }
        }
    }
    if(player==2){
        for(int i=0; i<64; i++){
            if(position[i]>'a' & position[i]<'z'){
                for(int j=0; j<64; j++){
                    if(isValid(position, i, j, 0, EP, EPL)){
                        holder=dummy[j];
                        dummy[j]=dummy[i];
                        dummy[i]='-';
                        if(!check(dummy, player)){
                            return false;
                        }
                        dummy[i]=dummy[j];
                        dummy[j]=holder;
                    }
                }
            }
        }

    }
    return true;
}
