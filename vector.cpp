#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> numbers;

    for(int i = 0; i < 5; i++)
    {
        numbers.push_back(i);
    }

    for(auto i=numbers.begin(); i!=numbers.end(); i++)
    {
        cout << *i << " ";
    }

    numbers.push_back(5);

    for(auto i=numbers.begin(); i!=numbers.end(); i++)
    {
        cout << *i << " ";
    }

    return 0;
}
