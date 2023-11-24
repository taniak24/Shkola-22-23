#include <iostream>

using namespace std;

void swap_vars(int& first, int& second)
{
    int temp;

    temp = first;
    first = second;
    second = temp;

    return;
}

int main()
{
    int n = 17;
    int& n_ref = n;

    cout << "n: " << n << endl;
    cout << "n_ref: " << n_ref << endl;

    n = 18;
    cout << "n_ref: " << n_ref << endl;
    cout << endl;

    ///fn and ref
    int a = 2, b = 3;
    cout << "A: " << a << " B: " << b << endl;
    swap_vars(a, b);
    cout << "After Swap: " << "a:" << a << " b: " << b << endl;
    cout << endl;


    ///pointer
    int w = 20;
    int* point;
    point = &w;

    cout << "W: " << w << endl;
    cout << "Pointer: " << point << endl;
    cout << "*point: " << *point << endl;
    cout << endl;

    ///array
    int arr[3] = {23, 44, 56};
    int*secArr = arr;

    cout << "secArr: " << secArr[1] << endl;

    return 0;
}
