#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    enum COLORS {
    BLACK = 0,
    BLUE = FOREGROUND_BLUE,
    CYAN = FOREGROUND_BLUE | FOREGROUND_GREEN,
    GREEN = FOREGROUND_GREEN,
    RED = FOREGROUND_RED,
    BROWN = FOREGROUND_RED | FOREGROUND_GREEN,
    PURPLE = FOREGROUND_RED | FOREGROUND_BLUE,
    LIGHT_GREY =  FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN,

    GREY = 0 | FOREGROUND_INTENSITY,
    LIGHT_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    LIGHT_CYAN = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    LIGHT_GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    LIGHT_RED = FOREGROUND_RED | FOREGROUND_INTENSITY,
    YELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
    PINK = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
    WHITE =  FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY
};

/// declare new colour variable.GLOBAL
COLORS defaultColor = GREY;

/// drawing
HANDLE hConsoleOutput = ::GetStdHandle(STD_OUTPUT_HANDLE);
COORD screenBuf = {ROWS, COLS};
CHAR_INFO blankScreen[(ROWS)*(COLS)] = {0};


void drawChar(char ch, int y, int x, COLORS foregroundColor, COLORS backgroundColor)
{
    CHAR_INFO chInfo;
    chInfo.Char.AsciiChar = ch;
    chInfo.Attributes = foregroundColor | (backgroundColor<<4);
    COORD bufSize = {1,1};
    COORD bufCoord = {0,0};
     SMALL_RECT screen_pos = {x, y, x+1, y+1};
    ::WriteConsoleOutput(hConsoleOutput, &chInfo, bufSize, bufCoord, &screen_pos);
}

void background(COLORS foreground, COLORS background)
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            drawChar(' ', i, j, foreground, background);
            if(i == 0 || i == ROWS - 1)
            {
                drawChar(border, i, j, foreground, background);
            }
            if(j == 0 || j == COLS - 1)
            {
                drawChar(border, i, j, foreground, background);
            }
        }
    }
}

    return 0;
}
