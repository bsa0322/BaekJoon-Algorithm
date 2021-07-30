#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,int> ci;
struct cmp{
	bool operator()(ci x, ci y)
	{
		if(x.second < y.second) return 0;
		return 1;
	}
};
vector <vector<ci> > v(1001);
priority_queue <ci, vector<ci>, cmp> pq;
int ans[1001];
int main()
{
	ci t;
	int n,m,a,b,c,s,e,x,y;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		v[a].push_back(ci(b,c));
	}
	cin>>s>>e;
	for(int i=1;i<=n;i++)
	{
		ans[i]=-1;
	}
	ans[s]=0;
	pq.push(ci(s,0));
	while(!pq.empty())
	{
		t=pq.top();
		pq.pop();
		x=t.first;
		y=t.second;
		for(int i=0;i<v[x].size();i++)
		{
			if(ans[v[x][i].first]==-1 || ans[v[x][i].first] > y+v[x][i].second)
			{
				ans[v[x][i].first] = y+v[x][i].second;
				pq.push(ci(v[x][i].first,y+v[x][i].second));
			}
		}
	}
	cout<<ans[e]<<'\n';
	return 0;
}
