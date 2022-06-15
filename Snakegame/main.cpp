#include<graphics.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
#include "Map.h"
#include "ConRan.h"
#include "DieuKhien.h"
#include "ThucAn.h"
#include "Menu.h"
#include "BangDiem.h"
int main(int argc, char *argv[])
{
    int x = 0,y = 0,x1 =0 ,y1 = 0,thoat = 0;
    int x2 =0, y2 = 0,x3 = 0, y3 =0,thoat1 = 0;
    initwindow(1600,800,"Con Ran",0,0);
    KhoiTaoConRan();
    KhoiTaoThucAn();
    if(ReadGameData() == 0)
    {
        ResetGameData();
    }else


    LoadingScreen();
    cleardevice();
    do{
	menu(x,y);
	clickmouse(x,y,thoat,thoat1,x2,y2);
	delay(10);
    }while(thoat !=1);

    closegraph();
    return 0;
}
