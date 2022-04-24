//배수아 c++ 14494 
#include<iostream>
using namespace std;
long long int table[1010][1010]; //다이나믹 배열 
int main()
{
	int n,m;
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
	{
		table[i][1] = 1; //1번째 열은 위에서 내려오는 경우밖에 없으므로 1로 초기화 
	}
	for(int i=1;i<=m;i++)
	{
		table[1][i] = 1; //1번째 행은 왼쪽에서 오는 경우밖에 없으므로 1로 초기화 
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			table[i][j]=(table[i-1][j] + table[i][j-1] + table[i-1][j-1])%1000000007; 
			//왼쪽, 위, 대각선에서 오는 곳의 경우의 수 모두 더하기 
		}
	}
	cout<<table[n][m]<<'\n';
	return 0;
} 
