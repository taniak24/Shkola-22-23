#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

int main()
{
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
                    cout << table[i][j] << "\t";
                }
                else
                {
                    cout << '*' << "\t";
                }
            }
            cout << endl << endl;
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

    cout << "YOU WON! \n";

    return 0;
}
