#pragma once
#include <graphics.h>
#include <stdio.h>
#include "ConRan.h"

const int Maxx = 1200;
const int Maxy = 800;
void BangDiem()
{
    setfillstyle(1,6);
    bar(Maxx,0,Maxx+400,20);
    bar(Maxx,20,Maxx+20,Maxy-20);
    bar(Maxx,Maxy-20,Maxx+400,Maxy);
    bar(Maxx+380,20,Maxx+400,Maxy-20);
}
void Map1()
{
    setfillstyle(1,2);
    bar(0,0,20,Maxy);
    bar(Maxx - 20,0,Maxx,Maxy);
    bar(20,0,Maxx-20,20);
    bar(20,Maxy-20,Maxx-20,Maxy);
}
void Map2()
{
    setfillstyle(1,4);
    bar(0,0,20,Maxy);
    bar(Maxx - 20,0,Maxx,Maxy);
    bar(20,0,Maxx-20,20);
    bar(20,Maxy-20,Maxx-20,Maxy);
    bar(300,300,900,320);
    bar(300,500,900,520);
    bar(300,320,320,400);
    bar(880,420,900,500);
}

