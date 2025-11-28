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
    int cx;
    int cy;
    int bigflag=0;
    int firstv1[5]={1,3,-1,0,0}; //v1 is for vrd/vld/hru/hrd
    int lastv1[5]={4,4,-1,1,3}; 
    int firstv2[5]={0,0,-1,3,1}; //v2 is for vru/vlu/hlu/hld
    int lastv2[5]={3,1,-1,4,4};
    //if both pegs are red
    if(board[x1][y1]==1 && board[x2][y2]==1){
        if((x2)-(x1)==2 && (y2)-(y1)==4){
            //vertical right down link
            printf("case: vrd\n"); //debug
            cx = (x1)+1;
            int first=0;
            int last=4;
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<redgrp->nsl; m++){
                if(((redgrp->singllinks[m]->p1.x==cx1 && redgrp->singllinks[m]->p1.y==cy1)&&(redgrp->singllinks[m]->p2.x==cx2 && redgrp->singllinks[m]->p2.y==cy2))||((redgrp->singllinks[m]->p2.x==cx1 && redgrp->singllinks[m]->p2.y==cy1)&&(redgrp->singllinks[m]->p1.x==cx2 && redgrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ red: allowed.\n",n/2); //debug
                    // first=; if this first is more then take it
                    if(firstv1[d]>first){
                        first=firstv1[d];
                    }
                    // last=; if this last is less take it
                    if(lastv1[d]<last){
                        last=lastv1[d];
                    }
                }
            }
            }
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<blugrp->nsl; m++){
                if(((blugrp->singllinks[m]->p1.x==cx1 && blugrp->singllinks[m]->p1.y==cy1)&&(blugrp->singllinks[m]->p2.x==cx2 && blugrp->singllinks[m]->p2.y==cy2))||((blugrp->singllinks[m]->p2.x==cx1 && blugrp->singllinks[m]->p2.y==cy1)&&(blugrp->singllinks[m]->p1.x==cx2 && blugrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ blue: allowed.\n",n/2); //debug
                    // first=; if this first is more then take it
                    if(firstv1[d]>first){
                        first=firstv1[d];
                    }
                    // last=; if this last is less take it
                    if(lastv1[d]<last){
                        last=lastv1[d];
                    }
                }
            }
            }
            for(int j=first; j<=last; j++){
                //already checked parallel cases now
                //condition that checks if it is overlapping any of the current links/pegs
                if(board[cx][(y1)+j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n"); //debug
                    int except=0;
                    //check for exception cases
                    if(board[cx][(y1)+flagn]==-5){
                        bigflag=1;
                        break;
                    }
                    else if(board[cx][(y1)+flagn]==5){
                        for(int i=0; i<redgrp->nsl; i++){
                            if((redgrp->singllinks[i]->p1.x==x2 && redgrp->singllinks[i]->p1.y==y2) || (redgrp->singllinks[i]->p2.x==x2 && redgrp->singllinks[i]->p2.y==y2) || (redgrp->singllinks[i]->p1.x==x1 && redgrp->singllinks[i]->p1.y==y1) || (redgrp->singllinks[i]->p2.x==x1 && redgrp->singllinks[i]->p2.y==y1)){
                                for(int h=0; h<=4; h++){
                                    if(redgrp->singllinks[i]->middle[h].x==cx && redgrp->singllinks[i]->middle[h].y==(y1)+flagn){
                                        except=1;
                                        break;
                                    }
                                }
                            }    
                        }
                        if(except!=1){
                            printf("denied: first failed found\n"); //debug
                            bigflag=1;
                            break;
                        }
                        else{
                            printf("exception: collision allowed\n"); //debug
                        }
                    }
                    else{
                        bigflag=1;
                    }
                    
                }
            }
            if(flag==0 || (flag==1 && bigflag==0)){
                peg arr[5];
                for(int j=0; j<=4; j++){
                    board[cx][(y1)+j]=5;
                    arr[j].x=cx;
                    arr[j].y=(y1)+j;
                }
                //add the link
                addlinktogrp(x1,y1,x2,y2,redgrp,arr);
            }
        }

        else if((x2)-(x1)==-2 && (y2)-(y1)==4){
            //vertical left down link
            printf("case: vld\n"); //debug
            cx = (x1)-1;
            int first=0;
            int last=4;
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<redgrp->nsl; m++){
                if(((redgrp->singllinks[m]->p1.x==cx1 && redgrp->singllinks[m]->p1.y==cy1)&&(redgrp->singllinks[m]->p2.x==cx2 && redgrp->singllinks[m]->p2.y==cy2))||((redgrp->singllinks[m]->p2.x==cx1 && redgrp->singllinks[m]->p2.y==cy1)&&(redgrp->singllinks[m]->p1.x==cx2 && redgrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ red: allowed.\n",n/2); //debug
                    if(firstv1[d]>first){
                        first=firstv1[d];
                    }
                    if(lastv1[d]<last){
                        last=lastv1[d];
                    }
                }
            }
            }
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<blugrp->nsl; m++){
                if(((blugrp->singllinks[m]->p1.x==cx1 && blugrp->singllinks[m]->p1.y==cy1)&&(blugrp->singllinks[m]->p2.x==cx2 && blugrp->singllinks[m]->p2.y==cy2))||((blugrp->singllinks[m]->p2.x==cx1 && blugrp->singllinks[m]->p2.y==cy1)&&(blugrp->singllinks[m]->p1.x==cx2 && blugrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ blue: allowed.\n",n/2); //debug
                    if(firstv1[d]>first){
                        first=firstv1[d];
                    }
                    if(lastv1[d]<last){
                        last=lastv1[d];
                    }
                }
            }
            }
            for(int j=first; j<=last; j++){
                if(board[cx][(y1)+j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    int except=0;
                    if(board[cx][(y1)+flagn]==-5){
                        bigflag=1;
                        break;
                    }
                    else if(board[cx][(y1)+flagn]==5){
                    for(int i=0; i<redgrp->nsl; i++){
                    if((redgrp->singllinks[i]->p1.x==x2 && redgrp->singllinks[i]->p1.y==y2) || (redgrp->singllinks[i]->p2.x==x2 && redgrp->singllinks[i]->p2.y==y2) || (redgrp->singllinks[i]->p1.x==x1 && redgrp->singllinks[i]->p1.y==y1) || (redgrp->singllinks[i]->p2.x==x1 && redgrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(redgrp->singllinks[i]->middle[j].x==cx && redgrp->singllinks[i]->middle[j].y==(y1)+flagn){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        printf("exception: collision allowed\n"); //debug
                    }                    
                    }
                    else{
                        bigflag=1;
                    }
                }
            }
            if(flag==0 || (flag==1 && bigflag==0)){
                peg arr[5];
                for(int j=0; j<=4; j++){
                    board[cx][(y1)+j]=5;
                    arr[j].x=cx;
                    arr[j].y=(y1)+j;
                }
                addlinktogrp(x1,y1,x2,y2,redgrp,arr);
            }
        }

        else if((x2)-(x1)==2 && (y2)-(y1)==-4){
            //vertical right up link
            printf("case: vru\n"); //debug
            cx = (x1)+1;
            int first=0;
            int last=4;
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<redgrp->nsl; m++){
                if(((redgrp->singllinks[m]->p1.x==cx1 && redgrp->singllinks[m]->p1.y==cy1)&&(redgrp->singllinks[m]->p2.x==cx2 && redgrp->singllinks[m]->p2.y==cy2))||((redgrp->singllinks[m]->p2.x==cx1 && redgrp->singllinks[m]->p2.y==cy1)&&(redgrp->singllinks[m]->p1.x==cx2 && redgrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ red: allowed.\n",n/2); //debug
                    if(firstv2[d]>first){
                        first=firstv2[d];
                    }
                    if(lastv2[d]<last){
                        last=lastv2[d];
                    }
                }
            }
            }
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<blugrp->nsl; m++){
                if(((blugrp->singllinks[m]->p1.x==cx1 && blugrp->singllinks[m]->p1.y==cy1)&&(blugrp->singllinks[m]->p2.x==cx2 && blugrp->singllinks[m]->p2.y==cy2))||((blugrp->singllinks[m]->p2.x==cx1 && blugrp->singllinks[m]->p2.y==cy1)&&(blugrp->singllinks[m]->p1.x==cx2 && blugrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ blue: allowed.\n",n/2); //debug
                    if(firstv2[d]>first){
                        first=firstv2[d];
                    }
                    if(lastv2[d]<last){
                        last=lastv2[d];
                    }
                }
            }
            }
            for(int j=first; j<=last; j++){
                if(board[cx][(y1)-j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    int except=0;
                    if(board[cx][(y1)-flagn]==-5){
                        bigflag=1;
                        break;
                    }
                    else if(board[cx][(y1)-flagn]==5){
                    for(int i=0; i<redgrp->nsl; i++){
                    if((redgrp->singllinks[i]->p1.x==x2 && redgrp->singllinks[i]->p1.y==y2) || (redgrp->singllinks[i]->p2.x==x2 && redgrp->singllinks[i]->p2.y==y2) || (redgrp->singllinks[i]->p1.x==x1 && redgrp->singllinks[i]->p1.y==y1) || (redgrp->singllinks[i]->p2.x==x1 && redgrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(redgrp->singllinks[i]->middle[j].x==cx && redgrp->singllinks[i]->middle[j].y==(y1)-flagn){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        printf("exception: collision allowed\n"); //debug
                    }                    
                    }
                    else{
                        bigflag=1;
                    }
                }
            }
            if(flag==0 || (flag==1 && bigflag==0)){
                peg arr[5];
                for(int j=0; j<=4; j++){
                    board[cx][(y1)-j]=5;
                    arr[j].x=cx;
                    arr[j].y=(y1)-j;
                }
                addlinktogrp(x1,y1,x2,y2,redgrp,arr);
            }
        }

        else if((x2)-(x1)==-2 && (y2)-(y1)==-4){
            //vertical left up link
            printf("case: vlu\n"); //debug
            cx = (x1)-1;
            int first=0;
            int last=4;
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<redgrp->nsl; m++){
                if(((redgrp->singllinks[m]->p1.x==cx1 && redgrp->singllinks[m]->p1.y==cy1)&&(redgrp->singllinks[m]->p2.x==cx2 && redgrp->singllinks[m]->p2.y==cy2))||((redgrp->singllinks[m]->p2.x==cx1 && redgrp->singllinks[m]->p2.y==cy1)&&(redgrp->singllinks[m]->p1.x==cx2 && redgrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ red: allowed.\n",n/2); //debug
                    if(firstv2[d]>first){
                        first=firstv2[d];
                    }
                    if(lastv2[d]<last){
                        last=lastv2[d];
                    }
                }
            }
            }
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<blugrp->nsl; m++){
                if(((blugrp->singllinks[m]->p1.x==cx1 && blugrp->singllinks[m]->p1.y==cy1)&&(blugrp->singllinks[m]->p2.x==cx2 && blugrp->singllinks[m]->p2.y==cy2))||((blugrp->singllinks[m]->p2.x==cx1 && blugrp->singllinks[m]->p2.y==cy1)&&(blugrp->singllinks[m]->p1.x==cx2 && blugrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ blue: allowed.\n",n/2); //debug
                    if(firstv2[d]>first){
                        first=firstv2[d];
                    }
                    if(lastv2[d]<last){
                        last=lastv2[d];
                    }
                }
            }
            }
            for(int j=first; j<=last; j++){
                if(board[cx][(y1)-j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    int except=0;
                    if(board[cx][(y1)-flagn]==-5){
                        bigflag=1;
                        break;
                    }
                    else if(board[cx][(y1)-flagn]==5){
                    for(int i=0; i<redgrp->nsl; i++){
                    if((redgrp->singllinks[i]->p1.x==x2 && redgrp->singllinks[i]->p1.y==y2) || (redgrp->singllinks[i]->p2.x==x2 && redgrp->singllinks[i]->p2.y==y2) || (redgrp->singllinks[i]->p1.x==x1 && redgrp->singllinks[i]->p1.y==y1) || (redgrp->singllinks[i]->p2.x==x1 && redgrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(redgrp->singllinks[i]->middle[j].x==cx && redgrp->singllinks[i]->middle[j].y==(y1)-flagn){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        printf("exception: collision allowed\n"); //debug
                    }                    
                    }
                    else{
                        bigflag=1;
                    }
                }
            }
            if(flag==0 || (flag==1 && bigflag==0)){
                peg arr[5];
                for(int j=0; j<=4; j++){
                    board[cx][(y1)-j]=5;
                    arr[j].x=cx;
                    arr[j].y=(y1)-j;
                }
                addlinktogrp(x1,y1,x2,y2,redgrp,arr);
            }
        }

        else if((x2)-(x1)==4 && (y2)-(y1)==2){
            //horizontal right down link
            printf("case: hrd\n"); //debug
            cy = (y1)+1;
            int first=0;
            int last=4;
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1+n;
                int cy1=y1;
                int cx2=x2+n;
                int cy2=y2;
            for(int m=0; m<redgrp->nsl; m++){
                if(((redgrp->singllinks[m]->p1.x==cx1 && redgrp->singllinks[m]->p1.y==cy1)&&(redgrp->singllinks[m]->p2.x==cx2 && redgrp->singllinks[m]->p2.y==cy2))||((redgrp->singllinks[m]->p2.x==cx1 && redgrp->singllinks[m]->p2.y==cy1)&&(redgrp->singllinks[m]->p1.x==cx2 && redgrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ red: allowed.\n",n/2); //debug
                    if(firstv1[d]>first){
                        first=firstv1[d];
                    }
                    if(lastv1[d]<last){
                        last=lastv1[d];
                    }
                }
            }
            }
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<blugrp->nsl; m++){
                if(((blugrp->singllinks[m]->p1.x==cx1 && blugrp->singllinks[m]->p1.y==cy1)&&(blugrp->singllinks[m]->p2.x==cx2 && blugrp->singllinks[m]->p2.y==cy2))||((blugrp->singllinks[m]->p2.x==cx1 && blugrp->singllinks[m]->p2.y==cy1)&&(blugrp->singllinks[m]->p1.x==cx2 && blugrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ blue: allowed.\n",n/2); //debug
                    if(firstv1[d]>first){
                        first=firstv1[d];
                    }
                    if(lastv1[d]<last){
                        last=lastv1[d];
                    }
                }
            }
            }
            for(int j=first; j<=last; j++){
                if(board[(x1)+j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    int except=0;
                    if(board[(x1)+flagn][cy]==-5){
                        bigflag=1;
                        break;
                    }
                    else if(board[(x1)+flagn][cy]==5){
                    for(int i=0; i<redgrp->nsl; i++){
                    if((redgrp->singllinks[i]->p1.x==x2 && redgrp->singllinks[i]->p1.y==y2) || (redgrp->singllinks[i]->p2.x==x2 && redgrp->singllinks[i]->p2.y==y2) || (redgrp->singllinks[i]->p1.x==x1 && redgrp->singllinks[i]->p1.y==y1) || (redgrp->singllinks[i]->p2.x==x1 && redgrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(redgrp->singllinks[i]->middle[j].x==(x1)+flagn && redgrp->singllinks[i]->middle[j].y==cy){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        printf("exception: collision allowed\n"); //debug
                    }                    
                    }
                    else{
                        bigflag=1;
                    }
                }
            }
            if(flag==0 || (flag==1 && bigflag==0)){
                peg arr[5];
                for(int j=0; j<=4; j++){
                    board[(x1)+j][cy]=5;
                    arr[j].x=(x1)+j;
                    arr[j].y=cy;
                }
                addlinktogrp(x1,y1,x2,y2,redgrp,arr);
            }
        }

        else if((x2)-(x1)==-4 && (y2)-(y1)==2){
            //horizontal left down link
            printf("case: hld\n"); //debug
            cy = (y1)+1;
            int first=0;
            int last=4;
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1+n;
                int cy1=y1;
                int cx2=x2+n;
                int cy2=y2;
            for(int m=0; m<redgrp->nsl; m++){
                if(((redgrp->singllinks[m]->p1.x==cx1 && redgrp->singllinks[m]->p1.y==cy1)&&(redgrp->singllinks[m]->p2.x==cx2 && redgrp->singllinks[m]->p2.y==cy2))||((redgrp->singllinks[m]->p2.x==cx1 && redgrp->singllinks[m]->p2.y==cy1)&&(redgrp->singllinks[m]->p1.x==cx2 && redgrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ red: allowed.\n",n/2); //debug
                    if(firstv2[d]>first){
                        first=firstv2[d];
                    }
                    if(lastv2[d]<last){
                        last=lastv2[d];
                    }
                }
            }
            }
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<blugrp->nsl; m++){
                if(((blugrp->singllinks[m]->p1.x==cx1 && blugrp->singllinks[m]->p1.y==cy1)&&(blugrp->singllinks[m]->p2.x==cx2 && blugrp->singllinks[m]->p2.y==cy2))||((blugrp->singllinks[m]->p2.x==cx1 && blugrp->singllinks[m]->p2.y==cy1)&&(blugrp->singllinks[m]->p1.x==cx2 && blugrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ blue: allowed.\n",n/2); //debug
                    if(firstv2[d]>first){
                        first=firstv2[d];
                    }
                    if(lastv2[d]<last){
                        last=lastv2[d];
                    }
                }
            }
            }
            for(int j=first; j<=last; j++){
                if(board[(x1)-j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    int except=0;
                    if(board[(x1)-flagn][cy]==-5){
                        bigflag=1;
                        break;
                    }
                    else if(board[(x1)-flagn][cy]==5){
                    for(int i=0; i<redgrp->nsl; i++){
                    if((redgrp->singllinks[i]->p1.x==x2 && redgrp->singllinks[i]->p1.y==y2) || (redgrp->singllinks[i]->p2.x==x2 && redgrp->singllinks[i]->p2.y==y2) || (redgrp->singllinks[i]->p1.x==x1 && redgrp->singllinks[i]->p1.y==y1) || (redgrp->singllinks[i]->p2.x==x1 && redgrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(redgrp->singllinks[i]->middle[j].x==(x1)-flagn && redgrp->singllinks[i]->middle[j].y==cy){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        printf("exception: collision allowed\n"); //debug
                    }                    
                    }
                    else{
                        bigflag=1;
                    }
                }
            }
            if(flag==0 || (flag==1 && bigflag==0)){
                peg arr[5];
                for(int j=0; j<=4; j++){
                    board[(x1)-j][cy]=5;
                    arr[j].x=(x1)-j;
                    arr[j].y=cy;
                }
                addlinktogrp(x1,y1,x2,y2,redgrp,arr);
            }
        }

        else if((x2)-(x1)==4 && (y2)-(y1)==-2){
            //horizontal right up link
            printf("case: hru\n");
            cy = (y1)-1;
            int first=0;
            int last=4;
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1+n;
                int cy1=y1;
                int cx2=x2+n;
                int cy2=y2;
            for(int m=0; m<redgrp->nsl; m++){
                if(((redgrp->singllinks[m]->p1.x==cx1 && redgrp->singllinks[m]->p1.y==cy1)&&(redgrp->singllinks[m]->p2.x==cx2 && redgrp->singllinks[m]->p2.y==cy2))||((redgrp->singllinks[m]->p2.x==cx1 && redgrp->singllinks[m]->p2.y==cy1)&&(redgrp->singllinks[m]->p1.x==cx2 && redgrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ red: allowed.\n",n/2); //debug
                    if(firstv1[d]>first){
                        first=firstv1[d];
                    }
                    if(lastv1[d]<last){
                        last=lastv1[d];
                    }
                }
            }
            }
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<blugrp->nsl; m++){
                if(((blugrp->singllinks[m]->p1.x==cx1 && blugrp->singllinks[m]->p1.y==cy1)&&(blugrp->singllinks[m]->p2.x==cx2 && blugrp->singllinks[m]->p2.y==cy2))||((blugrp->singllinks[m]->p2.x==cx1 && blugrp->singllinks[m]->p2.y==cy1)&&(blugrp->singllinks[m]->p1.x==cx2 && blugrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ blue: allowed.\n",n/2); //debug
                    if(firstv1[d]>first){
                        first=firstv1[d];
                    }
                    if(lastv1[d]<last){
                        last=lastv1[d];
                    }
                }
            }
            }
            for(int j=first; j<=last; j++){
                if(board[(x1)+j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    int except=0;
                    if(board[(x1)+flagn][cy]==-5){
                        bigflag=1;
                        break;
                    }
                    else if(board[(x1)+flagn][cy]==5){
                    for(int i=0; i<redgrp->nsl; i++){
                    if((redgrp->singllinks[i]->p1.x==x2 && redgrp->singllinks[i]->p1.y==y2) || (redgrp->singllinks[i]->p2.x==x2 && redgrp->singllinks[i]->p2.y==y2) || (redgrp->singllinks[i]->p1.x==x1 && redgrp->singllinks[i]->p1.y==y1) || (redgrp->singllinks[i]->p2.x==x1 && redgrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(redgrp->singllinks[i]->middle[j].x==(x1)+flagn && redgrp->singllinks[i]->middle[j].y==cy){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        printf("exception: collision allowed\n"); //debug
                    }                    
                    }
                    else{
                        bigflag=1;
                    }
                }
            }
            if(flag==0 || (flag==1 && bigflag==0)){
                peg arr[5];
                for(int j=0; j<=4; j++){
                    board[(x1)+j][cy]=5;
                    arr[j].x=(x1)+j;
                    arr[j].y=cy;
                }
                addlinktogrp(x1,y1,x2,y2,redgrp,arr);
            }
        }

        else if((x2)-(x1)==-4 && (y2)-(y1)==-2){
            //horizontal left up link
            printf("case: hlu\n");
            cy = (y1)-1;
            int first=0;
            int last=4;
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1+n;
                int cy1=y1;
                int cx2=x2+n;
                int cy2=y2;
            for(int m=0; m<redgrp->nsl; m++){
                if(((redgrp->singllinks[m]->p1.x==cx1 && redgrp->singllinks[m]->p1.y==cy1)&&(redgrp->singllinks[m]->p2.x==cx2 && redgrp->singllinks[m]->p2.y==cy2))||((redgrp->singllinks[m]->p2.x==cx1 && redgrp->singllinks[m]->p2.y==cy1)&&(redgrp->singllinks[m]->p1.x==cx2 && redgrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ red: allowed.\n",n/2); //debug
                    if(firstv2[d]>first){
                        first=firstv2[d];
                    }
                    if(lastv2[d]<last){
                        last=lastv2[d];
                    }
                }
            }
            }
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<blugrp->nsl; m++){
                if(((blugrp->singllinks[m]->p1.x==cx1 && blugrp->singllinks[m]->p1.y==cy1)&&(blugrp->singllinks[m]->p2.x==cx2 && blugrp->singllinks[m]->p2.y==cy2))||((blugrp->singllinks[m]->p2.x==cx1 && blugrp->singllinks[m]->p2.y==cy1)&&(blugrp->singllinks[m]->p1.x==cx2 && blugrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ blue: allowed.\n",n/2); //debug
                    if(firstv2[d]>first){
                        first=firstv2[d];
                    }
                    if(lastv2[d]<last){
                        last=lastv2[d];
                    }
                }
            }
            }
            for(int j=first; j<=last; j++){
                if(board[(x1)-j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    int except=0;
                    if(board[(x1)-flagn][cy]==-5){
                        bigflag=1;
                        break;
                    }
                    else if(board[(x1)-flagn][cy]==5){
                    for(int i=0; i<redgrp->nsl; i++){
                    if((redgrp->singllinks[i]->p1.x==x2 && redgrp->singllinks[i]->p1.y==y2) || (redgrp->singllinks[i]->p2.x==x2 && redgrp->singllinks[i]->p2.y==y2) || (redgrp->singllinks[i]->p1.x==x1 && redgrp->singllinks[i]->p1.y==y1) || (redgrp->singllinks[i]->p2.x==x1 && redgrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(redgrp->singllinks[i]->middle[j].x==(x1)-flagn && redgrp->singllinks[i]->middle[j].y==cy){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        printf("exception: collision allowed\n"); //debug
                    }                    
                    }
                    else{
                        bigflag=1;
                    }
                }
            }
            if(flag==0 || (flag==1 && bigflag==0)){
                peg arr[5];
                for(int j=0; j<=4; j++){
                    board[(x1)-j][cy]=5;
                    arr[j].x=(x1)-j;
                    arr[j].y=cy;
                }
                addlinktogrp(x1,y1,x2,y2,redgrp,arr);
            }
        }
    }

    //if both pegs are blue
    else if(board[x1][y1]==-1 && board[x2][y2]==-1){
        if((x2)-(x1)==2 && (y2)-(y1)==4){
            //vertical right down link
            printf("case: vrd\n"); //debug
            cx = (x1)+1;
            int first=0;
            int last=4;
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<redgrp->nsl; m++){
                if(((redgrp->singllinks[m]->p1.x==cx1 && redgrp->singllinks[m]->p1.y==cy1)&&(redgrp->singllinks[m]->p2.x==cx2 && redgrp->singllinks[m]->p2.y==cy2))||((redgrp->singllinks[m]->p2.x==cx1 && redgrp->singllinks[m]->p2.y==cy1)&&(redgrp->singllinks[m]->p1.x==cx2 && redgrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ red: allowed.\n",n/2); //debug
                    if(firstv1[d]>first){
                        first=firstv1[d];
                    }
                    if(lastv1[d]<last){
                        last=lastv1[d];
                    }
                }
            }
            }
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<blugrp->nsl; m++){
                if(((blugrp->singllinks[m]->p1.x==cx1 && blugrp->singllinks[m]->p1.y==cy1)&&(blugrp->singllinks[m]->p2.x==cx2 && blugrp->singllinks[m]->p2.y==cy2))||((blugrp->singllinks[m]->p2.x==cx1 && blugrp->singllinks[m]->p2.y==cy1)&&(blugrp->singllinks[m]->p1.x==cx2 && blugrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ blue: allowed.\n",n/2); //debug
                    if(firstv1[d]>first){
                        first=firstv1[d];
                    }
                    if(lastv1[d]<last){
                        last=lastv1[d];
                    }
                }
            }
            }
            for(int j=first; j<=last; j++){
                if(board[cx][(y1)+j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n"); //debug
                    int except=0;
                    if(board[cx][(y1)+flagn]==5){
                        bigflag=1;
                        break;
                    }
                    else if(board[cx][(y1)+flagn]==-5){
                    for(int i=0; i<blugrp->nsl; i++){
                    if((blugrp->singllinks[i]->p1.x==x2 && blugrp->singllinks[i]->p1.y==y2) || (blugrp->singllinks[i]->p2.x==x2 && blugrp->singllinks[i]->p2.y==y2) || (blugrp->singllinks[i]->p1.x==x1 && blugrp->singllinks[i]->p1.y==y1) || (blugrp->singllinks[i]->p2.x==x1 && blugrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(blugrp->singllinks[i]->middle[j].x==cx && blugrp->singllinks[i]->middle[j].y==(y1)+flagn){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        printf("exception: collision allowed\n"); //debug
                    }                    
                    }
                    else{
                        bigflag=1;
                    }
                }
            }
            if(flag==0 || (flag==1 && bigflag==0)){
                peg arr[5];
                for(int j=0; j<=4; j++){
                    board[cx][(y1)+j]=-5;
                    arr[j].x=cx;
                    arr[j].y=(y1)+j;
                }
                addlinktogrp(x1,y1,x2,y2,blugrp,arr);
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
                    int except=0;
                    if(board[cx][(y1)+flagn]==5){
                        bigflag=1;
                        break;
                    }
                    else if(board[cx][(y1)+flagn]==-5){
                    for(int i=0; i<blugrp->nsl; i++){
                    if((blugrp->singllinks[i]->p1.x==x2 && blugrp->singllinks[i]->p1.y==y2) || (blugrp->singllinks[i]->p2.x==x2 && blugrp->singllinks[i]->p2.y==y2) || (blugrp->singllinks[i]->p1.x==x1 && blugrp->singllinks[i]->p1.y==y1) || (blugrp->singllinks[i]->p2.x==x1 && blugrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(blugrp->singllinks[i]->middle[j].x==cx && blugrp->singllinks[i]->middle[j].y==(y1)+flagn){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        printf("exception: collision allowed\n"); //debug
                    }                    
                    }
                    else{
                        bigflag=1;
                    }
                }
            }
            if(flag==0 || (flag==1 && bigflag==0)){
                peg arr[5];
                for(int j=0; j<=4; j++){
                    board[cx][(y1)+j]=-5;
                    arr[j].x=cx;
                    arr[j].y=(y1)+j;
                }
                addlinktogrp(x1,y1,x2,y2,blugrp,arr);
            }
        }

        else if((x2)-(x1)==2 && (y2)-(y1)==-4){
            //vertical right up link
            printf("case: vru\n"); //debug
            cx = (x1)+1;
            int first=0;
            int last=4;
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<redgrp->nsl; m++){
                if(((redgrp->singllinks[m]->p1.x==cx1 && redgrp->singllinks[m]->p1.y==cy1)&&(redgrp->singllinks[m]->p2.x==cx2 && redgrp->singllinks[m]->p2.y==cy2))||((redgrp->singllinks[m]->p2.x==cx1 && redgrp->singllinks[m]->p2.y==cy1)&&(redgrp->singllinks[m]->p1.x==cx2 && redgrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ red: allowed.\n",n/2); //debug
                    if(firstv2[d]>first){
                        first=firstv2[d];
                    }
                    if(lastv2[d]<last){
                        last=lastv2[d];
                    }
                }
            }
            }
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<blugrp->nsl; m++){
                if(((blugrp->singllinks[m]->p1.x==cx1 && blugrp->singllinks[m]->p1.y==cy1)&&(blugrp->singllinks[m]->p2.x==cx2 && blugrp->singllinks[m]->p2.y==cy2))||((blugrp->singllinks[m]->p2.x==cx1 && blugrp->singllinks[m]->p2.y==cy1)&&(blugrp->singllinks[m]->p1.x==cx2 && blugrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ blue: allowed.\n",n/2); //debug
                    if(firstv2[d]>first){
                        first=firstv2[d];
                    }
                    if(lastv2[d]<last){
                        last=lastv2[d];
                    }
                }
            }
            }
            for(int j=first; j<=last; j++){
                if(board[cx][(y1)-j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    int except=0;
                    if(board[cx][(y1)-flagn]==5){
                        bigflag=1;
                        break;
                    }
                    else if(board[cx][(y1)-flagn]==-5){
                    for(int i=0; i<blugrp->nsl; i++){
                    if((blugrp->singllinks[i]->p1.x==x2 && blugrp->singllinks[i]->p1.y==y2) || (blugrp->singllinks[i]->p2.x==x2 && blugrp->singllinks[i]->p2.y==y2) || (blugrp->singllinks[i]->p1.x==x1 && blugrp->singllinks[i]->p1.y==y1) || (blugrp->singllinks[i]->p2.x==x1 && blugrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(blugrp->singllinks[i]->middle[j].x==cx && blugrp->singllinks[i]->middle[j].y==(y1)-flagn){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        printf("exception: collision allowed\n"); //debug
                    }                    
                    }
                    else{
                        bigflag=1;
                    }
                }
            }
            if(flag==0 || (flag==1 && bigflag==0)){
                peg arr[5];
                for(int j=0; j<=4; j++){
                    board[cx][(y1)-j]=-5;
                    arr[j].x=cx;
                    arr[j].y=(y1)-j;
                }
                addlinktogrp(x1,y1,x2,y2,blugrp,arr);
            }
        }

        else if((x2)-(x1)==-2 && (y2)-(y1)==-4){
            //vertical left up link
            printf("case: vlu\n"); //debug
            cx = (x1)-1;
            int first=0;
            int last=4;
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<redgrp->nsl; m++){
                if(((redgrp->singllinks[m]->p1.x==cx1 && redgrp->singllinks[m]->p1.y==cy1)&&(redgrp->singllinks[m]->p2.x==cx2 && redgrp->singllinks[m]->p2.y==cy2))||((redgrp->singllinks[m]->p2.x==cx1 && redgrp->singllinks[m]->p2.y==cy1)&&(redgrp->singllinks[m]->p1.x==cx2 && redgrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ red: allowed.\n",n/2); //debug
                    if(firstv2[d]>first){
                        first=firstv2[d];
                    }
                    if(lastv2[d]<last){
                        last=lastv2[d];
                    }
                }
            }
            }
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<blugrp->nsl; m++){
                if(((blugrp->singllinks[m]->p1.x==cx1 && blugrp->singllinks[m]->p1.y==cy1)&&(blugrp->singllinks[m]->p2.x==cx2 && blugrp->singllinks[m]->p2.y==cy2))||((blugrp->singllinks[m]->p2.x==cx1 && blugrp->singllinks[m]->p2.y==cy1)&&(blugrp->singllinks[m]->p1.x==cx2 && blugrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ blue: allowed.\n",n/2); //debug
                    if(firstv2[d]>first){
                        first=firstv2[d];
                    }
                    if(lastv2[d]<last){
                        last=lastv2[d];
                    }
                }
            }
            }
            for(int j=first; j<=last; j++){
                if(board[cx][(y1)-j]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    int except=0;
                    if(board[cx][(y1)-flagn]==5){
                        bigflag=1;
                        break;
                    }
                    else if(board[cx][(y1)-flagn]==-5){
                    for(int i=0; i<blugrp->nsl; i++){
                    if((blugrp->singllinks[i]->p1.x==x2 && blugrp->singllinks[i]->p1.y==y2) || (blugrp->singllinks[i]->p2.x==x2 && blugrp->singllinks[i]->p2.y==y2) || (blugrp->singllinks[i]->p1.x==x1 && blugrp->singllinks[i]->p1.y==y1) || (blugrp->singllinks[i]->p2.x==x1 && blugrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(blugrp->singllinks[i]->middle[j].x==cx && blugrp->singllinks[i]->middle[j].y==(y1)-flagn){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        printf("exception: collision allowed\n"); //debug
                    }                    
                    }
                    else{
                        bigflag=1;
                    }
                }
            }
            if(flag==0 || (flag==1 && bigflag==0)){
                peg arr[5];
                for(int j=0; j<=4; j++){
                    board[cx][(y1)-j]=-5;
                    arr[j].x=cx;
                    arr[j].y=(y1)-j;
                }
                addlinktogrp(x1,y1,x2,y2,blugrp,arr);
            }
        }

        else if((x2)-(x1)==4 && (y2)-(y1)==2){
            //horizontal right down link
            printf("case: hrd\n"); //debug
            cy = (y1)+1;
            int first=0;
            int last=4;
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1+n;
                int cy1=y1;
                int cx2=x2+n;
                int cy2=y2;
            for(int m=0; m<redgrp->nsl; m++){
                if(((redgrp->singllinks[m]->p1.x==cx1 && redgrp->singllinks[m]->p1.y==cy1)&&(redgrp->singllinks[m]->p2.x==cx2 && redgrp->singllinks[m]->p2.y==cy2))||((redgrp->singllinks[m]->p2.x==cx1 && redgrp->singllinks[m]->p2.y==cy1)&&(redgrp->singllinks[m]->p1.x==cx2 && redgrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ red: allowed.\n",n/2); //debug
                    if(firstv1[d]>first){
                        first=firstv1[d];
                    }
                    if(lastv1[d]<last){
                        last=lastv1[d];
                    }
                }
            }
            }
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<blugrp->nsl; m++){
                if(((blugrp->singllinks[m]->p1.x==cx1 && blugrp->singllinks[m]->p1.y==cy1)&&(blugrp->singllinks[m]->p2.x==cx2 && blugrp->singllinks[m]->p2.y==cy2))||((blugrp->singllinks[m]->p2.x==cx1 && blugrp->singllinks[m]->p2.y==cy1)&&(blugrp->singllinks[m]->p1.x==cx2 && blugrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ blue: allowed.\n",n/2); //debug
                    if(firstv1[d]>first){
                        first=firstv1[d];
                    }
                    if(lastv1[d]<last){
                        last=lastv1[d];
                    }
                }
            }
            }
            for(int j=first; j<=last; j++){
                if(board[(x1)+j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    int except=0;
                    if(board[(x1)+flagn][cy]==5){
                        bigflag=1;
                        break;
                    }
                    else if(board[(x1)+flagn][cy]==-5){
                    for(int i=0; i<blugrp->nsl; i++){
                    if((blugrp->singllinks[i]->p1.x==x2 && blugrp->singllinks[i]->p1.y==y2) || (blugrp->singllinks[i]->p2.x==x2 && blugrp->singllinks[i]->p2.y==y2) || (blugrp->singllinks[i]->p1.x==x1 && blugrp->singllinks[i]->p1.y==y1) || (blugrp->singllinks[i]->p2.x==x1 && blugrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(blugrp->singllinks[i]->middle[j].x==(x1)+flagn && blugrp->singllinks[i]->middle[j].y==cy){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        printf("exception: collision allowed\n"); //debug
                    }                    
                    }
                    else{
                        bigflag=1;
                    }
                }
            }
            if(flag==0 || (flag==1 && bigflag==0)){
                peg arr[5];
                for(int j=0; j<=4; j++){
                    board[(x1)+j][cy]=-5;
                    arr[j].x=(x1)+j;
                    arr[j].y=cy;
                }
                addlinktogrp(x1,y1,x2,y2,blugrp,arr);
            }
        }

        else if((x2)-(x1)==-4 && (y2)-(y1)==2){
            //horizontal left down link
            printf("case: hld\n"); //debug
            cy = (y1)+1;
            int first=0;
            int last=4;
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1+n;
                int cy1=y1;
                int cx2=x2+n;
                int cy2=y2;
            for(int m=0; m<redgrp->nsl; m++){
                if(((redgrp->singllinks[m]->p1.x==cx1 && redgrp->singllinks[m]->p1.y==cy1)&&(redgrp->singllinks[m]->p2.x==cx2 && redgrp->singllinks[m]->p2.y==cy2))||((redgrp->singllinks[m]->p2.x==cx1 && redgrp->singllinks[m]->p2.y==cy1)&&(redgrp->singllinks[m]->p1.x==cx2 && redgrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ red: allowed.\n",n/2); //debug
                    if(firstv2[d]>first){
                        first=firstv2[d];
                    }
                    if(lastv2[d]<last){
                        last=lastv2[d];
                    }
                }
            }
            }
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<blugrp->nsl; m++){
                if(((blugrp->singllinks[m]->p1.x==cx1 && blugrp->singllinks[m]->p1.y==cy1)&&(blugrp->singllinks[m]->p2.x==cx2 && blugrp->singllinks[m]->p2.y==cy2))||((blugrp->singllinks[m]->p2.x==cx1 && blugrp->singllinks[m]->p2.y==cy1)&&(blugrp->singllinks[m]->p1.x==cx2 && blugrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ blue: allowed.\n",n/2); //debug
                    if(firstv2[d]>first){
                        first=firstv2[d];
                    }
                    if(lastv2[d]<last){
                        last=lastv2[d];
                    }
                }
            }
            }
            for(int j=first; j<=last; j++){
                if(board[(x1)-j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    int except=0;
                    if(board[(x1)-flagn][cy]==5){
                        bigflag=1;
                        break;
                    }
                    else if(board[(x1)-flagn][cy]==-5){
                    for(int i=0; i<blugrp->nsl; i++){
                    if((blugrp->singllinks[i]->p1.x==x2 && blugrp->singllinks[i]->p1.y==y2) || (blugrp->singllinks[i]->p2.x==x2 && blugrp->singllinks[i]->p2.y==y2) || (blugrp->singllinks[i]->p1.x==x1 && blugrp->singllinks[i]->p1.y==y1) || (blugrp->singllinks[i]->p2.x==x1 && blugrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(blugrp->singllinks[i]->middle[j].x==(x1)-flagn && blugrp->singllinks[i]->middle[j].y==cy){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        printf("exception: collision allowed\n"); //debug
                    }                    
                    }
                    else{
                        bigflag=1;
                    }
                }
            }
            if(flag==0 || (flag==1 && bigflag==0)){
                peg arr[5];
                for(int j=0; j<=4; j++){
                    board[(x1)-j][cy]=-5;
                    arr[j].x=(x1)-j;
                    arr[j].y=cy;
                }
                addlinktogrp(x1,y1,x2,y2,blugrp,arr);
            }
        }

        else if((x2)-(x1)==4 && (y2)-(y1)==-2){
            //horizontal right up link
            printf("case: hru\n");
            cy = (y1)-1;
            int first=0;
            int last=4;
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1+n;
                int cy1=y1;
                int cx2=x2+n;
                int cy2=y2;
            for(int m=0; m<redgrp->nsl; m++){
                if(((redgrp->singllinks[m]->p1.x==cx1 && redgrp->singllinks[m]->p1.y==cy1)&&(redgrp->singllinks[m]->p2.x==cx2 && redgrp->singllinks[m]->p2.y==cy2))||((redgrp->singllinks[m]->p2.x==cx1 && redgrp->singllinks[m]->p2.y==cy1)&&(redgrp->singllinks[m]->p1.x==cx2 && redgrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ red: allowed.\n",n/2); //debug
                    if(firstv1[d]>first){
                        first=firstv1[d];
                    }
                    if(lastv1[d]<last){
                        last=lastv1[d];
                    }
                }
            }
            }
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<blugrp->nsl; m++){
                if(((blugrp->singllinks[m]->p1.x==cx1 && blugrp->singllinks[m]->p1.y==cy1)&&(blugrp->singllinks[m]->p2.x==cx2 && blugrp->singllinks[m]->p2.y==cy2))||((blugrp->singllinks[m]->p2.x==cx1 && blugrp->singllinks[m]->p2.y==cy1)&&(blugrp->singllinks[m]->p1.x==cx2 && blugrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ blue: allowed.\n",n/2); //debug
                    if(firstv1[d]>first){
                        first=firstv1[d];
                    }
                    if(lastv1[d]<last){
                        last=lastv1[d];
                    }
                }
            }
            }
            for(int j=0; j<=4; j++){
                if(board[(x1)+j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    int except=0;
                    if(board[(x1)+flagn][cy]==5){
                        bigflag=1;
                        break;
                    }
                    else if(board[(x1)+flagn][cy]==-5){
                    for(int i=0; i<blugrp->nsl; i++){
                    if((blugrp->singllinks[i]->p1.x==x2 && blugrp->singllinks[i]->p1.y==y2) || (blugrp->singllinks[i]->p2.x==x2 && blugrp->singllinks[i]->p2.y==y2) || (blugrp->singllinks[i]->p1.x==x1 && blugrp->singllinks[i]->p1.y==y1) || (blugrp->singllinks[i]->p2.x==x1 && blugrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(blugrp->singllinks[i]->middle[j].x==(x1)+flagn && blugrp->singllinks[i]->middle[j].y==cy){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        printf("exception: collision allowed\n"); //debug
                    }                    
                    }
                    else{
                        bigflag=1;
                    }
                }
            }
            if(flag==0 || (flag==1 && bigflag==0)){
                peg arr[5];
                for(int j=0; j<=4; j++){
                    board[(x1)+j][cy]=-5;
                    arr[j].x=(x1)+j;
                    arr[j].y=cy;
                }
                addlinktogrp(x1,y1,x2,y2,blugrp,arr);
            }
        }

        else if((x2)-(x1)==-4 && (y2)-(y1)==-2){
            //horizontal left up link
            printf("case: hlu\n");
            cy = (y1)-1;
            int first=0;
            int last=4;
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1+n;
                int cy1=y1;
                int cx2=x2+n;
                int cy2=y2;
            for(int m=0; m<redgrp->nsl; m++){
                if(((redgrp->singllinks[m]->p1.x==cx1 && redgrp->singllinks[m]->p1.y==cy1)&&(redgrp->singllinks[m]->p2.x==cx2 && redgrp->singllinks[m]->p2.y==cy2))||((redgrp->singllinks[m]->p2.x==cx1 && redgrp->singllinks[m]->p2.y==cy1)&&(redgrp->singllinks[m]->p1.x==cx2 && redgrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ red: allowed.\n",n/2); //debug
                    if(firstv2[d]>first){
                        first=firstv2[d];
                    }
                    if(lastv2[d]<last){
                        last=lastv2[d];
                    }
                }
            }
            }
            for(int d=0; d<=4; d++){
                int n=2*d-4;
                if(n==0){
                    continue;
                }
                int cx1=x1;
                int cy1=y1+n;
                int cx2=x2;
                int cy2=y2+n;
            for(int m=0; m<blugrp->nsl; m++){
                if(((blugrp->singllinks[m]->p1.x==cx1 && blugrp->singllinks[m]->p1.y==cy1)&&(blugrp->singllinks[m]->p2.x==cx2 && blugrp->singllinks[m]->p2.y==cy2))||((blugrp->singllinks[m]->p2.x==cx1 && blugrp->singllinks[m]->p2.y==cy1)&&(blugrp->singllinks[m]->p1.x==cx2 && blugrp->singllinks[m]->p1.y==cy2))){ 
                    printf("parallel exception %d found w/ blue: allowed.\n",n/2); //debug
                    if(firstv2[d]>first){
                        first=firstv2[d];
                    }
                    if(lastv2[d]<last){
                        last=lastv2[d];
                    }
                }
            }
            }
            for(int j=first; j<=last; j++){
                if(board[(x1)-j][cy]!=0){
                    flagn=j;
                    flag=1;
                    printf("collision detected\n");
                    int except=0;
                    if(board[(x1)-flagn][cy]==5){
                        bigflag=1;
                        break;
                    }
                    else if(board[(x1)-flagn][cy]==-5){
                    for(int i=0; i<blugrp->nsl; i++){
                    if((blugrp->singllinks[i]->p1.x==x2 && blugrp->singllinks[i]->p1.y==y2) || (blugrp->singllinks[i]->p2.x==x2 && blugrp->singllinks[i]->p2.y==y2) || (blugrp->singllinks[i]->p1.x==x1 && blugrp->singllinks[i]->p1.y==y1) || (blugrp->singllinks[i]->p2.x==x1 && blugrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(blugrp->singllinks[i]->middle[j].x==(x1)-flagn && blugrp->singllinks[i]->middle[j].y==cy){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        printf("exception: collision allowed\n"); //debug
                    }                    
                    }
                    else{
                        bigflag=1;
                    }
                }
            }
            if(flag==0 || (flag==1 && bigflag==0)){
                peg arr[5];
                for(int j=0; j<=4; j++){
                    board[(x1)-j][cy]=-5;
                    arr[j].x=(x1)-j;
                    arr[j].y=cy;
                }
                addlinktogrp(x1,y1,x2,y2,blugrp,arr);
            }
        }
    }

    else{
        printf("no link possible\n");
    }

    return;
}
