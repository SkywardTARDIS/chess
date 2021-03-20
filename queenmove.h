#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "sense.h"
#include <stdbool.h>
#include "gridToPos.h"

bool Queen(char *position, int j, int k, int m, int n){
    //rook
    if(j==m ^ k==n){
        if(j>m){
            //printf("right");
            for(int i=(j-1); i>m; i--){
                if(position[gridToPos(i,k)]!='-'){
                    return false;
                }
            }
            return true;
        }
        if(j<m){
            //printf("left");
            for(int i=(j+1); i<m; i++){
                if(position[gridToPos(i,k)]!='-'){
                    return false;
                }
            }
            return true;
        }
        if(k>n){
            //printf("up");
            for(int i=(k-1); i>n; i--){
                if(position[gridToPos(j,i)]!='-'){
                    return false;
                }
            } 
            return true;
        }
        if(k<n){
            //printf("down");
            for(int i=(k+1); i<n; i++){
                if(position[gridToPos(j,i)]!='-'){
                    return false;
                }
            } 
            return true;
        }
    }
    else if(abs(j-m)==abs(k-n)){
        if(j>m & k>n){
            for(int i=1; (j-i)>m; i++){
                if(position[gridToPos(j-i, k-i)]!='-'){
                    return false;
                }
            }
            return true;
        }
        if(j<m & k>n){
            for(int i=1; (j+i)<m; i++){
                if(position[gridToPos(j+i, k-i)]!='-'){
                    return false;
                }
            }
            return true;
        }
        if(j<m & k<n){
            for(int i=1; (j+i)<m; i++){
                if(position[gridToPos(j+i, k+i)]!='-'){
                    return false;
                }
            }
            return true;
        }
        if(j>m & k<n){
            for(int i=1; (j-i)>m; i++){
                if(position[gridToPos(j-i, k+i)]!='-'){
                    return false;
                }
            }
            return true;
        }
    }
    else{
        //printf("none\n");
        return false;
    }
}
