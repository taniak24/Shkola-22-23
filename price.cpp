#include <iostream>

using namespace std;

int main()
{
    float price;
    float price_VAT;
    int kg, priceKg;

    cout << "The price for kg: ";
    cin >> priceKg;

    cout << "How much kg: ";
    cin >> kg;

    price = kg*priceKg;
    price_VAT = price / 5;

    cout << "The price with VAT: " << price + price_VAT;


    return 0;
}
