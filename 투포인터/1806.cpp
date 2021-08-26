#include<iostream>
#include<vector>
using namespace std;
vector <int> v;
int main()
{
	int n,s,a,ans=-1,l,r,sum;
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		v.push_back(a);
	}
	l=r=0;
	sum=v[l];
	while(l <= r)
	{
		if(sum < s && r+1 < n)
		{
			r++;
			sum+=v[r];
		}
		else
		{
			if(sum >= s && (ans==-1 || ans > r-l+1)) ans = r-l+1;
			sum-=v[l];
			l++;
		}
	}
	if(ans==-1) ans=0;
	cout<<ans<<'\n';
	return 0;
}
