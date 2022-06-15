#pragma once
#include <graphics.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include "InGame.h"

void menu(int &x, int &y);
void clickmouse(int &x, int &y,int &x2, int &y2,int &thoat, int &thoat1);
void clickmouse1(int &x2, int &y2, int &thoat1);
void menuspeed(int &x2, int &y2, int &thoat1);
void menu(int &x, int &y)
{
	readimagefile("TITLE.JFIF",540,80,1080,180);
	readimagefile("LOGO.JPG",1100,100,1500,500);
	settextstyle(4,0,5);
	setcolor(14);
	if(ismouseclick(WM_MOUSEMOVE))
	{
		getmouseclick(WM_MOUSEMOVE, x, y); //Lay toa do vi tri con tro

	if((y>=230 && y<=260+20) && (x>=255+440 && x<=450+440))
	{
    settextstyle(1,0,3);	setcolor(14);
	outtextxy(255+440,230,"    GAME MOI");
    settextstyle(1,0,2);	setcolor(15);
	outtextxy(290+440,260+20,"  DIEM          ");
	outtextxy(305+440,290+40," TUY CHON              ");
	outtextxy(290+440,320+60," HUONG DAN          ");
	outtextxy(310+440,350+80," THOAT           ");
	}
	else if((y>=260+20 && y<=290+40) && (x>=255+440 && x<=450+440))
	{
    settextstyle(1,0,2);	setcolor(15);
	outtextxy(255+440,230,"    GAME MOI               ");
    settextstyle(1,0,3);	setcolor(14);
	outtextxy(290+440,260+20,"  DIEM");
    settextstyle(1,0,2);	setcolor(15);
	outtextxy(305+440,290+40," TUY CHON                ");
	outtextxy(290+440,320+60," HUONG DAN              ");
	outtextxy(310+440,350+80," THOAT              ");
	}
    else if((y>=290+40 && y<=320+60) && (x>=255+440 && x<=450+440))
	{
    settextstyle(1,0,2);	setcolor(15);
	outtextxy(255+440,230,"    GAME MOI              ");
	outtextxy(290+440,260+20,"  DIEM             ");
    settextstyle(1,0,3);	setcolor(14);
	outtextxy(305+440,290+40,"TUY CHON");
    settextstyle(1,0,2);	setcolor(15);
	outtextxy(290+440,320+60," HUONG DAN              ");
	outtextxy(310+440,350+80," THOAT            ");
	}
	else if((y>=320+60 && y<=350+80) && (x>=255+440 && x<=450+440))
	{
    settextstyle(1,0,2);	setcolor(15);
	outtextxy(255+440,230,"    GAME MOI                ");
	outtextxy(290+440,260+20,"  DIEM             ");
	outtextxy(305+440,290+40," TUY CHON           ");
    settextstyle(1,0,3);	setcolor(14);
	outtextxy(290+440,320+60,"HUONG DAN");
    settextstyle(1,0,2);	setcolor(15);
	outtextxy(310+440,350+80," THOAT                ");
	}
	else if((y>=350+80 && y<=380+100) && (x>=255+440 && x<=450+440))
	{
    settextstyle(1,0,2);	setcolor(15);
	outtextxy(255+440,230,"    GAME MOI                ");
	outtextxy(290+440,260+20,"  DIEM               ");
	outtextxy(305+440,290+40," TUY CHON             ");
	outtextxy(290+440,320+60," HUONG DAN              ");
    settextstyle(1,0,3);	setcolor(14);
	outtextxy(310+440,350+80,"THOAT");
	}
	else
	{
	 settextstyle(1,0,2);	 setcolor(15);
 	outtextxy(255+440,230,"    GAME MOI           ");
	outtextxy(290+440,260+20,"  DIEM               ");
	outtextxy(305+440,290+40," TUY CHON                  ");
	outtextxy(290+440,320+60," HUONG DAN                   ");
	outtextxy(310+440,350+80," THOAT                         ");
	}
	}
}
void clickmouse(int &x,int &y, int &thoat, int &thoat1, int &x2, int &y2)
{
	if(ismouseclick(WM_LBUTTONDBLCLK) && (y>230 && y<380) && (x>255+440 && x<450+440))
	{
	    int x1, y1;
		cleardevice();
		getmouseclick(WM_LBUTTONDBLCLK, x1, y1);  //Lay toa do chuot click
		if((y1>=230 && y1<=260+20) && (x1>=255+440 && x1<=450+440))
		{
			StartGame();
			Diem = 0;
		}
		if((y1>=260+20 && y1<=290+40) && (x1>=255+440 && x1<=450+440))
		{
            ShowHighScores();
            getch();
		}
		if((y1>=290+40 && y1<=320+60) && (x1>=255+440 && x1<=450+440))
		{
		    thoat1 = 0;
            do{
                menuspeed(x2,y2,thoat1);
                clickmouse1(x2,y2,thoat1);
                delay(10);
            }while(thoat1 !=1);
		}
		if((y1>=320+60 && y1<=350+80) && (x1>=255+440 && x1<=450+440))
		{
		    ShowHighScores();
		    getch();
		}
		if((y1>=350+80 && y1<=380+100) && (x1>=255+440 && x1<=450+440))
		{
			thoat = 1;
		}
	 cleardevice();
	 menu(x,y);
   }
}
void menuspeed(int &x2, int &y2, int &thoat1)
{
    settextstyle(4,0,5);	setcolor(14);
	outtextxy(560,120,"CHON CAP DO");
    if(ismouseclick(WM_MOUSEMOVE))
	{
		getmouseclick(WM_MOUSEMOVE, x2, y2); //Lay toa do vi tri con tro

	if((y2>=230 && y2<=260+20) && (x2>=255+440 && x2<=450+440))
	{
    settextstyle(1,0,3);	setcolor(14);
	outtextxy(255+440,230,"     DE          ");
    settextstyle(1,0,2);	setcolor(15);
	outtextxy(290+400,260+20,"TRUNG BINH         ");
	outtextxy(305+400,290+40,"   KHO              ");
	outtextxy(290+440,320+60,"EXIT                   ");
	}
	else if((y2>=260+20 && y2<=290+40) && (x2>=255+440 && x2<=450+440))
	{
    settextstyle(1,0,2);	setcolor(15);
	outtextxy(255+440,230,"     DE                 ");
    settextstyle(1,0,3);	setcolor(14);
	outtextxy(290+400,260+20,"TRUNG BINH           ");
    settextstyle(1,0,2);	setcolor(15);
	outtextxy(305+400,290+40,"   KHO              ");
	outtextxy(290+440,320+60,"EXIT              ");
	}
    else if((y2>=290+40 && y2<=320+60) && (x2>=255+440 && x2<=450+440))
	{
    settextstyle(1,0,2);	setcolor(15);
	outtextxy(255+440,230,"     DE                 ");
	outtextxy(290+400,260+20,"TRUNG BINH             ");
    settextstyle(1,0,3);	setcolor(14);
	outtextxy(305+400,290+40,"   KHO             ");
    settextstyle(1,0,2);	setcolor(15);
	outtextxy(290+440,320+60,"EXIT            ");
	}
    else if((y2>=320+60 && y2<=350+80) && (x2>=255+440 && x2<=450+440))
	{
    settextstyle(1,0,2);	setcolor(15);
	outtextxy(255+440,230,"     DE                 ");
	outtextxy(290+400,260+20,"TRUNG BINH             ");
	outtextxy(305+400,290+40,"   KHO                      ");
    settextstyle(1,0,3);	setcolor(14);
	outtextxy(290+440,320+60,"EXIT            ");
	}
	else
	{
	 settextstyle(1,0,2);	 setcolor(15);
 	outtextxy(255+440,230,"     DE                      ");
	outtextxy(290+400,260+20,"TRUNG BINH             ");
	outtextxy(305+400,290+40,"   KHO                 ");
	outtextxy(290+440,320+60,"EXIT                   ");
	}
	}
}
void clickmouse1(int &x2, int &y2, int &thoat1)
{
	if(ismouseclick(WM_LBUTTONDBLCLK) && (y2>230 && y2<380) && (x2>255+440 && x2<450+440))
	{
		int x3, y3;
		cleardevice();

		getmouseclick((WM_LBUTTONDBLCLK), x3, y3);  //Lay toa do chuot click
		if((y3>=230 && y3<=260+20) && (x3>=255+440 && x3<=450+440))
		{
		    cleardevice();
            speed = 100;
            settextstyle(3,0,4);
            outtextxy(400,100,"Ban dang chon cap do: (DE)");
            outtextxy(400,250,"Nhan phim bat ki de thoat!");
            getch();
		}
		if((y3>=260+20 && y3<=290+40) && (x3>=255+400 && x3<=450+440))
		{
		    cleardevice();
		    speed = 50;
		    settextstyle(3,0,4);
		    outtextxy(400,100,"Ban dang chon cap do: (TRUNG BINH)");
		    outtextxy(400,250,"Nhan phim bat ki de thoat!");
		    getch();
		}
		if((y3>=290+40 && y3<=320+60) && (x3>=255+400 && x3<=450+440))
		{
		    cleardevice();
            speed = 10;
            settextstyle(3,0,4);
            outtextxy(400,100,"Ban dang chon cap do: (KHO)");
            outtextxy(400,250,"Nhan phim bat ki de thoat!");
            getch();
		}
		if((y3>=320+60 && y3<=350+80) && (x3>=255+440 && x3<=450+440))
		{
			thoat1 = 1;
		}
	 cleardevice();
	 menuspeed(x2,y2,thoat1);
   }
}
