#ifndef LOGIC_H
#define LOGIC_H

typedef struct peg{
    int x;
    int y;
}peg;

typedef struct singllink{
    peg p1;
    peg p2;
    peg middle[5];
}singllink;

typedef struct linkgroup{
    singllink** singllinks;
    int nsl;
}linkgroup;

void addlinktogrp(int x1, int y1, int x2, int y2, linkgroup* grp, peg arr[5]);
void checkwin(int board[47][47], int playr, int* end, linkgroup* redgrp, linkgroup* blugrp);
void freeall(linkgroup* redgrp, linkgroup* blugrp);

#endif