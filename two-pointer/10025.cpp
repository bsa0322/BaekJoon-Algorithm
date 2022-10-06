#include<iostream>
using namespace std;
int uri[1000010];
int main()
{
	int n,x,g,k,s=0,mx=0,ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>g>>x;
		uri[x] = g;
		if(mx < x) mx = x;
	}
	k = k*2+1;
	for(int i=0;i<=mx;i++)
	{
		if(i >= k)
		{
			s -= uri[i-k];
		}
		s+=uri[i];
		
		if(s > ans) ans = s;
	}
	cout<<ans<<'\n';
	return 0;
 
} 
