#include<iostream>
#include<algorithm>
using namespace std;
int snack[1000000];
int main1()
{
	int n, m, ans = 0, l=1, r=0, mid, cnt = 0;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> snack[i];
		if (r < snack[i]) r = snack[i];
	}
	sort(snack, snack + n);
	r = r * 2;
	while (l <= r)
	{
		mid = (l + r) / 2;
		cnt = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (snack[i] < mid) break;
			cnt += (snack[i] / mid);
		}
		if (cnt < m)
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
			if (cnt == m) ans = mid;
		}
	}
	cout << ans << "\n";
	return 0;
}