#include <stdio.h>
#include <unistd.h>
#include "sense.h"

int gridToPos(int m, int n){
    return ((7-m) + n*8);
}
