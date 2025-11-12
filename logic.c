#include <stdio.h>
#include <stdlib.h>
#include "link.h"
#include "logic.h"

void addlinktosimpgrp(int x1, int y1, int x2, int y2, linkgroup* simpgrp){
    //to be done
    //add the link and simplify the link grp
    //when someone puts at the end then check if there is full length connection you can group from red/blue links think of combining pairs logic
    //later as part of the logic, we will check if there is a link in this grp such that the x1-x2=23*2
    // linkgroup* addlinktogrp(int x1, int y1, int x2, int y2, linkgroup* grp){
    // link* new = malloc(sizeof(link));
    // new->p1.x=x1;
    // new->p1.y=y1;
    // new->p2.x=x2;
    // new->p2.y=y2;
    // (grp->n)++;
    // grp->links = realloc(grp->links,(grp->n)*sizeof(link*));
    // grp->links[(grp->n-1)] = new;
    // return grp->links;
    return;
}

int checkwin(int playr, linkgroup* redsimp, linkgroup* blusimp){
    //function that checks if there is a link st the diff bw x or y is max
    return 0;
}