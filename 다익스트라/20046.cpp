#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> c;
typedef pair<c, int> ci;
struct cmp{
	bool operator()(ci x,ci y)
	{
		if(x.second < y.second) return 0;
		return 1;
	}
};
priority_queue <ci, vector<ci>, cmp> pq;
int ans[1001][1001];
int mp[1001][1001];
int main()
{
	ci t;
	int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1},x,y,z,tx,ty,tz,n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>mp[i][j];
			ans[i][j]=-1;
		}
	}
	if(mp[1][1]==-1) cout<<"-1\n";
	else
	{
		if(mp[1][1]==0) ans[1][1]=0;
		else ans[1][1]=mp[1][1];
		pq.push(ci(c(1,1),ans[1][1]));	
		while(!pq.empty())
		{
			t=pq.top();
			pq.pop();
			x=t.first.first;
			y=t.first.second;
			z=t.second;
			for(int k=0;k<4;k++)
			{
				tx=x+dx[k];
				ty=y+dy[k];
				if(tx>0 && ty>0 && tx<=n && ty<=m && mp[tx][ty]!=-1 && (ans[tx][ty]==-1 || ans[tx][ty] > z+mp[tx][ty]))
				{
					ans[tx][ty]=z+mp[tx][ty];
					tz=z+mp[tx][ty];
					pq.push(ci(c(tx,ty),tz));
				}
			}
		}
		cout<<ans[n][m]<<'\n';
	}
	return 0;
}
