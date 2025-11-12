#ifndef LINK_H
#define LINK_H

typedef struct peg{
    int x;
    int y;
}peg;

typedef struct link{
    peg p1;
    peg p2;
}link;

typedef struct linkgroup{
    link** links;
    int n;
}linkgroup;

linkgroup* addlinktogrp(int x1, int y1, int x2, int y2, linkgroup* grp);
linkgroup* addlinktosimpgrp(int x1, int y1, int x2, int y2, linkgroup* grp);
void makelink(int board[47][47], int x1, int y1, int x2, int y2, linkgroup* red, linkgroup* blu, linkgroup* redsimp, linkgroup* blusimp);
void unmakelink(int board[47][47], int x1, int y1, int x2, int y2, linkgroup* red, linkgroup* blu, linkgroup* redsimp, linkgroup* blusimp, int playr);

#endif