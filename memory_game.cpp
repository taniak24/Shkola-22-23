#include <iostream>
#include <windows.h>
#include <ctime>
#include <stdlib.h>

using namespace std;

const int ROWS = 20;
const int COLS = 20 ;

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

void card_draw(int x, int y, int pic_numb, COLORS pictures[9][5][5])
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            drawChar(' ', i + x, j + y, pictures[pic_numb][i][j], pictures[pic_numb][i][j]);
        }
    }
}

int main()
{
    COLORS pictures[9][5][5] =
    {
        RED, RED, RED, RED, RED,
        RED, WHITE, RED, WHITE, RED,
        RED, RED, RED, RED, RED,
        RED, YELLOW, YELLOW, YELLOW, RED,
        RED, YELLOW, YELLOW, YELLOW, RED,

        BLUE, BLUE, BLUE, BLUE, BLUE,
        BLUE, WHITE, BLUE, WHITE, BLUE,
        BLUE, BLUE, BLUE, BLUE, BLUE,
        BLUE, YELLOW, YELLOW, YELLOW, BLUE,
        BLUE, YELLOW, YELLOW, YELLOW, BLUE,

        GREEN, GREEN, GREEN, GREEN, GREEN,
        GREEN, WHITE, GREEN, WHITE, GREEN,
        GREEN, GREEN, GREEN, GREEN, GREEN,
        GREEN, YELLOW, YELLOW, YELLOW, GREEN,
        GREEN, YELLOW, YELLOW, YELLOW, GREEN,

        BROWN, BROWN, BROWN, BROWN, BROWN,
        BROWN, YELLOW, YELLOW, YELLOW, BROWN,
        YELLOW, BLUE, YELLOW, BLUE, YELLOW,
        YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,
        YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,

        GREY, GREY, GREY, GREY, GREY,
        GREY, YELLOW, YELLOW, YELLOW, GREY,
        YELLOW, BLUE, YELLOW, BLUE, YELLOW,
        YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,
        YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,

        WHITE, GREEN, GREEN, GREEN, WHITE,
        GREEN, WHITE, GREEN, WHITE, GREEN,
        GREEN, BLUE, WHITE, BLUE, GREEN,
        GREEN, WHITE, GREEN, WHITE, GREEN,
        WHITE, GREEN, GREEN, GREEN, WHITE,

        PURPLE, CYAN, PURPLE, CYAN, PURPLE,
        CYAN, PURPLE, PURPLE, PURPLE, CYAN,
        PURPLE, PURPLE, PURPLE, PURPLE, PURPLE,
        CYAN, PURPLE, PURPLE, PURPLE, CYAN,
        PURPLE, CYAN, PURPLE, CYAN, PURPLE,

        BROWN, BROWN, BROWN, BROWN, BROWN,
        BROWN, YELLOW, YELLOW, YELLOW, YELLOW,
        YELLOW, YELLOW, BLUE, YELLOW, BLUE,
        YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,
        YELLOW, YELLOW, YELLOW, YELLOW, YELLOW,

        GREEN, GREEN, GREEN, GREEN, GREEN,
        GREY, BLUE, GREY, BLUE, GREY,
        GREEN, GREEN, GREEN, GREEN, GREEN,
        GREEN, GREEN, GREEN, GREEN, GREEN,
        GREEN, GREEN, GREEN, GREEN, GREEN,

    };

    srand(time(0));

    int check_row, check_col;
    int row1 = - 1, col1 = - 2;
    int row2 = - 3, col2 = - 4;

    int counter = 0;

    const int size_M = 4;
    int table[size_M][size_M] = {0};

    ///(size_M * size_M)/2 - if you change sizeM or type 8(for check)
    for(int i = 1; i <= (size_M * size_M)/2; i++)
    {
        ///j - print twice
        for(int j = 0; j < 2; j++)
        {
            do
            {
                check_row = rand()%size_M;
                check_col = rand()%size_M;
            }
            while(table[check_row][check_col] != 0);
            table[check_row][check_col] = i;
        }
    }

    while(counter < 8)
    {
        for(int i = 0; i < size_M; i++)
        {
            ///j - print twice
            for(int j = 0; j < size_M; j++)
            {
                if(table[i][j] == 0)
                {
                    cout << ' ' << "\t";
                }
                else if(i==row1 && j==col1 || i==row2 && j==col2)
                {
                    card_draw(1 + i*6, 1 + j*6, table[i][j], pictures);
                }
                else
                {
                    card_draw(1 + i*6, 1 + j*6, 6, pictures);
                }
            }
            cout << endl << endl;
        }

        for(int i = 0; i < 18; i++)
        {
            cout << endl;
        }
        ///FOR CARD1
        cout << "Enter first row to open: ";
        cin >> row1;
        cout << "Enter first col to open: ";
        cin >> col1;
        cout << endl;

        ///FOR CARD2
        cout << "Enter second row to open: ";
        cin >> row2;
        cout << "Enter second col to open: ";
        cin >> col2;

        if(table[row1][row2] == table[row2][col2])
        {
            table[row1][row2] = table[row2][col2] = 0;
            counter++;
        }
        system("cls");
    }



///show all pic
    /*
    int c = 10;
    for(int p = 0; p < 9; p++)
    {
        card_draw(c, 0, p, pictures);
        c+= 6;
    }*/


    return 0;
}
