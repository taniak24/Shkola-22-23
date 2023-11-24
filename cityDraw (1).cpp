
#include<iostream>
#include<windows.h>
#include<ctime>

using namespace std;

const int ROWS =35;
const int COLS =100;

int gSize = 4;

enum COLORS
{
    BLACK = 0,
    BLUE = FOREGROUND_BLUE,
    CYAN = FOREGROUND_BLUE | FOREGROUND_GREEN,
    GREEN = FOREGROUND_GREEN,
    RED = FOREGROUND_RED,
    BROWN = FOREGROUND_RED | FOREGROUND_GREEN,
    B_BROWN = BACKGROUND_RED | BACKGROUND_GREEN,
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
COLORS defaultColor = LIGHT_BLUE;

/// drawing
HANDLE hConsoleOutput = ::GetStdHandle(STD_OUTPUT_HANDLE);
COORD screenBuf = {ROWS, COLS};
CHAR_INFO blankScreen[(ROWS)*(COLS)] = {0};


void drawChar(char ch, int y, int x, COLORS foregroundColor, COLORS backgroundColor){
    CHAR_INFO chInfo;
    chInfo.Char.AsciiChar = ch;
    chInfo.Attributes = foregroundColor | (backgroundColor<<4);
    COORD bufSize = {1,1};
    COORD bufCoord = {0,0};
     SMALL_RECT screen_pos = {x, y, x+1, y+1};
    ::WriteConsoleOutput(hConsoleOutput, &chInfo, bufSize, bufCoord, &screen_pos);
}

void setBgrd(COLORS color1, COLORS color2)
{
    for(int i = 0; i < screenBuf.X; i++){
        for(int j = 0; j < screenBuf.Y; j++){
            drawChar('$', i, j, color1, color2);
        }
    }
}

void grass(COLORS color)
{
    for(int i = ROWS; i > ROWS-gSize; i--)
    {
        for(int k=0; k<COLS; k++)
        {
            drawChar(' ',i,k,color,color);

        }
    }
}

void road(COLORS roadColor, COLORS line)
{
    for(int i = ROWS - gSize + 1; i > ROWS - gSize*2; i--)
    {
        for(int k = 0; k < COLS; k++)
        {
            drawChar(' ', i, k, roadColor, roadColor);
            drawChar('=',ROWS - gSize - 1, k, line, roadColor);
        }
    }
}

void clouds()
{
    int length = rand()%COLS/20 + 1;
    int rows = rand()%ROWS/3;
    int cols = rand()%COLS;

    if(cols + length > COLS - 1)
    {
        cols = COLS - length;
    }

    for(int i = 0; i < length; i++)
    {
        drawChar(' ', rows, cols + i, WHITE, WHITE);
    }

}

void stars()
{
    int position = rand()%COLS;
    int rows = rand()%ROWS/3;
    int cols = rand()%COLS;

    if(cols + position > COLS - 1)
    {
        cols = COLS - position;
    }

    for(int i = 0; i < position; i++)
    {
        drawChar('*', rows, cols, YELLOW, BLACK);
    }
}

void move_car()
{

}

int main()
{
    srand(time(0));

    bool day = true;
    setBgrd(defaultColor, defaultColor);
    grass(GREEN);
    road(LIGHT_GREY, BLACK);

    ///for 10 clouds
    for(int i = 0; i < 10; i++)
    {
        clouds();
    }


    while(true){
        if(GetAsyncKeyState(VK_SPACE))
        {
            if(day == true)
            {
                ///call all functions for night
                setBgrd(BLACK, BLACK);
                grass(GREEN);
                for(int i = 0; i <10; i++)
                {
                    stars();
                }
                road(LIGHT_GREY, BLACK);
                day = false;
            }
            else
            {
                ///call all functions for day again
                setBgrd(defaultColor, defaultColor);
                grass(GREEN);
                for(int i = 0; i < 10; i++)
                {
                    clouds();
                }
                road(LIGHT_GREY, BLACK);
                day = true;
            }
        }
    }

    return 0;
}
