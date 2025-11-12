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
                    board[cx][(y1)+j]=5;
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
                addlinktosimpgrp(x1,y1,x2,y2,redsimp);
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
                    board[cx][(y1)+j]=5;
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
                addlinktosimpgrp(x1,y1,x2,y2,redsimp);
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
                    board[cx][(y1)-j]=5;
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
                addlinktosimpgrp(x1,y1,x2,y2,redsimp);
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
                    board[cx][(y1)-j]=5;
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
                addlinktosimpgrp(x1,y1,x2,y2,redsimp);
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
                    board[(x1)+j][cy]=5;
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
                addlinktosimpgrp(x1,y1,x2,y2,redsimp);
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
                    board[(x1)-j][cy]=5;
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
                addlinktosimpgrp(x1,y1,x2,y2,redsimp);
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
                    board[(x1)+j][cy]=5;
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
                addlinktosimpgrp(x1,y1,x2,y2,redsimp);
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
                    board[(x1)-j][cy]=5;
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
                addlinktosimpgrp(x1,y1,x2,y2,redsimp);
            }
        }
    }

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
