#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "sense.h"
#include <stdbool.h>
//UNUSED FILE
bool King(char *position, int j, int k, int m, int n, CR){
            if(CR>0){
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
                if(abs(j-m)<2 & abs(j-n)<2){
                    return true;
                }
                else{
                return false;
                }
            }
}
