#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, goal = 998244353, flag = 0;
    cin >> n;
    string a1, a2;
    long long num = 0, num1 = 0, num2 = 0, last1 = 0, last2 = 0, last = 0;
    cin >> a1;
    cin >> a2;
    while (n >= 6)
    {
        num1 = (a1[flag] - '0') * 100000 + (a1[flag + 1] - '0') * 10000 + (a1[flag + 2] - '0') * 1000 + (a1[flag + 3] - '0') * 100 + (a1[flag + 4] - '0') * 10 + (a1[flag + 5] - '0');
        num2 = (a2[flag] - '0') * 100000 + (a2[flag + 1] - '0') * 10000 + (a2[flag + 2] - '0') * 1000 + (a2[flag + 3] - '0') * 100 + (a2[flag + 4] - '0') * 10 + (a2[flag + 5] - '0');
        last2 = (num2 + last2 * 1000000) % goal;
        last1 = (num1 + last1 * 1000000) % goal;
        n = n - 6;
        flag = flag + 6;
    }
    int j = n;
    num1 = 0;
    num2 = 0;
    while (n > 0)
    {
        num1 = num1 * 10 + a1[flag] - '0';
        num2 = num2 * 10 + a2[flag] - '0';
        flag++;
        n--;
    }
    last1 = (num1 + last1 * (int)pow(10, j)) % goal;
    last2 = (num2 + last2 * (int)pow(10, j)) % goal;
    last = (last1 * last2) % goal;
    cout << last;
}