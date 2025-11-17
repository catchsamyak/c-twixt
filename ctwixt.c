#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "link.h"
#include "logic.h"

//[issues to be fixed in phase 2]
//if you input letters it goes in infinite loop
//need to check for every intersection -not break at first exception in link collission

int main(){
    //1 is red
    //-1 is blue
    int playr = 1;

    //contains if the game should end or not
    int end = 0;

    int board[47][47]={0};

    linkgroup* redgrp = malloc(sizeof(linkgroup));
    redgrp->ncl=0;
    redgrp->nsl=0;

    linkgroup* blugrp = malloc(sizeof(linkgroup));
    blugrp->ncl=0;
    blugrp->nsl=0;

    //print initial information like how to play
    //note- links cannot be removed
    printboard(board);

    int ix=0;
    int iy=0;
    while(end!=1){
        if(playr==1){
            int cont=0;
            while(cont!=1){
                printf("\n\033[31mred: \033[0m");
                scanf("%d %d",&ix, &iy);
                int x=2*ix-2;
                int y=2*iy-2;
                if(ix<1 || ix>24 || iy<1 || iy>24){
                    printf("out of bounds of board\n");
                }
                else if(ix==1||ix==24){
                    printf("cannot put there\n");
                }
                else if(board[x][y]!=0){
                    printf("something is already present there\n");
                }
                else{
                    board[x][y]=1;
                    makelink(board,x,y,x+2,y+4,redgrp,blugrp);
                    makelink(board,x,y,x-2,y+4,redgrp,blugrp);
                    makelink(board,x,y,x+2,y-4,redgrp,blugrp);
                    makelink(board,x,y,x-2,y-4,redgrp,blugrp);
                    makelink(board,x,y,x+4,y+2,redgrp,blugrp);
                    makelink(board,x,y,x-4,y+2,redgrp,blugrp);
                    makelink(board,x,y,x+4,y-2,redgrp,blugrp);
                    makelink(board,x,y,x-4,y-2,redgrp,blugrp);
                    printboard(board);
                    checkwin(playr, &end, redgrp, blugrp);
                    cont=1;
                }
            }
            playr=-playr;
        }   
        else{
            int cont=0;
            while(cont!=1){
                printf("\n\033[34mblue: \033[0m");
                scanf("%d %d",&ix, &iy);
                int x=2*ix-2;
                int y=2*iy-2;
                if(ix<1 || ix>24 || iy<1 || iy>24){
                    printf("out of bounds of board\n");
                }
                else if(iy==1||iy==24){
                    printf("cannot put there\n");
                }
                else if(board[x][y]!=0){
                    printf("something is already present there\n");
                }
                else{
                    board[x][y]=-1;
                    makelink(board,x,y,x+2,y+4,redgrp,blugrp);
                    makelink(board,x,y,x-2,y+4,redgrp,blugrp);
                    makelink(board,x,y,x+2,y-4,redgrp,blugrp);
                    makelink(board,x,y,x-2,y-4,redgrp,blugrp);
                    makelink(board,x,y,x+4,y+2,redgrp,blugrp);
                    makelink(board,x,y,x-4,y+2,redgrp,blugrp);
                    makelink(board,x,y,x+4,y-2,redgrp,blugrp);
                    makelink(board,x,y,x-4,y-2,redgrp,blugrp);
                    printboard(board);
                    checkwin(playr, &end, redgrp, blugrp);
                    cont=1;
                }
            }
            playr=-playr;
        }
    }

    if(playr==-1){
        printf("\n\033[31mred wins!\033[0m\n");
    }
    else{
        printf("\n\033[34mblue wins!\033[0m\n");
    }

    printf("\nthanks for playing!\n");

    freeall(redgrp, blugrp);

    return 0;
}
