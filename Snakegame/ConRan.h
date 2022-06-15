#pragma once
#include <graphics.h>
#include <windows.h>
#include <stdio.h>
int Diem = 0;
int speed;
enum TrangThai{LEN,XUONG,TRAI,PHAI};
TrangThai check = PHAI;
typedef struct ToaDo
{
    int x;
    int y;
}TD;
struct ConRan
{
    TD Dot[200];
    TrangThai tt;
    int ChieuDai;
}CR;
void KhoiTaoConRan()
{
    speed = 50;
    check = PHAI;
    CR.Dot[0].x = 60;
    CR.Dot[0].y = 60;
    CR.ChieuDai = 4;
}
void XuLyConRan()
{
    // vẽ rắn
     for(int i = 0; i < CR.ChieuDai; i++)
        {
            if(i == 0)
            {
                setfillstyle(1,4);
            }
            else setfillstyle(1,2);
            bar(CR.Dot[i].x,CR.Dot[i].y,CR.Dot[i].x + 20,CR.Dot[i].y + 20);
        }
    // xóa đuôi
            for(int i = CR.ChieuDai - 1; i < CR.ChieuDai;i++)
        {
            setfillstyle(1,0);
            bar(CR.Dot[i].x,CR.Dot[i].y,CR.Dot[i].x + 20,CR.Dot[i].y + 20);
        }
    // di chuyển đốt
            for(int i = CR.ChieuDai; i > 0; i--)
        {
            CR.Dot[i] = CR.Dot[i - 1];
        }
        delay(speed);
}

