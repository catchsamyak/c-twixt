#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct peg{
    int x;
    int y;
}peg;

typedef struct link{
    peg p1;
    peg p2;
    peg* included;
}link;

link* rlinks;
link* blinks;

void printboardvalues(int board[47][47]){
    for(int j=0; j<47; j++){
        for(int i=0; i<47; i++){
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

//use ^<v>
void printboard(int board[47][47]){
    printf("\n");
    for(int j=0; j<47; j++){
        for(int i=0; i<47; i++){

            //corners are always empty
            if((i==0 && j==0) || (i==46 && j==0) || (i==0 && j==46) || (i==46 && j==46)){
                printf("      ");
                continue;
            }
            
            if(i%2==0 && j%2==0){
                        if(i==0){
                            if(board[i][j]==0){
                            printf("  □  \033[34m│\033[0m");
                            }
                            if(board[i][j]==1){
                                printf("\033[31m  ■  \033[0m\033[34m│\033[0m");
                            }
                            if(board[i][j]==-1){
                                printf("\033[34m  ■  \033[0m\033[34m│\033[0m");
                            }
                        }
                        else if(i==46){
                            if(board[i][j]==0){
                            printf("\033[34m│\033[0m  □  ");
                            }
                            if(board[i][j]==1){
                                printf("\033[34m│\033[0m\033[31m  ■  \033[0m");
                            }
                            if(board[i][j]==-1){
                                printf("\033[34m│\033[0m\033[34m  ■  \033[0m");
                            }
                        }
                        else{
                            if(board[i][j]==0){
                                printf("  □  ");
                            }
                            if(board[i][j]==1){
                                printf("\033[31m  ■  \033[0m");
                            }
                            if(board[i][j]==-1){
                                printf("\033[34m  ■  \033[0m");
                            }
                        }
                    }

            else{ 
                if(i%2==0){
                    if(i==0){
                        if(j==1 || j==45){
                        // printf("  a \033[31m─\033[0m\033[34m│\033[0m");
                        printf("    \033[31m─\033[0m\033[34m│\033[0m");
                        }
                        else{
                        // printf("  a  \033[34m│\033[0m");
                        printf("     \033[34m│\033[0m");
                        }
                    }
                    else if(i==46){
                        if(j==1 || j==45){
                        // printf("\033[34m│\033[0m\033[31m─\033[0m b  ");
                        printf("\033[34m│\033[0m\033[31m─\033[0m    ");
                        }
                        else{
                        // printf("\033[34m│\033[0m  b  ");
                        printf("\033[34m│\033[0m     ");
                        }
                    }
                    else{
                        if(j==1 || j==45){
                        printf("\033[31m─────\033[0m");
                        }
                        else{
                        // printf("  c  ");
                        printf("     ");
                        }
                    }
                }
                else{
                    if(j==1 || j==45){
                        printf("\033[31m─\033[0m");
                    }
                    else{
                    // printf("m");
                    printf(" ");
                    }
                } 
            }

        }
        printf("\n");
    }
    printf("\n");
}

void makelink(int x1, int y1, int x2, int y2){
    if(abs(x1-x2)==2 && abs(y1-y2)==1){
        //horizontal link
    }
    if(abs(y1-y2)==2 && abs(x1-x2)==1){
        //vertical link
    }
    else{
        //invalid
    }
}
