#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "sense.h"
#include <stdbool.h>
#include "gridToPos.h"

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
    char simp = position[start];
    int j = 7 - (start%8);
    int k = start/8;
    int m = 7 - (end%8);
    int n = end/8;
    int player = 2;
    if(simp <= 'Z'){
        player = 1;
    }
    _Bool Queen = false;
    switch(simp){
        case 'r':
            simp = "R";
        case 'n':
            simp = "N";
        case 'b':
            simp = "B";
        case 'q':
            simp = "R";
            Queen = true;
        case 'Q':
            simp = 'R';
            Queen = true;
        case 'k':
            simp = "K";
        case 'p':
            simp = "P";
        case 'R':
            if(j==m ^ k==n){
                if(j>m){
                    for(int i=j; i>m; i--){
                        if(position[gridToPos(i,k)]!='-'){
                            return false;
                        }
                    }
                }
                if(j<m){
                    for(int i=j; i<m; i++){
                        if(position[gridToPos(i,k)]!='-'){
                            return false;
                        }
                    }
                }
                if(k>n){
                    for(int i=k; i>n; i--){
                        if(position[gridToPos(j,i)]!='-'){
                            return false;
                        }
                    }
                }
                if(k<n){
                    for(int i=k; i<n; i++){
                        if(position[gridToPos(j,i)]!='-'){
                            return false;
                        }
                    }
                }
            }
            else{
                return false;
            }
            if(Queen){
                simp = 'B';
            }
        case 'N':
            if((abs(j-m)==2 ^ abs(k-n)==2) & (abs(j-m)==1 ^ abs(k-n)==1)){
            }
            else{
                return false;
            }
            break;
        case 'B':
            if(abs(j-m)==abs(k-n)){
                if(j>m & k>n){
                    for(int i=1; (j-i)>m; i++){
                        if(position[gridToPos(j-i, k-i)]!='-'){
                            return false;
                        }
                    }
                }
                if(j<m & k>n){
                    for(int i=1; (j+i)<m; i++){
                        if(position[gridToPos(j+i, k-i)]!='-'){
                            return false;
                        }
                    }
                }
                if(j<m & k<n){
                    for(int i=1; (j+i)<m; i++){
                        if(position[gridToPos(j+i, k+i)]!='-'){
                            return false;
                        }
                    }
                }
                if(j>m & k<n){
                    for(int i=1; (j-i)>m; i++){
                        if(position[gridToPos(j-i, k+i)]!='-'){
                            return false;
                        }
                    }
                }
            }
            break;
        case 'P':
            printf("Pawn\n");
            if((k==6 & n==4) & j==m){
                printf("c1\n");
                if(position[start-8]=='-' & position[start-16]=='-'){
                    return true;
                }
                else{
                    return false;
                }
            }
            else if((k==1 & n==3) & j==m){
                printf("c2\n");
                if(position[start+8]=='-' & position[start+16]=='-'){
                    return true;
                }
                else{
                    return false;
                }
            }
            else if(EP){
                printf("c3\n");
                if((n==k-1 & end==EPL & (m==j+1 | m==j-1)) & player==1){
                }
                else if((n==k+1 & end==EPL & (m==j+1 | m==j-1)) & player==2) {
                }
                else{
                    return false;
                }
            }
            else{
                printf("c4\n");
                if((player==1 & end==(start-8)) & position[end]=='-'){
                    printf("c1\n");
                    return true;
                }
                else if((player==2 & end==(start+8)) & position[end]=='-'){
                    printf("c2\n");
                    return true;
                }
                else{
                    printf("c3\n");
                    return false;
                }
            }
            break;
        case 'K':
            if(CR>0){
                if(end==(start-2) & (CR%2)==1){
                    if(position[end]=='-' & position[end+1]=='-'){
                    }
                    else{
                        return false;
                    }
                }
                if(end==(start+2) & (CR>1)){
                    if(position[end]=='-' & (position[end-1]=='-' & position[end+1]=='-')){
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
                }
                else{
                return false;
                }
            }
            break;
    }
    return true;
}
