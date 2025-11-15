#include <stdio.h>
#include <stdlib.h>

void printboardvalues(int board[47][47]){
    for(int j=0; j<47; j++){
        for(int i=0; i<47; i++){
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

//0 is empty
//1 is red
//-1 is blue
//5 is red link
//-5 is blue link
//• or · or *
void printboard(int board[47][47]){
    printf("\n");

    printf("   ");
    for(int i=1; i<=24; i++){
        if(i<10){
            printf("    %d ", i);
        }
        else{
            printf("   %d ", i);
        }
    }
    printf("\n");
    printf("\n");

    for(int j=0; j<47; j++){

        if(j%2==0){
            if((j+2)/2<10){
               printf(" %d   ", (j+2)/2); 
            }
            else{
                printf("%d   ", (j+2)/2);
            }
        }
        else{
            printf("     ");
        }

        for(int i=0; i<47; i++){
            //corners are always empty
            if((i==0 && j==0) || (i==46 && j==0) || (i==0 && j==46) || (i==46 && j==46)){
                printf("     ");
                continue;
            }
            //places where players can put the pegs
            if(i%2==0 && j%2==0){
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
            //other for formatting and showing links
            else{ 
                if(i%2==0){
                    if(board[i][j]==5){
                        //change char here
                        printf("\033[31m  •  \033[0m");
                    }
                    else if(board[i][j]==-5){
                        //change char here
                        printf("\033[34m  •  \033[0m");
                    }
                    else if(j==1 || j==45){
                        printf("\033[31m─────\033[0m");
                    }
                    else{
                        // printf("  a  ");
                        printf("     ");
                    }
                }
                else{
                    if(board[i][j]==5){
                        //change char here
                        printf("\033[31m•\033[0m");
                    }
                    else if(board[i][j]==-5){
                        //change char here
                        printf("\033[34m•\033[0m");
                    }
                    else if(i==1 || i==45){
                        printf("\033[34m│\033[0m");
                    }
                    else if(j==1 || j==45){
                        printf("\033[31m─\033[0m");
                    }
                    else{
                        // printf("b");
                        printf(" ");
                    }
                } 
            }

        }
        printf("\n");
    }
}