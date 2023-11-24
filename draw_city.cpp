#include<iostream>
#include<windows.h>
#include<ctime>

using namespace std;

const int ROWS =35;
const int COLS =100;

///for car string rows
const int N = 4;

int gSize = 4;
int stars_num = 10;
int clouds_num = 10;
int buildings_num = 5;
int car_pos = 0;


string car[N]=
{
    "    ______     ",
    "   /|_||_|`.__ ",
    "= (   _    _ _)",
    "   `-(_)--(_)- ",
};

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

void setBgrd(COLORS color1, COLORS color2)
{
    for(int i = 0; i < screenBuf.X; i++)
    {
        for(int j = 0; j < screenBuf.Y; j++)
        {
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
    int rows = rand()%ROWS/3;
    int cols = rand()%COLS;

    drawChar(15, rows, cols, YELLOW, BLACK);
}

void move_car()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < car[i].length(); j++)
        {
            drawChar(car[i][j], (ROWS - 7) + i, j + car_pos, BLACK, LIGHT_GREY); /// black light grey
        }
    }
}

void clear_road(int posit)
{
    for(int i = 0; i <= N; i++)
    {
        drawChar(' ', (ROWS - 7) + i, posit, LIGHT_GREY, LIGHT_GREY);
    }
    drawChar('=',ROWS - gSize - 1, posit, BLACK, LIGHT_GREY);
}

void short_buildings(COLORS building1)
{
    int height;
    int space = 3;
    int wide = 8;
    int space_between_buildings;
    int total = 0;

    ///for windows
    int counter = 0;
    bool window = false;
    int window_loc;

    for(int i = 0; i < 6; i++)
    {
        wide = rand()%6 + 12;
        height = rand()%6 + 2;
        space = rand()%3 + 2;
        space_between_buildings = space + total;
        counter = 0;

        for(int i = space_between_buildings; i < space_between_buildings + wide; i++)
        {
            for(int j = ROWS - 1; j > 0 + height; j--)
            {
                if(space_between_buildings + wide < COLS - 1)
                {
                    window_loc = rand()%100;
                    if(window_loc < 15)
                    {
                        window = true;
                    }

                    if(counter < 35 && window)
                    {
                        drawChar(' ', j, i, WHITE, WHITE);
                        counter++;
                        window = false;
                    }
                    else
                    {
                        drawChar(' ', j, i, building1, building1);
                    }

                }
            }
        }
        total = space_between_buildings + wide;
    }
}

void tall_buildings(COLORS building2)
{
    int height;
    int space = 3;
    int wide = 8;
    int space_between_buildings;
    int total = 0;

    ///for windows
    int counter = 0;
    bool window = false;
    int window_loc;

    for(int i = 0; i < 6; i++)
    {
        wide = rand()%3 + 12;
        height = rand()%5 + 2;
        space = rand()%3 + 2;
        space_between_buildings = space + total;
        counter = 0;
        for(int i = space_between_buildings; i < space_between_buildings + wide; i++)
        {
            for(int j = ROWS - 1; j > 0 + height; j--)
            {
                if(space_between_buildings + wide < COLS -1)
                {
                    window_loc = rand()%100;
                    if(window_loc < 15)
                    {
                        window = true;
                    }

                    if(counter < 35 && window)
                    {
                        drawChar(' ', j, i, WHITE, WHITE);
                        counter++;
                        window = false;
                    }
                    else
                    {
                        drawChar(' ', j, i, building2, building2);
                    }
                }
            }
        }
        total = space_between_buildings + wide;
    }

}

///MAIN
int main()
{
    srand(time(0));

    bool day = true;
    setBgrd(defaultColor, defaultColor);

    ///for 10 clouds
    for(int i = 0; i < clouds_num; i++)
    {
        clouds();
    }
    tall_buildings(BROWN);
    short_buildings(YELLOW);
    grass(LIGHT_GREEN);
    road(LIGHT_GREY, BLACK);

    while(true)
    {
        move_car();
        car_pos++;
        clear_road(car_pos);

        if(car_pos >= COLS - 14)
        {
            road(LIGHT_GREY, BLACK);
            car_pos = 0;
        }

        ///click SPACE for change
        if(GetAsyncKeyState(VK_SPACE))
        {
            if(day == true)
            {
                ///call all functions for night
                setBgrd(BLACK, BLACK);
                for(int i = 0; i < stars_num; i++)
                {
                    stars();
                }
                tall_buildings(BLUE);
                short_buildings(LIGHT_BLUE);
                grass(LIGHT_GREEN);
                road(LIGHT_GREY, BLACK);

                day = false;
            }
            else
            {
                ///call all functions for day again
                setBgrd(defaultColor, defaultColor);
                for(int i = 0; i < clouds_num; i++)
                {
                    clouds();
                }
                tall_buildings(BROWN);
                short_buildings(YELLOW);
                grass(LIGHT_GREEN);
                road(LIGHT_GREY, BLACK);

                day = true;
            }
        }
        Sleep(100);
    }

    return 0;
}



