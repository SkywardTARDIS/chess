#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "sense.h"
#include <stdbool.h>
//UNUSED FILE
bool Pawn(char *position, int j, int k, int m, int n, EPL){
            printf("pawn\n");
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
            else if(EP){
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
                else{
                    //printf("c3\n");
                    return false;
                }
            }
}
