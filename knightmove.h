#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "sense.h"
#include <stdbool.h>


bool Knight(char *position, int j, int k, int m, int n){
            if((abs(j-m)==2 ^ abs(k-n)==2) & (abs(j-m)==1 ^ abs(k-n)==1)){
                return true;
            }
            else{
                return false;
            }
}
