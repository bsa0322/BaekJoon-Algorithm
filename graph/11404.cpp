#include<iostream>
#include<algorithm>
#include<cmath>
#define MAX 1000000000
using namespace std;
int mp[101][101];
int ans[101][101];
int main()
{
	//freopen("input.txt","r",stdin);
	cin.tie(0);
	int n,m,a,b,c;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans[i][j]=MAX;
		}
	}
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		if(mp[a][b] == 0) mp[a][b]=c;
		else mp[a][b]=min(mp[a][b],c);
		ans[a][b] = mp[a][b];
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==k) continue;
			for(int j=1;j<=n;j++)
			{
				if(i==j || ans[i][k]==MAX || ans[k][j]==MAX) continue;
				if(ans[i][j] > ans[i][k]+ans[k][j])
				{
					ans[i][j] = ans[i][k]+ans[k][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(ans[i][j]==MAX) ans[i][j]=0;
			cout<<ans[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
