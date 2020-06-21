#ifndef ALPHABET_HPP_INCLUDED
#define ALPHABET_HPP_INCLUDED
#include<stdio.h>
#include<windows.h>
#define ALL 1
#define _BLUE 9
#define _GREEN 10
#define _LIGHTBLUE 11
#define _RED 12
#define _MAGENTA 13
#define _YELLOW 14
#define _WHITE 15

char Emapfil_[5][6]={"XXXXX",
                     "X    ",
                     "XXX  ",
                     "X    ",
                     "XXXXX"},
     Lmapfil_[5][6]={"X    ",
                     "X    ",
                     "X    ",
                     "X    ",
                     "XXXXX"},
     Mmapfil_[5][6]={"X   X",
                     "XX XX",
                     "X X X",
                     "X   X",
                     "X   X"},
     Omapfil_[5][6]={" XXX ",
                     "X   X",
                     "X   X",
                     "X   X",
                     " XXX "},
     Tmapfil_[5][6]={"XXXXX",
                     "  X ",
                     "  X  ",
                     "  X  ",
                     "  X  "},
    Smapfil_[5][6]={" XXX ",
                     "X    ",
                     " XXX ",
                     "    X",
                     " XXX "};


CHAR_INFO ecinf[25],lcinf[25],mcinf[25],ocinf[25],scinf[25],tcinf[25];

void fillchar(int Char,int charvalue,int _color)
{
    int i,j;
    switch(Char)
    {
        case 101:
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(Emapfil_[i][j]=='X')
                {
                    ecinf[j+5*i].Char.AsciiChar=charvalue;
                    ecinf[j+5*i].Attributes=_color;
                }
                if(Emapfil_[i][j]==' ')
                {
                    ecinf[j+5*i].Char.AsciiChar=' ';
                    ecinf[j+5*i].Attributes=_color;
                }
            }
        }
        break;

        case 108:
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(Lmapfil_[i][j]=='X')
                {
                    lcinf[j+5*i].Char.AsciiChar=charvalue;
                    lcinf[j+5*i].Attributes=_color;
                }
                if(Lmapfil_[i][j]==' ')
                {
                    lcinf[j+5*i].Char.AsciiChar=' ';
                    lcinf[j+5*i].Attributes=_color;
                }
            }
        }
        break;
        case 109:
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(Mmapfil_[i][j]=='X')
                {
                    mcinf[j+5*i].Char.AsciiChar=charvalue;
                    mcinf[j+5*i].Attributes=_color;
                }
                if(Mmapfil_[i][j]==' ')
                {
                    mcinf[j+5*i].Char.AsciiChar=' ';
                    mcinf[j+5*i].Attributes=_color;
                }
            }
        }
        break;
        case 111:
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(Omapfil_[i][j]=='X')
                {
                    ocinf[j+5*i].Char.AsciiChar=charvalue;
                    ocinf[j+5*i].Attributes=_color;
                }
                if(Omapfil_[i][j]==' ')
                {
                    ocinf[j+5*i].Char.AsciiChar=' ';
                    ocinf[j+5*i].Attributes=_color;
                }
            }
        }
        break;
        case 115:
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(Smapfil_[i][j]=='X')
                {
                    scinf[j+5*i].Char.AsciiChar=charvalue;
                    scinf[j+5*i].Attributes=_color;
                }
                if(Smapfil_[i][j]==' ')
                {
                    scinf[j+5*i].Char.AsciiChar=' ';
                    scinf[j+5*i].Attributes=_color;
                }
            }
        }
        break;
        case 116:
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(Tmapfil_[i][j]=='X')
                {
                    tcinf[j+5*i].Char.AsciiChar=charvalue;
                    tcinf[j+5*i].Attributes=_color;
                }
                if(Tmapfil_[i][j]==' ')
                {
                    tcinf[j+5*i].Char.AsciiChar=' ';
                    tcinf[j+5*i].Attributes=_color;
                }
            }
        }
        break;
        case 1:
            for(i=0;i<26;i++)
                fillchar(i+97,charvalue,_color);
            for(i=0;i<10;i++)
                fillchar(i+48,charvalue,_color);
            break;

    }
}
void printchar(int Char,int design,int color,int x,int y)
{
    SMALL_RECT rect;
    COORD sz={5,5},zerozero={0,0};
    rect.Left=x;
    rect.Top=y;
    rect.Right=x+5;
    rect.Bottom=y+5;
    fillchar(Char,design,color);
    switch(Char)
    {

    case 'e':
        WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE),ecinf,sz,zerozero,&rect);
        break;
    case 'l':
        WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE),lcinf,sz,zerozero,&rect);
        break;
    case 'm':
        WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE),mcinf,sz,zerozero,&rect);
        break;
    case 'o':
        WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE),ocinf,sz,zerozero,&rect);
        break;
    case 's':
        WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE),scinf,sz,zerozero,&rect);
        break;
    case 't':
        WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE),tcinf,sz,zerozero,&rect);
        break;

    }
}
void printstr(int x,int y,char *str,int design,int color)
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]!=' ')
        {
            if(x+6>79)
            {
                x=2;
                y+=6;
            }
            printchar(str[i],design,color,x,y);
            x+=6;
        }
        else
            x+=3;
    }
}
#endif // ALPHABET_HPP_INCLUDED
