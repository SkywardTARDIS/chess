#include <stdio.h>
#include <unistd.h>
#include "sense.h"
#include "movepiece.h"
#include <stdbool.h>
//#include "cursor.h"

//int main(void){
    char position[] = "rnbqkbnrpppppppp--------------------------------PPPPPPPPRNBQKBNR";
int main(void){  
    setPos(position);
    //
 //   bm->pixel[4][3]=CC;
    //
    int p1CR = 3;
    int p2CR = 3;
  //  getMove();

    movePiece(position, gridToPos(4,6), gridToPos(4,4), 3, false, -1);
    movePiece(position, gridToPos(1,1), gridToPos(1,2), 3, false, -1);
    movePiece(position, gridToPos(3,6), gridToPos(3,4), 3, false, -1);
    movePiece(position, gridToPos(1,0), gridToPos(2,2), 3, false, -1);
    movePiece(position, gridToPos(6,7), gridToPos(5,5), 3, false, -1);
    movePiece(position, gridToPos(2,0), gridToPos(1,1), 3, false, -1);
    movePiece(position, gridToPos(5,7), gridToPos(3,5), 3, false, -1);
    movePiece(position, gridToPos(3,0), gridToPos(1,0), 3, false, -1);
    movePiece(position, gridToPos(4,7), gridToPos(4,6), 3, false, -1);
    movePiece(position, gridToPos(1,0), gridToPos(0,0), 0, false, -1);
    movePiece(position, gridToPos(3,7), gridToPos(5,7), 3, false, -1);
    movePiece(position, gridToPos(2,2), gridToPos(3,4), 0, false, -1);
    movePiece(position, gridToPos(5,5), gridToPos(3,4), 0, false, -1);
    movePiece(position, gridToPos(1,1), gridToPos(3,3), 0, false, -1);
    movePiece(position, gridToPos(4,4), gridToPos(3,3), 0, false, -1);
    movePiece(position, gridToPos(4,1), gridToPos(4,3), 0, false, -1);
    movePiece(position, gridToPos(3,3), gridToPos(4,2), 0, true, gridToPos(4,2));

    printf("%s\n",position);
    return 0;
}
