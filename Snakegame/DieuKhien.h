#pragma once
#include <graphics.h>
#include <windows.h>


void DieuKhien()
{
    if(GetAsyncKeyState(VK_RIGHT)){check = PHAI;}
    else if(GetAsyncKeyState(VK_LEFT)){check = TRAI;}
    else if(GetAsyncKeyState(VK_UP)){check = LEN;}
    else if(GetAsyncKeyState(VK_DOWN)){check = XUONG;}
        switch(check)
        {
            case LEN:
                CR.Dot[0].y -= 20;
                break;
            case XUONG:
                CR.Dot[0].y += 20;
                break;
            case TRAI:
                CR.Dot[0].x -= 20;
                break;
            case PHAI:
                CR.Dot[0].x +=20;
                break;
        }

}

