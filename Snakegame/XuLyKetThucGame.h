#pragma once
#include <graphics.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>

int DungTuong()
{
if(CR.Dot[0].x >= 1580 || CR.Dot[0].x<=20|| CR.Dot[0].y<=20 || CR.Dot[0].y>=780)
        {
            return 1;
        }
        return  0;
}
