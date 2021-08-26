#include<iostream>
using namespace std;
int n, mp[100][100];
int dx[2] = {0,1};
int dy[2] = {1,0};
string ans = "Hing";
void f(int x,int y)
{
    if(mp[x][y] == 0) return;
	if(x == n-1 && y == n-1)
	{
		ans = "HaruHaru";
		return;
	}
	for(int i=0;i<2;i++)
	{
		int tx = x+dx[i]*mp[x][y];
		int ty = y+dy[i]*mp[x][y];
		if(tx < n && ty < n)
		{
			f(tx,ty);
		}
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mp[i][j];
		}
	}
	f(0,0);
	cout<<ans<<'\n';
	return 0;
}
