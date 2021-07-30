#include<iostream>
#include<algorithm>
using namespace std;
int num[100001];
int cmp(int a,int b)
{
	if(a > b) return 1;
	else return 0;
}
int main()
{
	long long int ans=0;
	int n, tip=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	sort(num,num+n,cmp);
	for(int i=0;i<n;i++)
	{
		tip=num[i]-i;
		if(tip < 0) tip=0;
		ans+=tip;
	}
	cout<<ans<<'\n';
	return 0;
}
