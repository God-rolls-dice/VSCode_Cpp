#include <bits/stdc++.h>
using namespace std;
int gcd_1(int a, int b)
{
    return b == 0 ? a : gcd_1(b, a % b);
}
int main()
{
}