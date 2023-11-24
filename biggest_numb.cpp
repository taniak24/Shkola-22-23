#include <iostream>

using namespace std;

int numbers()
{
    int biggestN;

    for(int i = 0; i < 3; i++)
    {
        cout << "Enter numbers: ";
        cin >> n[i];
        if(n[i] > n[i-1])
        {
            biggestN = n[i];
        }
    }
    return 0;
}

int main()
{
    numbers();
    int n[3];
    for(int i = 0; i<3; i++)
    {
       cout<<"n["<<i<<"] = ";
       cin>>n[i];
    }
    cout<<"largest num: "<<largest(n);

    return 0;
}
