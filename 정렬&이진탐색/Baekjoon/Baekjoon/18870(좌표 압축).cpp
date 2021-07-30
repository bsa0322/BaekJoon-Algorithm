#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> ci;
int ans[1000000];
int main2()
{
	int n, x;
	vector <ci> v;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		v.push_back(ci(x, i));
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < n; i++)
	{
		if (v[i - 1].first == v[i].first)
		{
			ans[v[i].second] = ans[v[i - 1].second];
		}
		else
		{
			ans[v[i].second] = ans[v[i - 1].second] + 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}