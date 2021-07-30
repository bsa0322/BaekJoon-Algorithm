#include<iostream>
using namespace std;
int main()
{
	int n,m,a,s=1,x,ans=0;
	cin>>n>>m;
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>x;
		if(s < x)
		{
			for(int j=s;j<=x;j++)
			{
				if(j+m-1 >= x)
				{
					s=j;
					break;
				}
				ans++;
			}
		}
		else
		{
			ans += (s-x);
			s = x;
		}
	}
	cout<<ans<<'\n';
	return 0;
} 
