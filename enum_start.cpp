#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    /*
    ///defining enum
    enum Gender{Male, Female};

    ///creating gender variable
    Gender gender = Male;

    switch(gender)
    {
    case Male:
        cout << "Gender is male. ";
        break;
    case Female:
        cout << "Gender is female. ";
        break;
    default:
        cout << "Not male or female. ";
    }*/

    ///
    enum chill_months{June, July, August, September, December};

    int month;
    cout << "Enter a month: ";
    cin >> month;

    switch(month)
    {
    case 1:
        cout << "June";
        break;
    case 2:
        cout << "July";
        break;
    case 3:
        cout << "August";
        break;
    case 4:
        cout << "September";
        break;
    case 5:
        cout << "December";
        break;
    default:
        cout << "There is no break in this month ";
    }

    return 0;
}
