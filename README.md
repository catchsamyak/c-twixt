# C-TWIXT
  
C-TWIXT  
TwixT made using only C (programming language)  
  
HOW TO RUN:  
make sure you are in the directory containing the game files  
then run the command ```make```  
then run the command ```./twixt```  
in your linux terminal  
note: the rest of the relevant information about the game will be visible upon running it.  
  
FILES:  
ctwixt.c - contains the main code including handling player switch, player input, and checking for possible links and a win  
board.h & board.c - contains information on how to print the board (converts the array storing the state of the board to the printed version of the board)  
link.h & link.c - contains a function that checks whether a link is possible and valid and makes it if it is  
logic.h & logic.c - keeps an account of the links made so far and contains instructions on how to detect a win  

makefile - compiles all of these files together into a single exectuable named twixt  
