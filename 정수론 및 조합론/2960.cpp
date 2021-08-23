#include<iostream>
using namespace std;
int sosuMin[1001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k,cnt=0,ans=0;
	cin>>n>>k;
	sosuMin[0]=sosuMin[1]=1;
	for(int i=2;i<=n;i++) sosuMin[i] = i;
	for(int i=2;i<=n;i++)
	{
		if(sosuMin[i]==i)
		{
			sosuMin[i]=i; 
			cnt++;
			if(cnt == k)
			{
				ans=i;
				break;
			}
			for(int j=i*i;j<=n;j+=i)
			{
				if(sosuMin[j]==j)
				{
					sosuMin[j]=i;
					cnt++;
					//cout<<cnt<<' '<<j<<'\n';
				}
				if(cnt == k)
				{
					ans=j;
					break;
				}
			}
		}
		if(ans != 0) break;
	}
	cout<<ans<<'\n';
	return 0;
}
