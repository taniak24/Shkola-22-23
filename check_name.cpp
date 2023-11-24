#include <iostream>

using namespace std;

int main()
{
    string name;
    int len;

    cout << "Enter your name: ";
    cin >> name;
    len = name.length();

    while(len < 2 || len > 20)
    {
        cout << "Enter your name: ";
        cin >> name;
        len = name.length();
    }

    if(len >= 2 && len <= 4)
    {
        cout << "The name is short" << endl;
    }
    else if(len >= 5 && len <= 8)
    {
        cout << "The name is normal" << endl;
    }
    else if(len >= 9 && len <= 20)
    {
        cout << "The name is long" << endl;
    }



    return 0;
}
