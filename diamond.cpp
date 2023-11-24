#include <iostream>

using namespace std;

int main()
{
    int row = 5;
    int col = 5;

    //int space;

    for(int i = 0; i < row; i++)
    {
        for(int space = 0; space < row - i; space++)
        {
            cout << " ";
        }
        for(int j = 0; j < col; j++)
        {
            cout << " * ";
        }
        cout << endl;
    }

        return 0;
}

///hw - da e vytre prazen
