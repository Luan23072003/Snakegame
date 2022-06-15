#pragma once
#include <graphics.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "ConRan.h"
int rx[2],ry[2];
void KhoiTaoThucAn()
{
    rx[0] = 100;
    ry[0] = 100;
    rx[1] = 200;
    ry[1] = 200;

}
void XuLyThucAn()
{
    //Tạo thức ăn
    for(int i = 0;i < 2; i++)
    {
    // ăn thức ăn
    if(CR.Dot[0].x==rx[i] && CR.Dot[0].y==ry[i] )
    {
    CR.ChieuDai += 1;
    Diem=Diem+1;
    // vẽ thức ăn
    do{
    rx[i] = (rand()%(1581-400) + 20);
    ry[i] = (rand()%781 + 20);
    }while(getpixel(rx[i],ry[i])!=0);
    rx[i]=rx[i]/20;
    rx[i]=rx[i]*20;
    ry[i]=ry[i]/20;
    ry[i]=ry[i]*20;
     }
     if(i == 0)
     {
        readimagefile("apple3.jpg",rx[i],ry[i],rx[i]+20,ry[i]+20);
     }
     else if(i == 1)
     {
        readimagefile("apple2.jfif",rx[i],ry[i],rx[i]+20,ry[i]+20);
     }
    }
}


