#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#define MAX 1000000000
using namespace std;
int mp[501][501];
int main()
{
	//freopen("input.txt","r",stdin);
	cin.tie(0);
	string ans="NO";
	int t,n,m,w,a,b,c;
	cin>>t;
	while(t--)
	{
		ans="NO";
		cin>>n>>m>>w;
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
			mp[b][a]=min(mp[b][a],c);
		}
		for(int i=0;i<w;i++)
		{
			cin>>a>>b>>c;
			mp[a][b]=min(mp[a][b],c*(-1));
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
			if(mp[i][i] < 0)
			{
				ans="YES";
				break;	
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
