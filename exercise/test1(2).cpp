#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int num, i = 0;
    cin >> num;
    string N;
    cin >> N;
    int flag_1 = 0;
    for (i = 0; i < num; i++)
    {
        if (N[i] == '1')
            flag_1++;
    }
    if (flag_1 % 2 == 0)
    {
        cout << flag_1 / 2;
    }
    else
        cout << -1;
}