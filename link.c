#include <stdio.h>
#include <stdlib.h>
#include "link.h"
#include "logic.h"

void makelink(int board[47][47], int x1, int y1, int x2, int y2, linkgroup* redgrp, linkgroup* blugrp){

    if(x1<0 || x1>46 || y1<0 || y1>46 || x2<0 || x2>46 || y2<0 || y2>46){
        printf("trying to link out of bound\n");
        return;
    }

    int flagn=0;
    int flag=0;
    int except=0;
    int cx;
    int cy;

    //if both pegs are red
    if(board[x1][y1]==1 && board[x2][y2]==1){
        if((x2)-(x1)==2 && (y2)-(y1)==4){
            //vertical right down link
            printf("case: vrd\n"); //debug
            cx = (x1)+1;
            for(int j=0; j<=4; j++){
                //condition that checks if it is overlapping any of the current links/pegs
                if(board[cx][(y1)+j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n"); //debug
                    break;
                }
            }
            if(flag && board[cx][(y1)+flagn]==5){
                //check for exception cases
                //need to add extra condition in above if condition to differentiate cases where its own link intersection and other link intersection
                    for(int i=0; i<redgrp->nsl; i++){
                        if((redgrp->singllinks[i]->p1.x==x2 && redgrp->singllinks[i]->p1.y==y2) || (redgrp->singllinks[i]->p2.x==x2 && redgrp->singllinks[i]->p2.y==y2)){
                            except=1;
                            break;
                        }    
                    }    
                if(except){printf("exception: collision allowed\n");} //debug
            }
            if(flag==0 || (flag==1 && except==1)){
                for(int j=0; j<=4; j++){
                        board[cx][(y1)+j]=5;
                }
                //add the link
                addlinktogrp(x1,y1,x2,y2,redgrp);
            }
        }

        else if((x2)-(x1)==-2 && (y2)-(y1)==4){
            //vertical left down link
            printf("case: vld\n"); //debug
            cx = (x1)-1;
            for(int j=0; j<=4; j++){
                if(board[cx][(y1)+j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
            }
            if(flag && board[cx][(y1)+flagn]==5){
                    for(int i=0; i<redgrp->nsl; i++){
                        if((redgrp->singllinks[i]->p1.x==x2 && redgrp->singllinks[i]->p1.y==y2) || (redgrp->singllinks[i]->p2.x==x2 && redgrp->singllinks[i]->p2.y==y2)){
                            except=1;
                            break;
                        }    
                    }    
                if(except){printf("exception: collision allowed\n");} //debug
            }
            if(flag==0 || (flag==1 && except==1)){
                for(int j=0; j<=4; j++){
                        board[cx][(y1)+j]=5;
                }
                addlinktogrp(x1,y1,x2,y2,redgrp);
            }
        }

        else if((x2)-(x1)==2 && (y2)-(y1)==-4){
            //vertical right up link
            printf("case: vru\n"); //debug
            cx = (x1)+1;
            for(int j=0; j<=4; j++){
                if(board[cx][(y1)-j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
            }
            if(flag && board[cx][(y1)-flagn]==5){
                    for(int i=0; i<redgrp->nsl; i++){
                        if((redgrp->singllinks[i]->p1.x==x2 && redgrp->singllinks[i]->p1.y==y2) || (redgrp->singllinks[i]->p2.x==x2 && redgrp->singllinks[i]->p2.y==y2)){
                            except=1;
                            break;
                        }    
                    }    
                if(except){printf("exception: collision allowed\n");} //debug
            }
            if(flag==0 || (flag==1 && except==1)){
                for(int j=0; j<=4; j++){
                        board[cx][(y1)-j]=5;
                }
                addlinktogrp(x1,y1,x2,y2,redgrp);
            }
        }

        else if((x2)-(x1)==-2 && (y2)-(y1)==-4){
            //vertical left up link
            printf("case: vlu\n"); //debug
            cx = (x1)-1;
            for(int j=0; j<=4; j++){
                if(board[cx][(y1)-j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
            }
            if(flag && board[cx][(y1)-flagn]==5){
                    for(int i=0; i<redgrp->nsl; i++){
                        if((redgrp->singllinks[i]->p1.x==x2 && redgrp->singllinks[i]->p1.y==y2) || (redgrp->singllinks[i]->p2.x==x2 && redgrp->singllinks[i]->p2.y==y2)){
                            except=1;
                            break;
                        }    
                    }    
                if(except){printf("exception: collision allowed\n");} //debug
            }
            if(flag==0 || (flag==1 && except==1)){
                for(int j=0; j<=4; j++){
                        board[cx][(y1)-j]=5;
                }
                addlinktogrp(x1,y1,x2,y2,redgrp);
            }
        }

        else if((x2)-(x1)==4 && (y2)-(y1)==2){
            //horizontal right down link
            printf("case: hrd\n"); //debug
            cy = (y1)+1;
            for(int j=0; j<=4; j++){
                if(board[(x1)+j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
            }
            if(flag && board[(x1)+flagn][cy]==5){
                    for(int i=0; i<redgrp->nsl; i++){
                        if((redgrp->singllinks[i]->p1.x==x2 && redgrp->singllinks[i]->p1.y==y2) || (redgrp->singllinks[i]->p2.x==x2 && redgrp->singllinks[i]->p2.y==y2)){
                            except=1;
                            break;
                        }    
                    }    
                if(except){printf("exception: collision allowed\n");} //debug
            }
            if(flag==0 || (flag==1 && except==1)){
                for(int j=0; j<=4; j++){
                        board[(x1)+j][cy]=5;
                }
                addlinktogrp(x1,y1,x2,y2,redgrp);
            }
        }

        else if((x2)-(x1)==-4 && (y2)-(y1)==2){
            //horizontal left down link
            printf("case: hld\n"); //debug
            cy = (y1)+1;
            for(int j=0; j<=4; j++){
                if(board[(x1)-j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
            }
            if(flag && board[(x1)-flagn][cy]==5){
                    for(int i=0; i<redgrp->nsl; i++){
                        if((redgrp->singllinks[i]->p1.x==x2 && redgrp->singllinks[i]->p1.y==y2) || (redgrp->singllinks[i]->p2.x==x2 && redgrp->singllinks[i]->p2.y==y2)){
                            except=1;
                            break;
                        }    
                    }    
                if(except){printf("exception: collision allowed\n");} //debug
            }
            if(flag==0 || (flag==1 && except==1)){
                for(int j=0; j<=4; j++){
                        board[(x1)-j][cy]=5;
                }
                addlinktogrp(x1,y1,x2,y2,redgrp);
            }
        }

        else if((x2)-(x1)==4 && (y2)-(y1)==-2){
            //horizontal right up link
            printf("case: hru\n");
            cy = (y1)-1;
            for(int j=0; j<=4; j++){
                if(board[(x1)+j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
            }
            if(flag && board[(x1)+flagn][cy]==5){
                    for(int i=0; i<redgrp->nsl; i++){
                        if((redgrp->singllinks[i]->p1.x==x2 && redgrp->singllinks[i]->p1.y==y2) || (redgrp->singllinks[i]->p2.x==x2 && redgrp->singllinks[i]->p2.y==y2)){
                            except=1;
                            break;
                        }    
                    }    
                if(except){printf("exception: collision allowed\n");} //debug
            }
            if(flag==0 || (flag==1 && except==1)){
                for(int j=0; j<=4; j++){
                        board[(x1)+j][cy]=5;
                }
                addlinktogrp(x1,y1,x2,y2,redgrp);
            }
        }

        else if((x2)-(x1)==-4 && (y2)-(y1)==-2){
            //horizontal left up link
            printf("case: hlu\n");
            cy = (y1)-1;
            for(int j=0; j<=4; j++){
                if(board[(x1)-j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
            }
            if(flag && board[(x1)-flagn][cy]==5){
                    for(int i=0; i<redgrp->nsl; i++){
                        if((redgrp->singllinks[i]->p1.x==x2 && redgrp->singllinks[i]->p1.y==y2) || (redgrp->singllinks[i]->p2.x==x2 && redgrp->singllinks[i]->p2.y==y2)){
                            except=1;
                            break;
                        }    
                    }    
                if(except){printf("exception: collision allowed\n");} //debug
            }
            if(flag==0 || (flag==1 && except==1)){
                for(int j=0; j<=4; j++){
                        board[(x1)-j][cy]=5;
                }
                addlinktogrp(x1,y1,x2,y2,redgrp);
            }
        }
    }

    //if both pegs are blue
    else if(board[x1][y1]==-1 && board[x2][y2]==-1){
        if((x2)-(x1)==2 && (y2)-(y1)==4){
            //vertical right down link
            printf("case: vrd\n"); //debug
            cx = (x1)+1;
            for(int j=0; j<=4; j++){
                //condition that checks if it is overlapping any of the current links/pegs
                if(board[cx][(y1)+j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n"); //debug
                    break;
                }
            }
            if(flag && board[cx][(y1)+flagn]==-5){
                //check for exception cases
                //need to add extra condition in above if condition to differentiate cases where its own link intersection and other link intersection
                    for(int i=0; i<blugrp->nsl; i++){
                        if((blugrp->singllinks[i]->p1.x==x2 && blugrp->singllinks[i]->p1.y==y2) || (blugrp->singllinks[i]->p2.x==x2 && blugrp->singllinks[i]->p2.y==y2)){
                            except=1;
                            break;
                        }    
                    }    
                if(except){printf("exception: collision allowed\n");} //debug
            }
            if(flag==0 || (flag==1 && except==1)){
                for(int j=0; j<=4; j++){
                        board[cx][(y1)+j]=-5;
                }
                //add the link
                addlinktogrp(x1,y1,x2,y2,blugrp);
            }
        }

        else if((x2)-(x1)==-2 && (y2)-(y1)==4){
            //vertical left down link
            printf("case: vld\n"); //debug
            cx = (x1)-1;
            for(int j=0; j<=4; j++){
                if(board[cx][(y1)+j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
            }
            if(flag && board[cx][(y1)+flagn]==-5){
                    for(int i=0; i<blugrp->nsl; i++){
                        if((blugrp->singllinks[i]->p1.x==x2 && blugrp->singllinks[i]->p1.y==y2) || (blugrp->singllinks[i]->p2.x==x2 && blugrp->singllinks[i]->p2.y==y2)){
                            except=1;
                            break;
                        }    
                    }      
                if(except){printf("exception: collision allowed\n");} //debug
            }
            if(flag==0 || (flag==1 && except==1)){
                for(int j=0; j<=4; j++){
                        board[cx][(y1)+j]=-5;
                }
                addlinktogrp(x1,y1,x2,y2,blugrp);
            }
        }

        else if((x2)-(x1)==2 && (y2)-(y1)==-4){
            //vertical right up link
            printf("case: vru\n"); //debug
            cx = (x1)+1;
            for(int j=0; j<=4; j++){
                if(board[cx][(y1)-j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
            }
            if(flag && board[cx][(y1)-flagn]==-5){
                    for(int i=0; i<blugrp->nsl; i++){
                        if((blugrp->singllinks[i]->p1.x==x2 && blugrp->singllinks[i]->p1.y==y2) || (blugrp->singllinks[i]->p2.x==x2 && blugrp->singllinks[i]->p2.y==y2)){
                            except=1;
                            break;
                        }    
                    }      
                if(except){printf("exception: collision allowed\n");} //debug
            }
            if(flag==0 || (flag==1 && except==1)){
                for(int j=0; j<=4; j++){
                        board[cx][(y1)-j]=-5;
                }
                addlinktogrp(x1,y1,x2,y2,blugrp);
            }
        }

        else if((x2)-(x1)==-2 && (y2)-(y1)==-4){
            //vertical left up link
            printf("case: vlu\n"); //debug
            cx = (x1)-1;
            for(int j=0; j<=4; j++){
                if(board[cx][(y1)-j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
            }
            if(flag && board[cx][(y1)-flagn]==-5){
                    for(int i=0; i<blugrp->nsl; i++){
                        if((blugrp->singllinks[i]->p1.x==x2 && blugrp->singllinks[i]->p1.y==y2) || (blugrp->singllinks[i]->p2.x==x2 && blugrp->singllinks[i]->p2.y==y2)){
                            except=1;
                            break;
                        }    
                    }      
                if(except){printf("exception: collision allowed\n");} //debug
            }
            if(flag==0 || (flag==1 && except==1)){
                for(int j=0; j<=4; j++){
                        board[cx][(y1)-j]=-5;
                }
                addlinktogrp(x1,y1,x2,y2,blugrp);
            }
        }

        else if((x2)-(x1)==4 && (y2)-(y1)==2){
            //horizontal right down link
            printf("case: hrd\n"); //debug
            cy = (y1)+1;
            for(int j=0; j<=4; j++){
                if(board[(x1)+j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
            }
            if(flag && board[(x1)+flagn][cy]==-5){
                    for(int i=0; i<blugrp->nsl; i++){
                        if((blugrp->singllinks[i]->p1.x==x2 && blugrp->singllinks[i]->p1.y==y2) || (blugrp->singllinks[i]->p2.x==x2 && blugrp->singllinks[i]->p2.y==y2)){
                            except=1;
                            break;
                        }    
                    }      
                if(except){printf("exception: collision allowed\n");} //debug
            }
            if(flag==0 || (flag==1 && except==1)){
                for(int j=0; j<=4; j++){
                        board[(x1)+j][cy]=-5;
                }
                addlinktogrp(x1,y1,x2,y2,blugrp);
            }
        }

        else if((x2)-(x1)==-4 && (y2)-(y1)==2){
            //horizontal left down link
            printf("case: hld\n"); //debug
            cy = (y1)+1;
            for(int j=0; j<=4; j++){
                if(board[(x1)-j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
            }
            if(flag && board[(x1)-flagn][cy]==-5){
                    for(int i=0; i<blugrp->nsl; i++){
                        if((blugrp->singllinks[i]->p1.x==x2 && blugrp->singllinks[i]->p1.y==y2) || (blugrp->singllinks[i]->p2.x==x2 && blugrp->singllinks[i]->p2.y==y2)){
                            except=1;
                            break;
                        }    
                    }      
                if(except){printf("exception: collision allowed\n");} //debug
            }
            if(flag==0 || (flag==1 && except==1)){
                for(int j=0; j<=4; j++){
                        board[(x1)-j][cy]=-5;
                }
                addlinktogrp(x1,y1,x2,y2,blugrp);
            }
        }

        else if((x2)-(x1)==4 && (y2)-(y1)==-2){
            //horizontal right up link
            printf("case: hru\n");
            cy = (y1)-1;
            for(int j=0; j<=4; j++){
                if(board[(x1)+j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
            }
            if(flag && board[(x1)+flagn][cy]==-5){
                    for(int i=0; i<blugrp->nsl; i++){
                        if((blugrp->singllinks[i]->p1.x==x2 && blugrp->singllinks[i]->p1.y==y2) || (blugrp->singllinks[i]->p2.x==x2 && blugrp->singllinks[i]->p2.y==y2)){
                            except=1;
                            break;
                        }    
                    }      
                if(except){printf("exception: collision allowed\n");} //debug
            }
            if(flag==0 || (flag==1 && except==1)){
                for(int j=0; j<=4; j++){
                        board[(x1)+j][cy]=-5;
                }
                addlinktogrp(x1,y1,x2,y2,blugrp);
            }
        }

        else if((x2)-(x1)==-4 && (y2)-(y1)==-2){
            //horizontal left up link
            printf("case: hlu\n");
            cy = (y1)-1;
            for(int j=0; j<=4; j++){
                if(board[(x1)-j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    break;
                }
            }
            if(flag && board[(x1)-flagn][cy]==-5){
                    for(int i=0; i<blugrp->nsl; i++){
                        if((blugrp->singllinks[i]->p1.x==x2 && blugrp->singllinks[i]->p1.y==y2) || (blugrp->singllinks[i]->p2.x==x2 && blugrp->singllinks[i]->p2.y==y2)){
                            except=1;
                            break;
                        }    
                    }      
                if(except){printf("exception: collision allowed\n");} //debug
            }
            if(flag==0 || (flag==1 && except==1)){
                for(int j=0; j<=4; j++){
                        board[(x1)-j][cy]=-5;
                }
                addlinktogrp(x1,y1,x2,y2,blugrp);
            }
        }
    }

    else{
        printf("no link possible\n");
    }

    return;
}
