#include <iostream>

using namespace std;

int main()
{
    int symbol;
    char hearts = 003;
    char clubs = 005;///spatiq
    char diamonds = 004;
    char spades = 006; ///pika

    cout << "Enter number from one to four: ";
    cin >> symbol;

    switch(symbol)
    {
    case 1:
        cout << "The symbol: " << clubs << endl;
        break;
    case 2:
        cout << "The symbol: " << hearts << endl;
        break;
    case 3:
        cout << "The symbol: " << spades << endl;
        break;
    case 4:
        cout << "The symbol: " << diamonds << endl;
        break;
    default:
        cout << "Enter number from 1 to 4!";
    }

    return 0;
}
