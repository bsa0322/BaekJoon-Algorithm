#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
typedef pair<int, int> ci;
typedef pair<ci, int> cc;
vector <int> v[10000];
queue <cc> q;
int main2()
{
	cc t;
	int dx[4] = { -1,1,0,0 }, dy[4] = { -1,1,-1,1 };
	int a, b, cnt = 1, mx, x, y, tx, ty, ans = 0, n;
	cin >> a >> b;
	mx = max(a, b);
	for (int i = 1;;) {
		v[i].push_back(cnt);
		if (cnt == a) {
			q.push(cc(ci(i, v[i].size()-1),0));
		}
		if (sqrt(cnt)==i) {
			if (cnt > mx) {
				n = i;
				break;
			}
			i++;
		}
		cnt++;
	}
	while (!q.empty()) {
		t = q.front();
		q.pop();
		x = t.first.first;
		y = t.first.second;
		cnt = t.second;
		//cout << x << ' ' << y << ' ' << cnt << '\n';
		if (v[x][y] == b)
		{
			ans = cnt;
			break;
		}
		for (int k = 0; k < 4; k++) {
			tx = x + dx[k];
			ty = y + dy[k];
			if (tx > 0 && tx <= n && ty >= 0 && ty < tx * 2 - 1 && dx[k] == 0) {
				q.push(cc(ci(tx, ty), cnt + 1));
			}
			else if (tx > 0 && tx <= n && ty >= 0 && ty < tx * 2 - 1 && dx[k] == -1 && ty % 2 == 0) {
				q.push(cc(ci(tx, ty), cnt + 1));
			}
			else if (tx > 0 && tx <= n && ty >= 0 && ty < tx * 2 - 1 && dx[k] == 1 && ty % 2 == 1) {
				q.push(cc(ci(tx, ty), cnt + 1));
			}
		}
	}
	cout << ans << '\n';
	return 0;
}