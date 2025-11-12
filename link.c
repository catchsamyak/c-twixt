#include <stdio.h>
#include <stdlib.h>
#include "link.h"

linkgroup* addlinktogrp(int x1, int y1, int x2, int y2, linkgroup* grp){
    link* new = malloc(sizeof(link));
    new->p1.x=x1;
    new->p1.y=y1;
    new->p2.x=x2;
    new->p2.y=y2;
    (grp->n)++;
    grp->links = realloc(grp->links,(grp->n)*sizeof(link*));
    grp->links[(grp->n-1)] = new;
    return grp->links;
}

linkgroup* addlinktosimpgrp(int x1, int y1, int x2, int y2, linkgroup* grp){
    //to be done
    //add the link and simplify the grp
    //later as part of the logic, we will check if there is a link in this grp such that the x1-x2=23*2
}

void makelink(int board[47][47], int x1, int y1, int x2, int y2, linkgroup* red, linkgroup* blu, linkgroup* redsimp, linkgroup* blusimp){
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
                red->links=addlinktogrp(x1,y1,x2,y2,red);
                redsimp->links=addlinktosimpgrp(x1,y1,x2,y2,redsimp);
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
                red->links=addlinktogrp(x1,y1,x2,y2,red);
                redsimp->links=addlinktosimpgrp(x1,y1,x2,y2,redsimp);
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
                red->links=addlinktogrp(x1,y1,x2,y2,red);
                redsimp->links=addlinktosimpgrp(x1,y1,x2,y2,redsimp);
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
                red->links=addlinktogrp(x1,y1,x2,y2,red);
                redsimp->links=addlinktosimpgrp(x1,y1,x2,y2,redsimp);
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
                red->links=addlinktogrp(x1,y1,x2,y2,red);
                redsimp->links=addlinktosimpgrp(x1,y1,x2,y2,redsimp);
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
                red->links=addlinktogrp(x1,y1,x2,y2,red);
                redsimp->links=addlinktosimpgrp(x1,y1,x2,y2,redsimp);
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
                red->links=addlinktogrp(x1,y1,x2,y2,red);
                redsimp->links=addlinktosimpgrp(x1,y1,x2,y2,redsimp);
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
                red->links=addlinktogrp(x1,y1,x2,y2,red);
                redsimp->links=addlinktosimpgrp(x1,y1,x2,y2,redsimp);
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
                blu->links=addlinktogrp(x1,y1,x2,y2,blu);
                blusimp->links=addlinktosimpgrp(x1,y1,x2,y2,blusimp);
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
                blu->links=addlinktogrp(x1,y1,x2,y2,blu);
                blusimp->links=addlinktosimpgrp(x1,y1,x2,y2,blusimp);
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
                blu->links=addlinktogrp(x1,y1,x2,y2,blu);
                blusimp->links=addlinktosimpgrp(x1,y1,x2,y2,blusimp);
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
                blu->links=addlinktogrp(x1,y1,x2,y2,blu);
                blusimp->links=addlinktosimpgrp(x1,y1,x2,y2,blusimp);
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
                blu->links=addlinktogrp(x1,y1,x2,y2,blu);
                blusimp->links=addlinktosimpgrp(x1,y1,x2,y2,blusimp);
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
                blu->links=addlinktogrp(x1,y1,x2,y2,blu);
                blusimp->links=addlinktosimpgrp(x1,y1,x2,y2,blusimp);
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
                blu->links=addlinktogrp(x1,y1,x2,y2,blu);
                blusimp->links=addlinktosimpgrp(x1,y1,x2,y2,blusimp);
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
                blu->links=addlinktogrp(x1,y1,x2,y2,blu);
                blusimp->links=addlinktosimpgrp(x1,y1,x2,y2,blusimp);
            }
        }
    }

    else{
        printf("no link possible\n");
    }

    return;
}

void unmakelink(int board[47][47], int x1, int y1, int x2, int y2, linkgroup* red, linkgroup* blu, linkgroup* redsimp, linkgroup* blusimp, int playr){
    //to be done
    //check if the link is valid by making sure all of those middle ones are 5/-5 9red/blu)
    //only red can remove red links check that with playr
    //similar to above one, just remove the links (make them all zeros) if the input is valid
    return;
}

//maybe addlinktogrp and storing all links for red/blu is useless (can be removed by removing function and all the calls)
//for autolink try all 8 possible positions
//when someone puts at the end then check if there is full length connection you can group from red/blue links think of combining pairs logic


