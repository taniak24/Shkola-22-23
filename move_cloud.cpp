#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    system("color 3F");

    const int N = 6;
    string cloud[N] =
    {
    "          .-~~~-.              ",
    "  .- ~ ~-(       )_ _          ",
    " /                    ~ -.     ",
    "|                          '   ",
    " \\                         .' ",
    "   ~- ._ ,. ,.,.,., ,.. -~     "
    };
    char rain[] =
    {
        "| | |",
    };

    int up_down = 0;
    int left_right = 0;
    int rain_move = 0;

    while(true)
    {
        ///MOVE UP AND DOWN CLOUD
        if(GetAsyncKeyState(VK_DOWN))
        {
            up_down++;
        }
        if(GetAsyncKeyState(VK_UP))
        {
            up_down--;
        }
        ///check
        if(up_down < 0)
        {
            up_down = 0;
        }

        for(int i = 0; i < up_down; i++)
        {
            cout << endl;
        }

        ///MOVE LEFT AND RIGHT CLOUD
        if(GetAsyncKeyState(VK_RIGHT))
        {
            left_right++;

        }
        if(GetAsyncKeyState(VK_LEFT))
        {
            left_right--;
        }
        if(left_right < 0)
        {
            left_right = 0;
        }

        ///print the cloud
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < left_right; j++)
            {
                cout << " ";
            }
            cout << cloud[i] << endl;
        }

        if(up_down > 5 && left_right > 5)
        {
            rain_move++;
            system("color 8F");
            for(int i = 0; i < rain_move; i++)
            {
                cout << endl;
            }
            for(int i = 0; i < N; i++)
            {
                cout << rain[i] << endl;
            }
        }

        Sleep(100);
        system("cls");
    }

///30 -> and 15 down
    return 0;
}
