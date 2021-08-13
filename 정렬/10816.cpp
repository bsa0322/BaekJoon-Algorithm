#include<iostream>
using namespace std;
int pnum[10000010];
int nnum[10000010];
int n,m;
int main()
{
	cin.tie(0);
	int a,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		if(a>=0) pnum[a]++;
		else nnum[a*(-1)]++;
	}
	cin>>m;
	for(i=0;i<m;i++)
	{
		cin>>a;
		if(a>=0) cout<<pnum[a]<<' ';
		else cout<<nnum[a*(-1)]<<' ';
	}
	cout<<'\n';
	return 0;
}
