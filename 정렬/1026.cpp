#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector <int> a,b;
int cmp(int x,int y)
{
	if(x > y) return 1;
	return 0;
}
int main()
{
	int n,x,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		cin>>x;
		b.push_back(x);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end(),cmp);
	for(int i=0;i<n;i++)
	{
		ans += a[i] * b[i];
	}
	cout<<ans<<'\n';
	return 0;
}
