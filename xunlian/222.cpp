#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (auto i = (a); i <= (b); ++i)
#define DEC(i, a, b) for (auto i = (a); i >= (b); --i)

int s_mult(int a, int b)
{
	int back = 1;
	DEC(i, 0, b - 1)
	{
		back = back * (a - i);
	}
	return back;
}

int s_mult_2(int a, int b)
{
	int back = s_mult(a, b) / s_mult(b, b);
	return back;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int ans = 1;
	vector<int> count(26, 0);
	string s;
	cin >> s;
	int n = s.size();
	FOR(i, 0, n - 1)
	{
		count[s[i] - 'a']++;
	}
	sort(count.begin(), count.end());
	while (!count[0])
	{
		count.erase(count.begin());
	}
	n = count.size();
	int flag = count[n - 1];
	if (flag == 1)
	{
		cout << s_mult(n, n);
	}
	if (s.size() - count[n - 1] < count[n - 1] - 1)
	{
		cout << 0;
		return 0;
	}
	int sum = 0, sum_1 = 0;
	FOR(i, 0, n - 1)
	{
		if (count[i] == 1)
		{
			sum++;
			sum_1++;
		}
	}
	if (s.size() - count[n - 1] == count[n - 1] - 1)
	{
		cout << s_mult(sum, sum);
	}

	else
	{
		ans = ans * s_mult_2(sum + 1, s[i]);
		sum = sum + count[i];
	}
}
ans = ans * s_mult(sum_1, sum_1);
cout << ans;
}