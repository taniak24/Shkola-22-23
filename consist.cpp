#include <iostream>
#include <vector>

using namespace std;

bool contain(int a, int b)
{
    vector<int> check;

    while(a > 0)
    {
        cout << "A: " << a % 10 << endl;
        check.push_back(a%10);

        //cout << " B: " << b % 10 << endl;

        a/=10;
    }
    while(b > 0)
    {
        cout << "B: " << b % 10 << endl;

        for(int i = 0; i < check.size(); i++)
        {
            cout << "The elements of the vector: " << check[i] << endl;
            if(b%10 == check[i])
            {
                return true;
            }
        }
        b/=10;
    }

    return false;

}

int main()
{
    int a;
    int b;
    cout << "Enter A: ";
    cin >> a;

    cout << "Enter B: ";
    cin >> b;

    if(contain(a, b))
    {
        cout << " Contains!" << endl;
    }
    else
    {
        cout << " No contain" << endl;
    }

    return 0;
}
