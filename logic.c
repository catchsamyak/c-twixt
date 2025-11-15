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

    //checking if can comb with a comb link
    int temp=grp->ncl;
    for(int i=0; i<temp; i++){
        if(grp->comblinks[i]->p1.x==x1 && grp->comblinks[i]->p1.y==y1){
            comblink* new = malloc(sizeof(comblink));
            new->p1.x=grp->comblinks[i]->p2.x;
            new->p1.y=grp->comblinks[i]->p2.y;
            new->p2.x=x2;
            new->p2.y=y2;
            (grp->ncl)++;
            grp->comblinks = realloc(grp->comblinks, (grp->ncl)*sizeof(comblink*));
            grp->comblinks[(grp->ncl)-1]=new;
            printf("combined to a comb link\n"); //debug
        }
        else if(grp->comblinks[i]->p1.x==x2 && grp->comblinks[i]->p1.y==y2){
            comblink* new = malloc(sizeof(comblink));
            new->p1.x=grp->comblinks[i]->p2.x;
            new->p1.y=grp->comblinks[i]->p2.y;
            new->p2.x=x1;
            new->p2.y=y1;
            (grp->ncl)++;
            grp->comblinks = realloc(grp->comblinks, (grp->ncl)*sizeof(comblink*));
            grp->comblinks[(grp->ncl)-1]=new;
            printf("combined to a comb link\n"); //debug
        }
        else if(grp->comblinks[i]->p2.x==x1 && grp->comblinks[i]->p2.y==y1){
            comblink* new = malloc(sizeof(comblink));
            new->p1.x=grp->comblinks[i]->p1.x;
            new->p1.y=grp->comblinks[i]->p1.y;
            new->p2.x=x2;
            new->p2.y=y2;
            (grp->ncl)++;
            grp->comblinks = realloc(grp->comblinks, (grp->ncl)*sizeof(comblink*));
            grp->comblinks[(grp->ncl)-1]=new;
            printf("combined to a comb link\n"); //debug
        }
        else if(grp->comblinks[i]->p2.x==x2 && grp->comblinks[i]->p2.y==y2){
            comblink* new = malloc(sizeof(comblink));
            new->p1.x=grp->comblinks[i]->p1.x;
            new->p1.y=grp->comblinks[i]->p1.y;
            new->p2.x=x1;
            new->p2.y=y1;
            (grp->ncl)++;
            grp->comblinks = realloc(grp->comblinks, (grp->ncl)*sizeof(comblink*));
            grp->comblinks[(grp->ncl)-1]=new;
            printf("combined to a comb link\n"); //debug
        }  
    }

    //checking if can comb with a singl link
    for(int i=0; i<grp->nsl; i++){
        if(grp->singllinks[i]->p1.x==x1 && grp->singllinks[i]->p1.y==y1){
            comblink* new = malloc(sizeof(comblink));
            new->p1.x=grp->singllinks[i]->p2.x;
            new->p1.y=grp->singllinks[i]->p2.y;
            new->p2.x=x2;
            new->p2.y=y2;
            (grp->ncl)++;
            grp->comblinks = realloc(grp->comblinks, (grp->ncl)*sizeof(comblink*));
            grp->comblinks[(grp->ncl)-1]=new;
            printf("combined to a singl link\n"); //debug
        }
        else if(grp->singllinks[i]->p1.x==x2 && grp->singllinks[i]->p1.y==y2){
            comblink* new = malloc(sizeof(comblink));
            new->p1.x=grp->singllinks[i]->p2.x;
            new->p1.y=grp->singllinks[i]->p2.y;
            new->p2.x=x1;
            new->p2.y=y1;
            (grp->ncl)++;
            grp->comblinks = realloc(grp->comblinks, (grp->ncl)*sizeof(comblink*));
            grp->comblinks[(grp->ncl)-1]=new;
            printf("combined to a singl link\n"); //debug
        }
        else if(grp->singllinks[i]->p2.x==x1 && grp->singllinks[i]->p2.y==y1){
            comblink* new = malloc(sizeof(comblink));
            new->p1.x=grp->singllinks[i]->p1.x;
            new->p1.y=grp->singllinks[i]->p1.y;
            new->p2.x=x2;
            new->p2.y=y2;
            (grp->ncl)++;
            grp->comblinks = realloc(grp->comblinks, (grp->ncl)*sizeof(comblink*));
            grp->comblinks[(grp->ncl)-1]=new;
            printf("combined to a singl link\n"); //debug
        }
        else if(grp->singllinks[i]->p2.x==x2 && grp->singllinks[i]->p2.y==y2){
            comblink* new = malloc(sizeof(comblink));
            new->p1.x=grp->singllinks[i]->p1.x;
            new->p1.y=grp->singllinks[i]->p1.y;
            new->p2.x=x1;
            new->p2.y=y1;
            (grp->ncl)++;
            grp->comblinks = realloc(grp->comblinks, (grp->ncl)*sizeof(comblink*));
            grp->comblinks[(grp->ncl)-1]=new;
            printf("combined to a singl link\n"); //debug
        }   
    }

    // need to keep original links also, and then add combined ones, if dont add original link then can miss cases
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

void checkwin(int playr, int* end, linkgroup* redgrp, linkgroup* blugrp){

    if(playr==1){
        for(int i=0; i<redgrp->ncl; i++){
            if(abs((redgrp->comblinks[i]->p1.y)-(redgrp->comblinks[i]->p2.y))==46){
                *end = 1;
                break;
            }
        }
        // if(*end==0){printf("red did not win\n");} //debug
    }

    if(playr==-1){
        for(int i=0; i<blugrp->ncl; i++){
            if(abs((blugrp->comblinks[i]->p1.x)-(blugrp->comblinks[i]->p2.x))==46){
                *end = 1;
                break;
            }
        }
        // if(*end==0){printf("blue did not win\n");} //debug
    }

    return;
}

void freeall(linkgroup* redgrp, linkgroup* blugrp){

    //freeing redgrp
    for(int i=0; i<redgrp->nsl; i++){
        free(redgrp->singllinks[i]);
    }
    free(redgrp->singllinks);
    for(int i=0; i<redgrp->ncl; i++){
        free(redgrp->comblinks[i]);
    }
    free(redgrp->comblinks);
    free(redgrp);

    //freeing blugrp
    for(int i=0; i<blugrp->nsl; i++){
        free(blugrp->singllinks[i]);
    }
    free(blugrp->singllinks);
    for(int i=0; i<blugrp->ncl; i++){
        free(blugrp->comblinks[i]);
    }
    free(blugrp->comblinks);
    free(blugrp);

    return;
}