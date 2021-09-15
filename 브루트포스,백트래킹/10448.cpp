#include<iostream>
using namespace std;
int tri[45];
int ans;
void f(int cnt,int sum,int k)
{
	if(cnt == 3)
	{
		if(sum == k) ans=1;
		return;
	}
	for(int i=1;i<45;i++)
	{
		if(tri[i] + sum <= k)
		{
			f(cnt+1,sum+tri[i],k);	
		}
	}
}
int main()
{
	int t,k;
	cin>>t;
	for(int i=1;i<45;i++)
	{
		tri[i]=i*(i+1)/2;
	}
	while(t--)
	{
		cin>>k;
		ans=0;
		f(0,0,k);
		cout<<ans<<'\n';
	}
	return 0;
} 
