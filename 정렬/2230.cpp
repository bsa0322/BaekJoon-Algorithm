#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector <long long int> a;
int main()
{
	long long int n,m,x,l,ans=-1;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	l=0;
	for(int i=1;i<n;)
	{
		if(a[i]-a[l] >= m && l < n)
		{
			if(ans == -1 || ans > a[i]-a[l]) ans = a[i]-a[l];
			l++;
		}
		else i++;
	}
	cout<<ans<<'\n';
	return 0;
}
