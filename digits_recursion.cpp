#include <iostream>

using namespace std;

int digit(int n)
{
    while(n > 0)
    {
        cout << "The last digit is: " << n % 10 << endl;

        n/=10;
    }
}

int main()
{
    int n;

    cout << "Enter number: ";
    cin >> n;

    return 0;
}
