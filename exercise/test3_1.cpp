#include <bits/stdc++.h>
using namespace std;
const int N = 100;
vector<int> f[N];
int main()
{
    cout << "f[0]:" << &f[0];
    cout << "f[1]:" << &f[1];
    cout << "f[2]:" << &f[2];
    cout << "f[3]:" << & 'f[3] << endl; f[0].push_back(1); f[0].push_back(1); f[0].push_back(1);
    f[0].push_back(1);
    f[1].push_back(2);
    f[1].push_back(3);
    f[2].push_back(4);
    cout << "f[0]:" << &f[0];
    cout << "f[1]:" << &f[1];
    cout << "f[2]:" << &f[2];
    cout << "f[3]:" << &f[3] << endl;
    cout << f[0][0];
}