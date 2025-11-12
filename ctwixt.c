#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "link.h"
#include "logic.h"

//there is a slight issue in linking, try linking two adjacent Ls from same point 

int main(){
    //1 reps red
    //-1 reps blue
    int playr = 1;

    int board[47][47]={0};

    linkgroup* redsimp = malloc(sizeof(linkgroup));
    redsimp->n=0;

    linkgroup* blusimp = malloc(sizeof(linkgroup));
    blusimp->n=0;

    // board[10][10]=1;
    // board[12][14]=-1;
    // board[0][10]=1;
    // board[0][14]=-1;
    // board[10][0]=1;
    // board[12][0]=-1;
    // board[10][46]=1;
    // board[12][46]=-1;
    // board[46][10]=1;
    // board[46][14]=-1;
    // printboardvalues(board);

    printboard(board);

    int ix=0;
    int iy=0;
    while(ix!=-1 && iy!=-1){
        if(playr==1){
            int cont=0;
            while(cont!=1){
                printf("\n\033[31mred: \033[0m");
                scanf("%d %d",&ix, &iy);
                if(ix==-1||iy==-1){
                    break;
                }
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
                    makelink(board,x,y,x+2,y+4,redsimp,blusimp);
                    makelink(board,x,y,x-2,y+4,redsimp,blusimp);
                    makelink(board,x,y,x+2,y-4,redsimp,blusimp);
                    makelink(board,x,y,x-2,y-4,redsimp,blusimp);
                    makelink(board,x,y,x+4,y+2,redsimp,blusimp);
                    makelink(board,x,y,x-4,y+2,redsimp,blusimp);
                    makelink(board,x,y,x+4,y-2,redsimp,blusimp);
                    makelink(board,x,y,x-4,y-2,redsimp,blusimp);
                    printboard(board);
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
                if(ix==-1||iy==-1){
                    break;
                }
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
                    makelink(board,x,y,x+2,y+4,redsimp,blusimp);
                    makelink(board,x,y,x-2,y+4,redsimp,blusimp);
                    makelink(board,x,y,x+2,y-4,redsimp,blusimp);
                    makelink(board,x,y,x-2,y-4,redsimp,blusimp);
                    makelink(board,x,y,x+4,y+2,redsimp,blusimp);
                    makelink(board,x,y,x-4,y+2,redsimp,blusimp);
                    makelink(board,x,y,x+4,y-2,redsimp,blusimp);
                    makelink(board,x,y,x-4,y-2,redsimp,blusimp);
                    printboard(board);
                    cont=1;
                }
            }
            playr=-playr;
        }
    }

    return 0;
}
