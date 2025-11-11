#include <stdio.h>
#include <stdlib.h>
#include "board.h"

int main(){
    int board[47][47]={0};
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
    return 0;
}
