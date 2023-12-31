#include <bits/stdc++.h>
using namespace std;
#define N 998244353;
int main()
{
    string a, b;
    cin >> a >> b;
    int L1 = a.size();
    int L2 = b.size();
    int f1 = 0;
    int f2 = 0;
    long long n1 = 0, n2 = 0, sum_a = 0, sum_b = 0, add = 0;
    while (L1 - f1 >= 9)
    {
        n1 = (a[f1++] - '0') * 100000000 + (a[f1++] - '0') * 10000000 + (a[f1++] - '0') * 1000000 + (a[f1++] - '0') * 100000 + (a[f1++] - '0') * 10000 + (a[f1++] - '0') * 1000 + (a[f1++] - '0') * 100 + (a[f1++] - '0') * 10 + (a[f1++] - '0') * 1;
        sum_a = (sum_a * 1000000000 + n1) % N;
    }
    while (L1 - f1)
    {
        sum_a = sum_a * 10 + (a[f1++] - '0');
    }

    while (L2 - f2 >= 9)
    {
        n2 = (b[f2++] - '0') * 100000000 + (b[f2++] - '0') * 10000000 + (b[f2++] - '0') * 1000000 + (b[f2++] - '0') * 100000 + (b[f2++] - '0') * 10000 + (b[f2++] - '0') * 1000 + (b[f2++] - '0') * 100 + (b[f2++] - '0') * 10 + b[f2++] - '0';
        sum_b = (sum_b * 1000000000 + n2) % N;
    }
    while (L2 - f2)
    {
        sum_b = sum_b * 10 + (b[f2++] - '0');
    }
    add = (sum_a + sum_b) % N;
    cout << add;
    return 0;
}
/* 
#include <iostream>
#include <vector>
using namespace std;
const int mod = 998244353;
vector<int> add(vector<int> a, vector<int> b)
{
    vector<int> c;
    int tmp = 0;
    for (int i = 0; i < a.size() || i < b.size(); i++)          //倒着因为这里要从个位加起，不知道高位会有多少
    {
        if (i < a.size())
            tmp += a[i];
        if (i < b.size())
            tmp += b[i];            
        c.push_back(tmp % 10);
        tmp /= 10;
    }
    if (tmp)
        c.push_back(tmp);
    return c;
}
long long f(vector<int> c)
{
    long long ans = 0;
    for (int i = 0; i < c.size(); i++)
        ans = ((ans * 10) % mod + c[i]) % mod;
    return ans % mod;
}
int main()
{
    string a, b;
    vector<int> A, B, C;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');
    C = add(A, B);
    for (int i = C.size() - 1, j = 0; j < i; i--, j++)
        swap(C[i], C[j]);
    cout << f(C);
}  


 #include <iostream>
#define MOD 998244353
using namespace std;

long long GetMod(string s) {
	long long mod = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		mod = ((s[i] - '0') + mod * 10) % MOD;
	}
	return mod;
}

int main()
{
	string A, B;
	cin >> A >> B;
	cout << (GetMod(A) + GetMod(B)) % MOD;
	return 0;
}
//最优解无敌！！