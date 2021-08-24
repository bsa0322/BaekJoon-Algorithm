#include<iostream>
using namespace std;
int f(int x)
{
	int r=0, x0, chk=1;
	x0 = x%10;
	x /= 10;
	r = x%10 - x0;
	while(x > 0)
	{
		x0 = x%10;
		x /= 10;
		if(x <= 0) break;
		if(r != x%10 - x0)
		{
			chk = 0;
			break;
		}
	}
	return chk;
}
int main()
{
	int n, ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(f(i)) ans++;
	}
	cout<<ans<<'\n';
	return 0;
}
