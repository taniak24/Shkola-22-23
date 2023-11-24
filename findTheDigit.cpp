#include <iostream>

using namespace std;

int main()
{
    int n = 826886588;
    int counter = 0;

    while(n > 0)
    {
        cout << "The last digit: " << n % 10 << endl;
        if(n%10 == 8)
        {
            counter++;
        }
        n/=10;
    }

    cout << "The 8's in the number are: " << counter << endl;

    return 0;
}
