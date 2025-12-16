#include <stdio.h>
#include <stdlib.h>
#include "link.h"
#include "logic.h"

//checks for parallel exception
void parallelcheck(linkgroup* grp, int x1, int y1, int x2, int y2, int constx, int firstv[], int lastv[], int* first, int* last){
    for(int d=0; d<=4; d++){
        int n=2*d-4;
        if(n==0){
            continue;
        }
        int cx1,cy1,cx2,cy2;
        if(constx){
            cx1=x1;
            cy1=y1+n;
            cx2=x2;
            cy2=y2+n;
        }
        else{
            cx1=x1+n;
            cy1=y1;
            cx2=x2+n;
            cy2=y2;
        }
        for(int m=0; m<grp->nsl; m++){
            if(((grp->singllinks[m]->p1.x==cx1 && grp->singllinks[m]->p1.y==cy1)&&(grp->singllinks[m]->p2.x==cx2 && grp->singllinks[m]->p2.y==cy2))||((grp->singllinks[m]->p2.x==cx1 && grp->singllinks[m]->p2.y==cy1)&&(grp->singllinks[m]->p1.x==cx2 && grp->singllinks[m]->p1.y==cy2))){ 
                // printf("parallel exception %d found: allowed.\n",n/2); //debug
                // first=; if this first is more then take it
                if(firstv[d]>*first){
                    *first=firstv[d];
                }
                // last=; if this last is less take it
                if(lastv[d]<*last){
                    *last=lastv[d];
                }
            }
        }
    }
    return;
}

void makelink(int board[47][47], int x1, int y1, int x2, int y2, linkgroup* redgrp, linkgroup* blugrp){

    if(x1<0 || x1>46 || y1<0 || y1>46 || x2<0 || x2>46 || y2<0 || y2>46){
        // printf("trying to link out of bound\n"); //debug
        return;
    }

    int current=board[x1][y1];

    if(current==0 || board[x2][y2]!=current){
        // printf("no link possible\n"); //debug
        return;
    }

    linkgroup* currentgrp=(current==1)?redgrp:blugrp;
    int currentlink=(current==1)?5:-5;
    int notcurrentlink=-currentlink;
    int flagn=0;
    int flag=0;
    int cx;
    int cy;
    int bigflag=0;
    int firstv1[5]={1,3,-1,0,0}; //v1 is for vrd/vld/hru/hrd
    int lastv1[5]={4,4,-1,1,3}; 
    int firstv2[5]={0,0,-1,3,1}; //v2 is for vru/vlu/hlu/hld
    int lastv2[5]={3,1,-1,4,4};

        if((x2)-(x1)==2 && (y2)-(y1)==4){
            //vertical right down link
            // printf("case: vrd\n"); //debug
            cx = (x1)+1;
            int first=0;
            int last=4;

            //parallelcheckred
            parallelcheck(redgrp, x1, y1, x2, y2, 1, firstv1, lastv1, &first, &last);
            //parallelcheckblue
            parallelcheck(blugrp, x1, y1, x2, y2, 1, firstv1, lastv1, &first, &last);

            for(int j=first; j<=last; j++){
                //already checked parallel cases now
                //condition that checks if it is overlapping any of the current links/pegs
                if(board[cx][(y1)+j]!=0){
                    flagn=j;
                    flag=1;
                    // printf("collision detected\n"); //debug
                    int except=0;
                    //check for exception cases
                    if(board[cx][(y1)+flagn]==notcurrentlink){
                        bigflag=1;
                        break;
                    }
                    else if(board[cx][(y1)+flagn]==currentlink){
                        for(int i=0; i<currentgrp->nsl; i++){
                            if((currentgrp->singllinks[i]->p1.x==x2 && currentgrp->singllinks[i]->p1.y==y2) || (currentgrp->singllinks[i]->p2.x==x2 && currentgrp->singllinks[i]->p2.y==y2) || (currentgrp->singllinks[i]->p1.x==x1 && currentgrp->singllinks[i]->p1.y==y1) || (currentgrp->singllinks[i]->p2.x==x1 && currentgrp->singllinks[i]->p2.y==y1)){
                                for(int h=0; h<=4; h++){
                                    if(currentgrp->singllinks[i]->middle[h].x==cx && currentgrp->singllinks[i]->middle[h].y==(y1)+flagn){
                                        except=1;
                                        break;
                                    }
                                }
                            }    
                        }
                        if(except!=1){
                            // printf("denied: first failed found\n"); //debug
                            bigflag=1;
                            break;
                        }
                        else{
                            // printf("exception: collision allowed\n"); //debug
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
                    board[cx][(y1)+j]=currentlink;
                    arr[j].x=cx;
                    arr[j].y=(y1)+j;
                }
                //add the link
                addlinktogrp(x1,y1,x2,y2,currentgrp,arr);
            }
        }

        else if((x2)-(x1)==-2 && (y2)-(y1)==4){
            //vertical left down link
            // printf("case: vld\n"); //debug
            cx = (x1)-1;
            int first=0;
            int last=4;
            
            parallelcheck(redgrp, x1, y1, x2, y2, 1, firstv1, lastv1, &first, &last);
            parallelcheck(blugrp, x1, y1, x2, y2, 1, firstv1, lastv1, &first, &last);

            for(int j=first; j<=last; j++){
                if(board[cx][(y1)+j]!=0){
                    flagn=j;
                    flag=1;
                    // printf("collision detected\n"); //debug
                    int except=0;
                    if(board[cx][(y1)+flagn]==notcurrentlink){
                        bigflag=1;
                        break;
                    }
                    else if(board[cx][(y1)+flagn]==currentlink){
                    for(int i=0; i<currentgrp->nsl; i++){
                    if((currentgrp->singllinks[i]->p1.x==x2 && currentgrp->singllinks[i]->p1.y==y2) || (currentgrp->singllinks[i]->p2.x==x2 && currentgrp->singllinks[i]->p2.y==y2) || (currentgrp->singllinks[i]->p1.x==x1 && currentgrp->singllinks[i]->p1.y==y1) || (currentgrp->singllinks[i]->p2.x==x1 && currentgrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(currentgrp->singllinks[i]->middle[j].x==cx && currentgrp->singllinks[i]->middle[j].y==(y1)+flagn){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        // printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        // printf("exception: collision allowed\n"); //debug
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
                    board[cx][(y1)+j]=currentlink;
                    arr[j].x=cx;
                    arr[j].y=(y1)+j;
                }
                addlinktogrp(x1,y1,x2,y2,currentgrp,arr);
            }
        }

        else if((x2)-(x1)==2 && (y2)-(y1)==-4){
            //vertical right up link
            // printf("case: vru\n"); //debug
            cx = (x1)+1;
            int first=0;
            int last=4;

            parallelcheck(redgrp, x1, y1, x2, y2, 1, firstv2, lastv2, &first, &last);
            parallelcheck(blugrp, x1, y1, x2, y2, 1, firstv2, lastv2, &first, &last);

            for(int j=first; j<=last; j++){
                if(board[cx][(y1)-j]!=0){
                    flagn=j;
                    flag=1;
                    // printf("collision detected\n"); //debug
                    int except=0;
                    if(board[cx][(y1)-flagn]==notcurrentlink){
                        bigflag=1;
                        break;
                    }
                    else if(board[cx][(y1)-flagn]==currentlink){
                    for(int i=0; i<currentgrp->nsl; i++){
                    if((currentgrp->singllinks[i]->p1.x==x2 && currentgrp->singllinks[i]->p1.y==y2) || (currentgrp->singllinks[i]->p2.x==x2 && currentgrp->singllinks[i]->p2.y==y2) || (currentgrp->singllinks[i]->p1.x==x1 && currentgrp->singllinks[i]->p1.y==y1) || (currentgrp->singllinks[i]->p2.x==x1 && currentgrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(currentgrp->singllinks[i]->middle[j].x==cx && currentgrp->singllinks[i]->middle[j].y==(y1)-flagn){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        // printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        // printf("exception: collision allowed\n"); //debug
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
                    board[cx][(y1)-j]=currentlink;
                    arr[j].x=cx;
                    arr[j].y=(y1)-j;
                }
                addlinktogrp(x1,y1,x2,y2,currentgrp,arr);
            }
        }

        else if((x2)-(x1)==-2 && (y2)-(y1)==-4){
            //vertical left up link
            // printf("case: vlu\n"); //debug
            cx = (x1)-1;
            int first=0;
            int last=4;

            parallelcheck(redgrp, x1, y1, x2, y2, 1, firstv2, lastv2, &first, &last);
            parallelcheck(blugrp, x1, y1, x2, y2, 1, firstv2, lastv2, &first, &last);

            for(int j=first; j<=last; j++){
                if(board[cx][(y1)-j]!=0){
                    flagn=j;
                    flag=1;
                    // printf("collision detected\n"); //debug
                    int except=0;
                    if(board[cx][(y1)-flagn]==notcurrentlink){
                        bigflag=1;
                        break;
                    }
                    else if(board[cx][(y1)-flagn]==currentlink){
                    for(int i=0; i<currentgrp->nsl; i++){
                    if((currentgrp->singllinks[i]->p1.x==x2 && currentgrp->singllinks[i]->p1.y==y2) || (currentgrp->singllinks[i]->p2.x==x2 && currentgrp->singllinks[i]->p2.y==y2) || (currentgrp->singllinks[i]->p1.x==x1 && currentgrp->singllinks[i]->p1.y==y1) || (currentgrp->singllinks[i]->p2.x==x1 && currentgrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(currentgrp->singllinks[i]->middle[j].x==cx && currentgrp->singllinks[i]->middle[j].y==(y1)-flagn){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        // printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        // printf("exception: collision allowed\n"); //debug
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
                    board[cx][(y1)-j]=currentlink;
                    arr[j].x=cx;
                    arr[j].y=(y1)-j;
                }
                addlinktogrp(x1,y1,x2,y2,currentgrp,arr);
            }
        }

        else if((x2)-(x1)==4 && (y2)-(y1)==2){
            //horizontal right down link
            // printf("case: hrd\n"); //debug
            cy = (y1)+1;
            int first=0;
            int last=4;

            parallelcheck(redgrp, x1, y1, x2, y2, 0, firstv1, lastv1, &first, &last);
            parallelcheck(blugrp, x1, y1, x2, y2, 0, firstv1, lastv1, &first, &last);

            for(int j=first; j<=last; j++){
                if(board[(x1)+j][cy]!=0){
                    flagn=j;
                    flag=1;
                    // printf("collision detected\n"); //debug
                    int except=0;
                    if(board[(x1)+flagn][cy]==notcurrentlink){
                        bigflag=1;
                        break;
                    }
                    else if(board[(x1)+flagn][cy]==currentlink){
                    for(int i=0; i<currentgrp->nsl; i++){
                    if((currentgrp->singllinks[i]->p1.x==x2 && currentgrp->singllinks[i]->p1.y==y2) || (currentgrp->singllinks[i]->p2.x==x2 && currentgrp->singllinks[i]->p2.y==y2) || (currentgrp->singllinks[i]->p1.x==x1 && currentgrp->singllinks[i]->p1.y==y1) || (currentgrp->singllinks[i]->p2.x==x1 && currentgrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(currentgrp->singllinks[i]->middle[j].x==(x1)+flagn && currentgrp->singllinks[i]->middle[j].y==cy){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        // printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        // printf("exception: collision allowed\n"); //debug
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
                    board[(x1)+j][cy]=currentlink;
                    arr[j].x=(x1)+j;
                    arr[j].y=cy;
                }
                addlinktogrp(x1,y1,x2,y2,currentgrp,arr);
            }
        }

        else if((x2)-(x1)==-4 && (y2)-(y1)==2){
            //horizontal left down link
            // printf("case: hld\n"); //debug
            cy = (y1)+1;
            int first=0;
            int last=4;

            parallelcheck(redgrp, x1, y1, x2, y2, 0, firstv2, lastv2, &first, &last);
            parallelcheck(blugrp, x1, y1, x2, y2, 0, firstv2, lastv2, &first, &last);

            for(int j=first; j<=last; j++){
                if(board[(x1)-j][cy]!=0){
                    flagn=j;
                    flag=1;
                    // printf("collision detected\n"); //debug
                    int except=0;
                    if(board[(x1)-flagn][cy]==notcurrentlink){
                        bigflag=1;
                        break;
                    }
                    else if(board[(x1)-flagn][cy]==currentlink){
                    for(int i=0; i<currentgrp->nsl; i++){
                    if((currentgrp->singllinks[i]->p1.x==x2 && currentgrp->singllinks[i]->p1.y==y2) || (currentgrp->singllinks[i]->p2.x==x2 && currentgrp->singllinks[i]->p2.y==y2) || (currentgrp->singllinks[i]->p1.x==x1 && currentgrp->singllinks[i]->p1.y==y1) || (currentgrp->singllinks[i]->p2.x==x1 && currentgrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(currentgrp->singllinks[i]->middle[j].x==(x1)-flagn && currentgrp->singllinks[i]->middle[j].y==cy){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        // printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        // printf("exception: collision allowed\n"); //debug
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
                    board[(x1)-j][cy]=currentlink;
                    arr[j].x=(x1)-j;
                    arr[j].y=cy;
                }
                addlinktogrp(x1,y1,x2,y2,currentgrp,arr);
            }
        }

        else if((x2)-(x1)==4 && (y2)-(y1)==-2){
            //horizontal right up link
            // printf("case: hru\n"); //debug
            cy = (y1)-1;
            int first=0;
            int last=4;

            parallelcheck(redgrp, x1, y1, x2, y2, 0, firstv1, lastv1, &first, &last);
            parallelcheck(blugrp, x1, y1, x2, y2, 0, firstv1, lastv1, &first, &last);

            for(int j=first; j<=last; j++){
                if(board[(x1)+j][cy]!=0){
                    flagn=j;
                    flag=1;
                    // printf("collision detected\n"); //debug
                    int except=0;
                    if(board[(x1)+flagn][cy]==notcurrentlink){
                        bigflag=1;
                        break;
                    }
                    else if(board[(x1)+flagn][cy]==currentlink){
                    for(int i=0; i<currentgrp->nsl; i++){
                    if((currentgrp->singllinks[i]->p1.x==x2 && currentgrp->singllinks[i]->p1.y==y2) || (currentgrp->singllinks[i]->p2.x==x2 && currentgrp->singllinks[i]->p2.y==y2) || (currentgrp->singllinks[i]->p1.x==x1 && currentgrp->singllinks[i]->p1.y==y1) || (currentgrp->singllinks[i]->p2.x==x1 && currentgrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(currentgrp->singllinks[i]->middle[j].x==(x1)+flagn && currentgrp->singllinks[i]->middle[j].y==cy){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        // printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        // printf("exception: collision allowed\n"); //debug
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
                    board[(x1)+j][cy]=currentlink;
                    arr[j].x=(x1)+j;
                    arr[j].y=cy;
                }
                addlinktogrp(x1,y1,x2,y2,currentgrp,arr);
            }
        }

        else if((x2)-(x1)==-4 && (y2)-(y1)==-2){
            //horizontal left up link
            // printf("case: hlu\n"); //debug
            cy = (y1)-1;
            int first=0;
            int last=4;
            
            parallelcheck(redgrp, x1, y1, x2, y2, 0, firstv2, lastv2, &first, &last);
            parallelcheck(blugrp, x1, y1, x2, y2, 0, firstv2, lastv2, &first, &last);

            for(int j=first; j<=last; j++){
                if(board[(x1)-j][cy]!=0){
                    flagn=j;
                    flag=1;
                    // printf("collision detected\n"); //debug
                    int except=0;
                    if(board[(x1)-flagn][cy]==notcurrentlink){
                        bigflag=1;
                        break;
                    }
                    else if(board[(x1)-flagn][cy]==currentlink){
                    for(int i=0; i<currentgrp->nsl; i++){
                    if((currentgrp->singllinks[i]->p1.x==x2 && currentgrp->singllinks[i]->p1.y==y2) || (currentgrp->singllinks[i]->p2.x==x2 && currentgrp->singllinks[i]->p2.y==y2) || (currentgrp->singllinks[i]->p1.x==x1 && currentgrp->singllinks[i]->p1.y==y1) || (currentgrp->singllinks[i]->p2.x==x1 && currentgrp->singllinks[i]->p2.y==y1)){
                        for(int j=0; j<=4; j++){
                            if(currentgrp->singllinks[i]->middle[j].x==(x1)-flagn && currentgrp->singllinks[i]->middle[j].y==cy){
                                except=1;
                                break;
                            }
                        }
                    }    
                    }    
                    if(except!=1){
                        // printf("denied: first failed found\n"); //debug
                        bigflag=1;
                        break;
                    }
                    else{
                        // printf("exception: collision allowed\n"); //debug
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
                    board[(x1)-j][cy]=currentlink;
                    arr[j].x=(x1)-j;
                    arr[j].y=cy;
                }
                addlinktogrp(x1,y1,x2,y2,currentgrp,arr);
            }
        }
    return;
}

void autolink(int board[47][47], int x, int y, linkgroup* redgrp, linkgroup* blugrp){
    makelink(board,x,y,x+2,y+4,redgrp,blugrp);
    makelink(board,x,y,x-2,y+4,redgrp,blugrp);
    makelink(board,x,y,x+2,y-4,redgrp,blugrp);
    makelink(board,x,y,x-2,y-4,redgrp,blugrp);
    makelink(board,x,y,x+4,y+2,redgrp,blugrp);
    makelink(board,x,y,x-4,y+2,redgrp,blugrp);
    makelink(board,x,y,x+4,y-2,redgrp,blugrp);
    makelink(board,x,y,x-4,y-2,redgrp,blugrp);
    return;
}
