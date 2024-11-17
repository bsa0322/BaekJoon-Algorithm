#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#define MAX 1000000000000000
using namespace std;
long long int mp[501][501];
int main()
{
	//freopen("input.txt","r",stdin);
	cin.tie(0);
	int n,m,a,b;
	long long int c;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			mp[i][j]=MAX;
		}
	}
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		mp[a][b]=min(mp[a][b],c);
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==k) continue;
			for(int j=1;j<=n;j++)
			{
				if(k==j || mp[i][k]==MAX || mp[k][j]==MAX) continue;
				if(mp[i][j] > mp[i][k]+mp[k][j])
				{
					mp[i][j]=mp[i][k]+mp[k][j];
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(mp[i][i] < 0 && mp[1][i] != MAX)
		{
			cout<<"-1\n";
			return 0;
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(mp[1][i] == MAX) mp[1][i]=-1;
		cout<<mp[1][i]<<'\n';
	}	
	return 0;
}
