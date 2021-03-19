#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "sense.h"
#include <stdbool.h>

bool Rook(char *position, int j, int k, int m, int n){
            printf("rook\n");
            if(j==m ^ k==n){
                if(j>m){
                    for(int i=(j-1); i>m; i--){
                        if(position[gridToPos(i,k)]!='-'){
                            return false;
                        }
                    }
                    return true;
                }
                if(j<m){
                    for(int i=(j+1); i<m; i++){
                        if(position[gridToPos(i,k)]!='-'){
                            return false;
                        }
                    }
                    return true;
                }
                if(k>n){
                    for(int i=(k-1); i>n; i--){
                        if(position[gridToPos(j,i)]!='-'){
                            return false;
                        }
                    }
                    return true;
                }
                if(k<n){
                    for(int i=(k+1); i<n; i++){
                        if(position[gridToPos(j,i)]!='-'){
                            return false;
                        }
                    }
                    return true;
                }
            }
            else{
                return false;
            }
}
