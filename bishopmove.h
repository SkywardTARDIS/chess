#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "sense.h"
#include <stdbool.h>

bool Bishop(char *position, int j, int k, int m, int n){
            if(abs(j-m)==abs(k-n)){
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
                return false;
            }
}
