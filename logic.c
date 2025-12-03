#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "link.h"
#include "logic.h"

void copyarray(peg src[5], peg dest[5]){
    for(int i=0; i<=4; i++){
        dest[i]=src[i];
    }
    return;
}

void addlinktogrp(int x1, int y1, int x2, int y2, linkgroup* grp, peg arr[5]){
    //add the link to singl links
    singllink* new = malloc(sizeof(singllink));
    new->p1.x=x1;
    new->p1.y=y1;
    new->p2.x=x2;
    new->p2.y=y2;
    copyarray(arr,new->middle);
    (grp->nsl)++;
    grp->singllinks = realloc(grp->singllinks,(grp->nsl)*sizeof(singllink*));
    grp->singllinks[(grp->nsl)-1] = new;
    printf("added link to singl links\n");
    return;
}

int checkwinpeg(int playr, peg p, int notagain[47][47], int memo[47][47], linkgroup* grp){
    if(memo[p.x][p.y]!=-1){
        return memo[p.x][p.y];
    }
    if(playr==1 && p.y==46){
        memo[p.x][p.y]=1;
        return memo[p.x][p.y];
    }
    if(playr==-1 && p.x==46){
        memo[p.x][p.y]=1;
        return memo[p.x][p.y];
    }
    notagain[p.x][p.y]=1;
    for(int i=0; i<grp->nsl; i++){
        if((p.x==grp->singllinks[i]->p1.x && p.y==grp->singllinks[i]->p1.y) && notagain[grp->singllinks[i]->p2.x][grp->singllinks[i]->p2.y]!=1){
            if(checkwinpeg(playr, grp->singllinks[i]->p2, notagain, memo, grp)){
                memo[p.x][p.y]=1;
                return memo[p.x][p.y];
            }
        }
        else if((p.x==grp->singllinks[i]->p2.x && p.y==grp->singllinks[i]->p2.y) && notagain[grp->singllinks[i]->p1.x][grp->singllinks[i]->p1.y]!=1){
            if(checkwinpeg(playr, grp->singllinks[i]->p1, notagain, memo, grp)){
                memo[p.x][p.y]=1;
                return memo[p.x][p.y];
            }
        }
    }
    memo[p.x][p.y]=0;
    return memo[p.x][p.y];
}

void resetarr(int notagain[47][47]){
    for (int i=0; i<47; i++){
        for (int j=0; j<47; j++){
            notagain[i][j] = 0;
        }
    } 
    return;
}

void checkwin(int board[47][47], int playr, int* end, linkgroup* redgrp, linkgroup* blugrp){
    int memo[47][47];
    int notagain[47][47];
    for (int i=0; i<47; i++){
        for (int j=0; j<47; j++){
            memo[i][j] = -1;
        }
    }
    if(playr==1){
        for(int x=2; x<=44; x+=2){
            resetarr(notagain);
            if(board[x][0]==playr){
                peg p={x,0};
                if(checkwinpeg(playr,p,notagain,memo,redgrp)){
                    *end=1;
                    return;
                }
            }
        }
    }
    else{
        for(int y=2; y<=44; y+=2){
            resetarr(notagain);
            if(board[0][y]==playr){
                peg p={0,y};
                if(checkwinpeg(playr,p,notagain,memo,blugrp)){
                    *end=1;
                    return;
                }
            }
        }
    }
    return;
}

void freeall(linkgroup* redgrp, linkgroup* blugrp){
    //freeing redgrp
    for(int i=0; i<redgrp->nsl; i++){
        free(redgrp->singllinks[i]);
    }
    free(redgrp->singllinks);
    free(redgrp);

    //freeing blugrp
    for(int i=0; i<blugrp->nsl; i++){
        free(blugrp->singllinks[i]);
    }
    free(blugrp->singllinks);
    free(blugrp);
    return;
}