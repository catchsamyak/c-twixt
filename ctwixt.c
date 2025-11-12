#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "link.h"

int main(){
    int board[47][47]={0};

    linkgroup* red = malloc(sizeof(linkgroup));
    red->n=0;
    linkgroup* redsimp = malloc(sizeof(linkgroup));
    redsimp->n=0;

    linkgroup* blu = malloc(sizeof(linkgroup));
    blu->n=0;
    linkgroup* blusimp = malloc(sizeof(linkgroup));
    blusimp->n=0;

    board[10][10]=1;
    board[12][14]=-1;
    board[0][10]=1;
    board[0][14]=-1;
    board[10][0]=1;
    board[12][0]=-1;
    board[10][46]=1;
    board[12][46]=-1;
    board[46][10]=1;
    board[46][14]=-1;

    // printboardvalues(board);
    printboard(board);

    //when taking input make sure that its 0

    //remove links

    return 0;
}
