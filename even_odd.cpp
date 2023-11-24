#include <iostream>

using namespace std;

int main()
{
    int len = 5;
    int arr[len];

    int odd = 0;
    int even = 0;

    for(int i = 0; i < len; i++)
    {
        cout << "Enter: ";
        cin >> arr[i];

        if(arr[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    cout << "The even numbers: " << even << endl;
    cout << "The odd numbers: " << odd << endl;

    return 0;
}
