#ifndef LOGIC_H
#define LOGIC_H

typedef struct peg{
    int x;
    int y;
}peg;

typedef struct link{
    peg p1;
    peg p2;
}link;

typedef struct linkgroup{
    link** singllinks;
    int nsl;
    link** comblinks;
    int ncl;
}linkgroup;

void addlinktogrp(int x1, int y1, int x2, int y2, linkgroup* grp);
void checkwin(int playr, int* end, linkgroup* redgrp, linkgroup* blugrp);
void freeall(linkgroup* redgrp, linkgroup* blugrp);

#endif