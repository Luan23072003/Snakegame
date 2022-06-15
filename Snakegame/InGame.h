#pragma once
#include<graphics.h>
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include "Menu.h"
#include "ThucAn.h"
#include "BangDiem.h"
int kt = 1;
char s[100];
void menu();
void InGame();
void ScreenGameOver();
int GameOver();
void XuLyThucAn();
void KhoiTaoThucAn();
int ChamTuong2();
void LoadingScreen()
{
    int i  =0;
    cleardevice();
    settextstyle(4,0,5);
    readimagefile("TITLE.JFIF",540,200,1080,400);
    delay(100);
    settextstyle(3,0,1);
    outtextxy(1600/2-100,1600/2-320,"LOADING.....");

    while(i!=200)
    {
        rectangle(1600/2 - 100,800-285,1600/2-100+i,800-265);
        rectangle(1600/2 - 100,800-285,1600/2+100,800-265);
        i++;
        delay(10);
    }
}
void ScreenGameOver()
{
            char a;
            cleardevice();
            settextstyle(3,0,4);
            sprintf(s,"Diem Cua ban La: %d",Diem);
            outtextxy(700,100,s);
            setfillstyle(SOLID_FILL,CYAN);
            if(1)
            {
                settextstyle(3,0,4);
                outtextxy(300,350,"Congrat! You made your way to the highscore!");
                outtextxy(300,400,"Press Enter to continue.");
                getch();
                takeuserdetails(Diem);
            }
            else
            {
                outtextxy(10,130,"Sorry! You coundn't make your way to the highscore!");
                outtextxy(10,150,"Press  any key to return to mainmenu.");
                getch();
            }
}

int GameOver()
{
        //cham tuong
     if(CR.Dot[0].x >= 1581-420 || CR.Dot[0].x<=19|| CR.Dot[0].y<=19 || CR.Dot[0].y>=761)
        {
            return 1;
        }
        //cham than
      for(int i = 2; i < CR.ChieuDai;i++)
        {
        if(CR.Dot[0].x == CR.Dot[i].x  && CR.Dot[0].y == CR.Dot[i].y )
            {
                return 1;
            }
        }
}
int ChamTuong2()
    {
        if(CR.Dot[0].x >= 300-2 && CR.Dot[0].x<=900-2 && CR.Dot[0].y>=300-2 && CR.Dot[0].y <=320-2)
        {
            return 1;
        }
        if(CR.Dot[0].x >= 300-2 && CR.Dot[0].x<=900-2 && CR.Dot[0].y>=500-2&& CR.Dot[0].y <=520-2)
        {
            return 1;
        }
        if(CR.Dot[0].x >= 300-2 && CR.Dot[0].x<=320-2 && CR.Dot[0].y>=320-2&& CR.Dot[0].y <=400-2)
        {
            return 1;
        }
         if(CR.Dot[0].x >= 880-2 && CR.Dot[0].x<=900-2 && CR.Dot[0].y>=420-2 && CR.Dot[0].y <=500-2)
        {
            return 1;
        }
    }
void StartGame()
{
    cleardevice();
    while(true)
    {
        if(Diem > 10)
        {
            Map2();
            BangDiem();
        }
        else
        {
        Map1();
        BangDiem();
        }
        settextstyle(1,0,2);
        sprintf(s,"YOUR SCORE: %d",Diem);
        outtextxy(1250,20,s);
        XuLyThucAn();
        DieuKhien();
            if(kbhit())
        {
            char a = getch();
            if(a != NULL) a = {NULL};
        }
        XuLyConRan();
        if(GameOver() == 1)
        {
            KhoiTaoConRan();
            KhoiTaoThucAn();
            ScreenGameOver();
            break;
        }
        if(Diem > 10)
        {
            if(ChamTuong2() == 1)
            {
                KhoiTaoConRan();
                KhoiTaoThucAn();
                ScreenGameOver();
                break;
            }
        }

    }
}
int TangToc()
{

}

