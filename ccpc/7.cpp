#include <bits/stdc++.h>
using namespace std;
int main()
{
    double x1, y1, z1;
    double x2, y2, z2;
    double x3, y3, z3;
    double x4, y4, z4;
    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;
    cin >> x3 >> y3 >> z3;
    cin >> x4 >> y4 >> z4;
    double a1, a2, a3, a4;
    double value;
    double A1, A2, A3, A4;
    A1 = x2 * (y3 * z4 - y4 * z3) - x3 * (y2 * z4 - y4 * z2) + x4 * (y2 * z3 - y3 * z2);
    A2 = x1 * (y3 * z4 - y4 * z3) - x3 * (y1 * z4 - y4 * z1) + x4 * (y1 * z3 - y3 * z1);
    A3 = x1 * (y2 * z4 - y4 * z2) - x2 * (y1 * z4 - y4 * z1) + x4 * (y1 * z2 - y2 * z1);
    A4 = x1 * (y2 * z3 - y3 * z2) - x2 * (y1 * z3 - y3 * z1) + x3 * (y1 * z2 - y2 * z1);
    value = (A1 - A2 + A3 - A4) / 6;
    cout << value;
}