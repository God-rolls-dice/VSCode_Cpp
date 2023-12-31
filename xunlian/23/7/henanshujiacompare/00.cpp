#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (auto i = (a); i <= (b); ++i)
#define DEC(i, a, b) for (auto i = (a); i >= (b); --i)
static bool cmp(pair<string, int> &a, pair<string, int> &b)
{
	return a.second > b.second;
}
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n, k;
	cin >> n >> k;
	ll a[n + 5], sum_po[n + 5] = {0};
	vector<pair<ll, ll>> nge;
	FOR(i, 1, n)
	{
		cin >> a[i];
		if (a[i] >= 0)
		{
			sum_po[i] = sum_po[i - 1] + a[i];
		}
		else
		{
			sum_po[i] = sum_po[i - 1];
			nge.push_back(make_pair(i, a[i]));
		}
	}
	sort(nge.begin() + 1, nge.end(), cmp);
	ll num = 0;
	while (k >= nge[1].second && nge.size() > 1)
	{
		if (sum_po[nge[1].first] >= nge[1].second)
		{
			DEC(i, nge[1].first - 1, 1)
			{
				if (nge[1].second())
			}
		}
		nge.erase(nge.begin() + 1);
	}
	return 0;
}