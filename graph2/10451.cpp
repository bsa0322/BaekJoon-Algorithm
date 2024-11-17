#include<iostream>
#include<queue>
using namespace std;
queue <int> q;
int check[1010];
int mp[1010];
int main()
{
	int t,n,i,j,a,ans=0,x;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>mp[i];
		}
		for(i=1;i<=n;i++)
		{
			if(check[i]==0)
			{
				ans++;
				check[i]=1;
				q.push(i);
				while(!q.empty())
				{
					x=q.front();
					q.pop();
					if(check[mp[x]]==0)
					{
						check[mp[x]]=1;	
						q.push(mp[x]);
					}
				}
			}
		}
		for(i=1;i<=n;i++) check[i]=0;
		cout<<ans<<'\n';
	}
	return 0;
}
