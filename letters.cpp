#include <iostream>

using namespace std;

string capitalise(string str)
{
    for(int i = 0; i < str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }

    return str;
}

int main()
{
    cout << capitalise("tania");

    return 0;
}
