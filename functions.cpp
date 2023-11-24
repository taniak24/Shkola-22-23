#include <iostream>

using namespace std;

void name()
{
    cout << "Tania" << endl;
}

string email(string name, string domain)
{
    string email_str = name + domain;

    return email_str;
}

int main()
{
    name();
    cout << email("tania", "@ant.bg");

    return 0;
}
