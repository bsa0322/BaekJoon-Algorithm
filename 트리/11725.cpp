#include<iostream>
#include<vector>
#include<queue>
using namespace std;
queue <int> q;
vector <int> v[100010];
int par[100010];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b, x;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	q.push(1);
	par[1] = -1;
	while(!q.empty())
	{
		x = q.front();
		q.pop();
		for(int i=0;i<v[x].size();i++)
		{
			if(par[v[x][i]] == 0)
			{
				par[v[x][i]] = x;
				q.push(v[x][i]);
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		cout<<par[i]<<'\n';
	}
	return 0;
}
