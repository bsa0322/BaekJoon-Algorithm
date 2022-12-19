#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> ci;
vector <int> mp[300001];
priority_queue <ci> q;
int d[300001];
vector <int> result;
int main1()
{
	ci t;
	int n, m, k, x, a, b;
	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		mp[a].push_back(b);
	}
	q.push(ci(0, x));
	while (!q.empty()) {
		t = q.top();
		q.pop();
		if (t.first >= k) continue; //시간초과 해결
		for (int i = 0; i < mp[t.second].size(); i++) {
			if ((mp[t.second][i]!=x && d[mp[t.second][i]] == 0) || d[mp[t.second][i]] > t.first + 1) {
				d[mp[t.second][i]] = t.first + 1;
				q.push(ci(t.first + 1, mp[t.second][i]));
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (d[i] == k) result.push_back(i);
	}
	if (result.size() == 0) {
		cout << "-1\n";
	}
	else {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << '\n';
		}
	}
	return 0;
}