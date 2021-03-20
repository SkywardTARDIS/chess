This game of chess was programmed by Joshua Nicholls, to be played on the Raspberry Pi 3 sense hat,
using the LED screen as a playing board

############################################################################################################
here is the line to compile:
cc -o chess chess.c -L ~/lib -I ~/include -lsense

Except, the program has already been compiled in this folder.
To run the game, type 

./chess


To clear your screen afterwards, type

./clear


############################################################################################################
Rules of play: Each piece moves as normally in chess
To move a piece, first select your own piece.
Then, select the space you wish to move it to

If you wish to agree to resign or a draw, on your turn, click on the SAME unoccupied square twice in a row to open the menu
