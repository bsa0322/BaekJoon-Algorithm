#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector <int> v[10001];
int cmp(int x,int y)
{
	if(x > y) return 1;
	return 0;
}
int main()
{
	int n,d,p,long_d=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>p>>d;
		if(long_d < d) long_d = d;
		v[d].push_back(p);
	}
	for(int i=1;i<=long_d;i++)
	{
		if(!v[i].empty()) sort(v[i].begin(),v[i].end(),cmp);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=)
	}
	return 0;
}
