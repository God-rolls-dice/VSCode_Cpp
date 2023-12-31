#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
typedef struct POINT{
    ll p, x, y;
}point;
vector<point> p(N);
int main()
{   
    ll n, m, x, y;
    cin >> n >> m;
    ll a, b;
    while (m--)
    {
        cin >> a >> b >> x >> y;
        p[a] = {b, x, y};
        cout << p[a].p << p[a].x << p[a].y;
    }
}