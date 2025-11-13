#include <stdio.h>
#include <stdlib.h>
#include "link.h"
#include "logic.h"

void makelink(int board[47][47], int x1, int y1, int x2, int y2, linkgroup* redsimp, linkgroup* blusimp){

    if(x1<0 || x1>46 || y1<0 || y1>46 || x2<0 || x2>46 || y2<0 || y2>46){
        printf("trying to link out of bound\n");
        return;
    }

    //if both pegs are red
    if(board[x1][y1]==1 && board[x2][y2]==1){
        if((x2)-(x1)==2 && (y2)-(y1)==4){
            //vertical right down link
            printf("case: vrd\n");
            int flagn=0;
            int flag=0;
            int cx = (x1)+1;
            for(int j=0; j<=4; j++){
                //condition that checks if it is overlapping any of the current links/pegs
                if(board[cx][(y1)+j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
                else{
                    //start filling
                    board[cx][(y1)+j]=5;
                }
            }
            if(flag){
                //check for exception cases
                if(flagn==4||flagn==3){
                    //need to add extra condition in above if condition to differentiate cases where its own link intersection and other link intersection
                    printf("collision allowed\n");
                    for(int j=flagn; j<=4; j++){
                        board[cx][(y1)+j]=5;
                    }
                    //and then add it
                    addlinktosimpgrp(x1,y1,x2,y2,redsimp);
                }
                //clear out previous filled
                else{
                    for(int j=0; j<flagn; j++){
                        board[cx][(y1)+j]=0;
                    }
                }
            }
            else{
                //add the link
                addlinktosimpgrp(x1,y1,x2,y2,redsimp);
            }
        }
        else if((x2)-(x1)==-2 && (y2)-(y1)==4){
            //vertical left down link
            printf("case: vld\n");
            int flagn=0;
            int flag=0;
            int cx = (x1)-1;
            for(int j=0; j<=4; j++){
                //condition that checks if it is overlapping any of the current links/pegs
                if(board[cx][(y1)+j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
                else{
                    //start filling
                    board[cx][(y1)+j]=5;
                }
            }
            if(flag){
                //check for exception cases
                if(flagn==3 || flagn==4){
                    printf("collision allowed\n");
                    for(int j=flagn; j<=4; j++){
                        board[cx][(y1)+j]=5;
                    }
                    //and then add it
                    addlinktosimpgrp(x1,y1,x2,y2,redsimp);
                }
                //clear out previous filled
                else{
                    for(int j=0; j<flagn; j++){
                        board[cx][(y1)+j]=0;
                    }
                }
            }
            else{
                //add the link
                addlinktosimpgrp(x1,y1,x2,y2,redsimp);
            }
        }
        else if((x2)-(x1)==2 && (y2)-(y1)==-4){
            //vertical right up link
            printf("case: vru\n");
            int flagn=0;
            int flag=0;
            int cx = (x1)+1;
            for(int j=0; j<=4; j++){
                //condition that checks if it is overlapping any of the current links/pegs
                if(board[cx][(y1)-j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
                else{
                    //start filling
                    board[cx][(y1)-j]=5;
                }
            }
            if(flag){
                //check for exception cases
                if(flagn==3 || flagn==4){
                    printf("collision allowed\n");
                    for(int j=flagn; j<=4; j++){
                        board[cx][(y1)-j]=5;
                    }
                    //and then add it
                    addlinktosimpgrp(x1,y1,x2,y2,redsimp);
                }
                //clear out previous filled
                else{
                    for(int j=0; j<flagn; j++){
                        board[cx][(y1)-j]=0;
                    }
                }
            }
            else{
                //add the link
                addlinktosimpgrp(x1,y1,x2,y2,redsimp);
            }
        }
        else if((x2)-(x1)==-2 && (y2)-(y1)==-4){
            //vertical left up link
            printf("case: vlu\n");
            int flagn=0;
            int flag=0;
            int cx = (x1)-1;
            for(int j=0; j<=4; j++){
                //condition that checks if it is overlapping any of the current links/pegs
                if(board[cx][(y1)-j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
                else{
                    //start filling
                    board[cx][(y1)-j]=5;
                }
            }
            if(flag){
                //check for exception cases
                if(flagn==3 || flagn==4){
                    printf("collision allowed\n");
                    for(int j=flagn; j<=4; j++){
                        board[cx][(y1)-j]=5;
                    }
                    //and then add it
                    addlinktosimpgrp(x1,y1,x2,y2,redsimp);
                }
                //clear out previous filled
                else{
                    for(int j=0; j<flagn; j++){
                        board[cx][(y1)-j]=0;
                    }
                }
            }
            else{
                //add the link
                addlinktosimpgrp(x1,y1,x2,y2,redsimp);
            }
        }
        else if((x2)-(x1)==4 && (y2)-(y1)==2){
            //horizontal right down link
            printf("case: hrd\n");
            int flagn=0;
            int flag=0;
            int cy = (y1)+1;
            for(int j=0; j<=4; j++){
                //condition that checks if it is overlapping any of the current links/pegs
                if(board[(x1)+j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
                else{
                    //start filling
                    board[(x1)+j][cy]=5;
                }
            }
            if(flag){
                if(flagn==3 || flagn==4){
                    printf("collision allowed\n");
                    for(int j=flagn; j<=4; j++){
                        board[(x1)+j][cy]=5;
                    }
                    //and then add it
                    addlinktosimpgrp(x1,y1,x2,y2,redsimp);
                }
                else{
                    //clear out previous filled
                    for(int j=0; j<flagn; j++){
                        board[(x1)+j][cy]=0;
                    }
                }
            }
            else{
                //add the link
                addlinktosimpgrp(x1,y1,x2,y2,redsimp);
            }
        }
        else if((x2)-(x1)==-4 && (y2)-(y1)==2){
            //horizontal left down link
            printf("case: hld\n");
            int flagn=0;
            int flag=0;
            int cy = (y1)+1;
            for(int j=0; j<=4; j++){
                //condition that checks if it is overlapping any of the current links/pegs
                if(board[(x1)-j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
                else{
                    //start filling
                    board[(x1)-j][cy]=5;
                }
            }
            if(flag){
                if(flagn==3 || flagn==4){
                    printf("collision allowed\n");
                    for(int j=flagn; j<=4; j++){
                        board[(x1)-j][cy]=5;
                    }
                    //and then add it
                    addlinktosimpgrp(x1,y1,x2,y2,redsimp);
                }
                else{
                    //clear out previous filled
                    for(int j=0; j<flagn; j++){
                        board[(x1)-j][cy]=0;
                    }
                }
            }
            else{
                //add the link
                addlinktosimpgrp(x1,y1,x2,y2,redsimp);
            }
        }
        else if((x2)-(x1)==4 && (y2)-(y1)==-2){
            //horizontal right up link
            printf("case: hru\n");
            int flagn=0;
            int flag=0;
            int cy = (y1)-1;
            for(int j=0; j<=4; j++){
                //condition that checks if it is overlapping any of the current links/pegs
                if(board[(x1)+j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
                else{
                    //start filling
                    board[(x1)+j][cy]=5;
                }
            }
            if(flag){
                if(flagn==3 || flagn==4){
                    printf("collision allowed\n");
                    for(int j=flagn; j<=4; j++){
                        board[(x1)+j][cy]=5;
                    }
                    //and then add it
                    addlinktosimpgrp(x1,y1,x2,y2,redsimp);
                }
                else{
                    //clear out previous filled
                    for(int j=0; j<flagn; j++){
                        board[(x1)+j][cy]=0;
                    }
                }
            }
            else{
                //add the link
                addlinktosimpgrp(x1,y1,x2,y2,redsimp);
            }
        }
        else if((x2)-(x1)==-4 && (y2)-(y1)==-2){
            //horizontal left up link
            printf("case: hlu\n");
            int flagn=0;
            int flag=0;
            int cy = (y1)-1;
            for(int j=0; j<=4; j++){
                //condition that checks if it is overlapping any of the current links/pegs
                if(board[(x1)-j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
                else{
                    //start filling
                    board[(x1)-j][cy]=5;
                }
            }
            if(flag){
                if(flagn==3 || flagn==4){
                    printf("collision allowed\n");
                    for(int j=flagn; j<=4; j++){
                        board[(x1)-j][cy]=5;
                    }
                    //and then add it
                    addlinktosimpgrp(x1,y1,x2,y2,redsimp);
                }
                else{
                    //clear out previous filled
                    for(int j=0; j<flagn; j++){
                        board[(x1)-j][cy]=0;
                    }
                }
            }
            else{
                //add the link
                addlinktosimpgrp(x1,y1,x2,y2,redsimp);
            }
        }
    }

    //this blue stuff is outdated
    //after figuring out the logic properly for red, adjust all of this accordingly (changes can be viewed in commit)
    //if both pegs are blue
    else if(board[x1][y1]==-1 && board[x2][y2]==-1){
        if((x2)-(x1)==2 && (y2)-(y1)==4){
            //vertical right up link
            int flagn=0;
            int flag=0;
            int cx = (x1)+1;
            for(int j=0; j<=4; j++){
                //condition that checks if it is overlapping any of the current links/pegs
                if(board[cx][(y1)+j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
                else{
                    //start filling
                    board[cx][(y1)+j]=-5;
                }
            }
            if(flag){
                //clear out previous filled
                for(int j=0; j<flagn; j++){
                    board[cx][(y1)+j]=0;
                }
            }
            else{
                //add the link
                addlinktosimpgrp(x1,y1,x2,y2,blusimp);
            }
        }
        else if((x2)-(x1)==-2 && (y2)-(y1)==4){
            //vertical left up link
            int flagn=0;
            int flag=0;
            int cx = (x1)-1;
            for(int j=0; j<=4; j++){
                //condition that checks if it is overlapping any of the current links/pegs
                if(board[cx][(y1)+j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
                else{
                    //start filling
                    board[cx][(y1)+j]=-5;
                }
            }
            if(flag){
                //clear out previous filled
                for(int j=0; j<flagn; j++){
                    board[cx][(y1)+j]=0;
                }
            }
            else{
                //add the link
                addlinktosimpgrp(x1,y1,x2,y2,blusimp);
            }
        }
        else if((x2)-(x1)==2 && (y2)-(y1)==-4){
            //vertical right down link
            int flagn=0;
            int flag=0;
            int cx = (x1)+1;
            for(int j=0; j<=4; j++){
                //condition that checks if it is overlapping any of the current links/pegs
                if(board[cx][(y1)-j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
                else{
                    //start filling
                    board[cx][(y1)-j]=-5;
                }
            }
            if(flag){
                //clear out previous filled
                for(int j=0; j<flagn; j++){
                    board[cx][(y1)-j]=0;
                }
            }
            else{
                //add the link
                addlinktosimpgrp(x1,y1,x2,y2,blusimp);
            }
        }
        else if((x2)-(x1)==-2 && (y2)-(y1)==-4){
            //vertical left down link
            int flagn=0;
            int flag=0;
            int cx = (x1)-1;
            for(int j=0; j<=4; j++){
                //condition that checks if it is overlapping any of the current links/pegs
                if(board[cx][(y1)-j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
                else{
                    //start filling
                    board[cx][(y1)-j]=-5;
                }
            }
            if(flag){
                //clear out previous filled
                for(int j=0; j<flagn; j++){
                    board[cx][(y1)-j]=0;
                }
            }
            else{
                //add the link
                addlinktosimpgrp(x1,y1,x2,y2,blusimp);
            }
        }
        else if((x2)-(x1)==4 && (y2)-(y1)==2){
            //horizontal right up link
            int flagn=0;
            int flag=0;
            int cy = (y1)+1;
            for(int j=0; j<=4; j++){
                //condition that checks if it is overlapping any of the current links/pegs
                if(board[(x1)+j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
                else{
                    //start filling
                    board[(x1)+j][cy]=-5;
                }
            }
            if(flag){
                //clear out previous filled
                for(int j=0; j<flagn; j++){
                    board[(x1)+j][cy]=0;
                }
            }
            else{
                //add the link
                addlinktosimpgrp(x1,y1,x2,y2,blusimp);
            }
        }
        else if((x2)-(x1)==-4 && (y2)-(y1)==2){
            //horizontal left up link
            int flagn=0;
            int flag=0;
            int cy = (y1)+1;
            for(int j=0; j<=4; j++){
                //condition that checks if it is overlapping any of the current links/pegs
                if(board[(x1)-j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
                else{
                    //start filling
                    board[(x1)-j][cy]=-5;
                }
            }
            if(flag){
                //clear out previous filled
                for(int j=0; j<flagn; j++){
                    board[(x1)-j][cy]=0;
                }
            }
            else{
                //add the link
                addlinktosimpgrp(x1,y1,x2,y2,blusimp);
            }
        }
        else if((x2)-(x1)==4 && (y2)-(y1)==-2){
            //horizontal right down link
            int flagn=0;
            int flag=0;
            int cy = (y1)-1;
            for(int j=0; j<=4; j++){
                //condition that checks if it is overlapping any of the current links/pegs
                if(board[(x1)+j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
                else{
                    //start filling
                    board[(x1)+j][cy]=-5;
                }
            }
            if(flag){
                //clear out previous filled
                for(int j=0; j<flagn; j++){
                    board[(x1)+j][cy]=0;
                }
            }
            else{
                //add the link
                addlinktosimpgrp(x1,y1,x2,y2,blusimp);
            }
        }
        else if((x2)-(x1)==-4 && (y2)-(y1)==-2){
            //horizontal left down link
            int flagn=0;
            int flag=0;
            int cy = (y1)-1;
            for(int j=0; j<=4; j++){
                //condition that checks if it is overlapping any of the current links/pegs
                if(board[(x1)-j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
                else{
                    //start filling
                    board[(x1)-j][cy]=-5;
                }
            }
            if(flag){
                //clear out previous filled
                for(int j=0; j<flagn; j++){
                    board[(x1)-j][cy]=0;
                }
            }
            else{
                //add the link
                addlinktosimpgrp(x1,y1,x2,y2,blusimp);
            }
        }
    }

    else{
        printf("no link possible\n");
    }

    return;
}
