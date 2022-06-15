#pragma once
#include <graphics.h>
#include "Menu.h"
#include <conio.h>
int kt2;
void menu();
int ReadHighScore = 0;
int sc;
char msg[100];
void ShowHighScores();
void readHighscore();
void takeuserdetails(int Diem);
int updateHighscore();
int checkifscoredHigh(int Diem);
int ReadGameData();
void ResetGameData();
void ResetHighScore();
int UpdateGameData();
struct highsc
{
    char name[50];
    int highscore;
}h[5];
struct previous_player
{
    char name[50];
    int dodai = 0;
}pp;
void ShowHighScores()
{
    cleardevice();

    if(ReadHighScore == 0) {readHighscore();}

    settextstyle(3,0,4);
    outtextxy(700,100,"High Score");

    settextstyle(3,0,3);
    for(int i = 0; i < 5 ; i++)
    {
        sprintf(msg,"%d, %s",i+1,h[i].name);
        outtextxy(400,150+i*25,msg);
        sprintf(msg,"%1d",h[i].highscore);
        outtextxy(700,150+i*25,msg);
    }
}
void readHighscore()
{
    size_t elements_read;
    FILE *fp;
    fp=fopen("highscore.bin","rb");
    if(fp == NULL)
    {
        ResetHighScore();
    }
    else
    {
        elements_read = fread(&h,sizeof(struct highsc),5,fp);
        fclose(fp);
        if(elements_read == 0)
        {
            outtextxy(750,400,"Error");
            getch();
        }
        ReadHighScore=1;
    }
}
void takeuserdetails(int Diem)
{
    char inputbuf[50];
    int input_pos = pp.dodai ;
    char c;
    int the_end = 0;
    strcpy(inputbuf,pp.name);
    do
    {
        cleardevice();
        outtextxy(120,140,"ENTER YOUR NAME:");
        outtextxy(120,200,inputbuf);
        switch (c = getch())
        {
        case 8://backspace
            if(input_pos)
            {
                    input_pos--;
                    inputbuf[input_pos] = 0;
            }
            break;
        case 13://enter
            the_end = 1;
            break;
        case 27://esc
            inputbuf[0] = 0;
            the_end = 1;
            break;
        default://bat ki
            if(input_pos < 50 - 1 && c>=' ' && c<='~')
            {
                inputbuf[input_pos] = c;
                input_pos++;
                inputbuf[input_pos] = 0;

            }
        }
    }while(!the_end);
    strcpy(pp.name,inputbuf);
    UpdateGameData();

    h[4].highscore = Diem;
    strcpy(h[4].name,inputbuf);
    if(updateHighscore() == 0)
    {
        settextstyle(3,0,4);
        outtextxy(100,450,"Unable to update Highscore");
        outtextxy(100,530,"Press any key to return");
    }
    else
    {
        settextstyle(3,0,4);
        outtextxy(100,450,"Highscore succesfully updated");
        outtextxy(100,530,"Press any key to return");
    }
    getch();
}
int updateHighscore()
{
    char ch[50];
    int i,j = 4;
    int k;
    size_t elements_written;
    FILE *fp;

    for(i = 3; i > 0, j > 0;i--)
    {
        if(h[j].highscore > h[i].highscore)
        {
            k = h[j].highscore;
            h[j].highscore = h[i].highscore;
            h[i].highscore = k;

            strcpy(ch,h[j].name);
            strcpy(h[j].name,h[i].name);
            strcpy(h[i].name,ch);

            j=i;
        }
        else
        {
            break;
        }
    }
    fp=fopen("highscore.bin","wb");
    if(fp == NULL)
    {
        return 0;
    }
    else
    {
        elements_written = fwrite(&h,sizeof(struct highsc),5,fp);
        fclose(fp);
        if(elements_written == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}
int checkifscoredHigh(int Diem)
{
    if(ReadHighScore == 0)
            readHighscore();
    if(Diem > h[4].highscore)
            return 1;
    else
            return 0;
}
int ReadGameData()
{
    size_t elements_written;
    int n = 0;
    FILE *fp;

    fp = fopen("gamedata.bin","rb");
    if(fp == NULL)
    {
        return 0;
    }
    else
    {
        //trả về số lượng phần tử đọc thành công dưới dạng size_t
        elements_written = fread(&pp,sizeof(struct previous_player),1,fp);
        if(elements_written == 0)
        {
            return 0;
        }
        else
        {
            n++;
        }
        if(n == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
int UpdateGameData()
{
    FILE *fp;

    fp = fopen("gamedata.bin","wb");
    if(fp == NULL)
    {
        return 0;
    }
    else
    {
        fwrite(&pp,sizeof(struct previous_player),1,fp);
        return 1;
    }
}
void ResetGameData()
{
    strcpy(pp.name,"Player");
    pp.dodai = 6;
    UpdateGameData();
}
void ResetHighScore()
{
    int i;
    char name[50];
    FILE *fp;

    for(i = 0;i < 5;i++)
    {
        strcpy(h[i].name,"Player");
        h[i].highscore = 0;
    }
    fp = fopen("highscore.bin","wb");
    if(fp != NULL)
    {
        fwrite(&h,sizeof(struct highsc),5,fp);
        fclose(fp);
    }
}
