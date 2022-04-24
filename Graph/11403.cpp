#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int mp[101][101];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>mp[i][j];
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==k) continue;
			for(int j=1;j<=n;j++)
			{
				if(k==j) continue;
				if(mp[i][k]==1 && mp[k][j]==1)
				{
					mp[i][j]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<mp[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
