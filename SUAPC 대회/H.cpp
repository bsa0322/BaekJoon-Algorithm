#include<iostream>
using namespace std;
struct kakao{
	double a,b,c;
}dt[500001];
int main()
{
	cin.tie(0);
	int n,ans=0;
	double a1,b1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>dt[i].a>>dt[i].b>>dt[i].c;
		if(dt[i].b!=0)
		{
			dt[i].a=dt[i].a/dt[i].b;
			dt[i].b=1;
			dt[i].c=dt[i].c/dt[i].b;
		}
	}
	if(n==1)
	{
		cout<<"0\n";
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			a1=dt[i].a;
			b1=dt[i].b;
			if(a1==0 || b1==0)
			{
				ans+=(n-i-1);
				continue;
			}
			for(int j=i+1;j<n;j++)
			{
				if(dt[j].a != a1) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
