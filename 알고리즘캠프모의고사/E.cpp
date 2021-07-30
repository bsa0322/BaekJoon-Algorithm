#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,int> ci;
vector <vector<ci> > mp(200001);
queue <ci> q;
int check[200001];
int main()
{
	ci t;
	int n,r,a,b,d,giga=0,x,y,ans1=0,ans2=0;
	cin>>n>>r;
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b>>d;
		mp[a].push_back(ci(b,d));
		mp[b].push_back(ci(a,d));
	}
	q.push(ci(r,0));
	check[r]=1;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		x=t.first;
		y=t.second;
		if(giga==0 && ((x==r && mp[x].size() >= 2) || (x!=r && mp[x].size() > 2)))
		{
			giga=x;
			ans1=y;
			y=0;
		}
		if(giga!=0)
		{
			if(ans2 < y) ans2=y;
		}
		for(int i=0;i<mp[x].size();i++)
		{
			if(check[mp[x][i].first]==0)
			{
				check[mp[x][i].first]=1;
				q.push(ci(mp[x][i].first,mp[x][i].second+y));
			}
			
		}
	}
	if(giga==0) ans1=y;
	cout<<ans1<<' '<<ans2<<'\n';
	return 0;
}
