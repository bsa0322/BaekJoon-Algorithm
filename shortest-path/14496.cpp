#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> ci;
vector <int> mp2[1001];
priority_queue <ci> q2;
int d2[1001];
int main()
{
	ci t;
	int n, m, a, b, x, y;
	cin >> a >> b >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		mp2[x].push_back(y);
		mp2[y].push_back(x);
	}
	q2.push(ci(0, a));
	while (!q2.empty()) {
		t = q2.top();
		q2.pop();
		for (int i = 0; i < mp2[t.second].size(); i++) {
			if ((mp2[t.second][i] != a && d2[mp2[t.second][i]] == 0) || d2[mp2[t.second][i]] > t.first + 1) {
				d2[mp2[t.second][i]] = t.first + 1;
				q2.push(ci(t.first + 1, mp2[t.second][i]));
			}
		}
	}
	if (a!=b && d2[b] == 0) {
		d2[b] = -1;
	}
	cout << d2[b] << '\n';
	return 0;
}