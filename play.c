#include <stdio.h>
#include <unistd.h>
#include "sense.h"
#include "setposition.h"
#include "inCheck.h"
#include <stdbool.h>
#define CR 0x07E1

int main(void){
    char position[] = "rnbqkbnrpppppppp--------------------------------PPPPPPPPRNBQKBNR";
    setPos(position);
    int player=1;
    int cj,ck;
    cj = 5;
    ck = 4;
    while(true){
        if()


    }



    return 0;
}
