#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int chess[3001][3001];
long long int dp[3001][3001];
int main()
{
	cin.tie(0);
	string s;
	int n,m;
	long long int ans=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		for(int j=0;j<m;j++)
		{
			if(s[j]=='B') 
			{
				chess[i][j]=1;
			}
		}
	}
	ans=n*m;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(chess[i][j] != chess[i-1][j] && chess[i][j] != chess[i][j-1] && chess[i][j] == chess[i-1][j-1])
			{
				dp[i][j]=1;
				dp[i][j]+=min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1]);
				ans+=dp[i][j];
			}
		}
	}
	/*for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<dp[i][j]<<' ';
		cout<<'\n';
	}*/
	cout<<ans<<'\n';
	return 0;
}
