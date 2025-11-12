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
    link** links;
    int n;
}linkgroup;

void addlinktosimpgrp(int x1, int y1, int x2, int y2, linkgroup* grp);

#endif