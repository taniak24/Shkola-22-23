#include <iostream>

using namespace std;

int main()
{
    int len = 26;
    char small[len];
    char caps[len];

    char check;

    for(int i = 65; i <= 90; i++)
    {
        caps[len] = static_cast<char> (i);

    }

    cout << caps[len] << " ";
    return 0;
}
