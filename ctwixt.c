#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "link.h"
#include "logic.h"

//[todo]
//need to check for every intersection -not break at first exception in link collission and also add parallel exception for all other cases
//test extensively after which stop printing debug prints

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

    //initial information display
    printf("\n");
    printf(" □ \033[31m■\033[0m □ □ □   □               □   \033[34m■\033[0m   □       □   □ \033[34m■\033[0m □ □ □\n");
    printf("     □        □      □      □    □     □   □         □    \n");
    printf("     \033[34m■\033[0m         □   □   \033[31m■\033[0m   □     □       □           □    \n");
    printf("     □          □ \033[34m■\033[0m     □ □      □     \033[31m■\033[0m   □         □    \n");
    printf("     □           □       □       □   □       □       \033[31m■\033[0m    \n");
    printf("\n");
    printf("Welcome to TWIXT!- this game has been made only using C (programming language) by Samyak Shah!\n");
    printf("\n");
    printf("TwixT is a connection game invented by Alex Randolph. It is played on a board with a 24x24 grid of holes, with the four corners missing.\n");
    printf("There are two players \033[31mred\033[0m and \033[34mblue\033[0m; the topmost and bottommost rows belong to \033[31mred\033[0m, and the leftmost and rightmost rows belong to \033[34mblue\033[0m.\n");
    printf("\n");
    printf("The RULES are as follows:\n");
    printf("The players take turns placing pegs of their respective colors on the board, one peg per turn. For this version of the game, \033[31mred\033[0m begins.\n");
    printf("A player may not place a peg on the rows which belong to his or her opponent.\n");
    printf("After placing a peg, you may link one or more pairs of pegs on the board which are all your own color.\n");
    printf("The links can only go between two pegs a knight's move away from each other and cannot cross another link; they block other links, most importantly the opponent's.\n");
    printf("For this version of the game, all possible links are automatically made and are permanent (cannot be removed) for the entire course of the game.\n");
    printf("The first player to make a continuous chain of linked pieces connecting their two sides wins. If neither side can achieve this, the game is a draw.\n");
    printf("\n");
    printf("In order to place a peg on your turn please enter the coordinates of the location at which you would to place your peg in the format <x> <y>,\n");
    printf("where <x> and <y> are the x-coordinate and y-coordinate respectively.\n");
    printf("\n");
    printf("The game will automatically end once a player has won. If you wish to EXIT before that manually: type ^C (ctrl+C) on your keyboard.\n");
    printf("Enjoy playing!\n");
    printf("\n");
    printboard(board);

    int ix=0;
    int iy=0;
    while(end!=1){
        if(playr==1){
            int cont=0;
            while(cont!=1){
                printf("\n\033[31mred: \033[0m");
                int valid=0;
                while(!valid){
                    if(scanf("%d %d",&ix, &iy)!=2){
                        printf("INVALID input, please enter integers only in the format <x> <y> (x-coordinate then y-coordinate).\n\033[31mred: \033[0m");
                        while(getchar()!='\n'){
                            continue;
                        }
                    }
                    else{
                        valid=1;
                    }
                }
                int x=2*ix-2;
                int y=2*iy-2;
                if(ix<1 || ix>24 || iy<1 || iy>24){
                    printf("INVALID input, that is out of the bounds of the board\n");
                }
                else if(ix==1||ix==24){
                    printf("INVALID input, you cannot place a peg on your opponent's rows\n");
                }
                else if(board[x][y]!=0){
                    printf("INVALID input, a peg is already present there\n");
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
                int valid=0;
                while(!valid){
                    if(scanf("%d %d",&ix, &iy)!=2){
                        printf("INVALID input, please enter integers only in the format <x> <y> (x-coordinate then y-coordinate).\n\033[34mblue: \033[0m");
                        while(getchar()!='\n'){
                            continue;
                        }
                    }
                    else{
                        valid=1;
                    }
                }
                int x=2*ix-2;
                int y=2*iy-2;
                if(ix<1 || ix>24 || iy<1 || iy>24){
                    printf("INVALID input, that is out of the bounds of the board\n");
                }
                else if(iy==1||iy==24){
                    printf("INVALID input, you cannot place a peg on your opponent's rows\n");
                }
                else if(board[x][y]!=0){
                    printf("INVALID input, a peg is already present there\n");
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

    printf("\nThanks for playing!\n");

    freeall(redgrp, blugrp);

    return 0;
}
