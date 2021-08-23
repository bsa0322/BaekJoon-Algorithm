#include<iostream>
using namespace std;
void func(int k)
{
	for(int i=2;i*i<=k;i++)
	{
		if(k%i) continue;
		while(k%i==0)
		{
			cout<<i<<' ';
			k/=i;
		}
	}
	if(k!=1) cout<<k;
} 
int main()
{
	int n,k;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		func(k);
		cout<<'\n';
	}
	return 0;
}
