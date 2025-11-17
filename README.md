# C-TWIXT

NAME: Samyak Shah
ROLL NUMBER: 2025101020

HOW TO RUN:
run the command ./twixt in your linux terminal

HOW TO EXIT:
use ctrl+C to exit for now

HOW TO PLAY:
there are two players: red and blue
during your turn enter the x-coordinate and y-coordinate respectively (of the position at which you would like to place your peg) seperated by a space 

INFORMATION:
ctwixt.c - contains the main code including handling player switch, player input, and checking for links and win
board.h & board.c - contains information on how to print the board (converts the array storing the state of the board to the printed version of the board)
link.h & link.c - contains a function that checks whether a link is possible and valid and makes it if it is
logic.h & logic.c - keeps a account of the links made so far and detects a win
makefile - compiles all of these files together into a single exectuable named twixt

NOTE: the game is still in development phase, you may see debug prints