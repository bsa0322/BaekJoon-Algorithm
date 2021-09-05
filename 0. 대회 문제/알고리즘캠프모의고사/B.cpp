#include<iostream>
#include<algorithm>
using namespace std;
int ans[4300];
int check[4300];
int main()
{
	int n, nn, k, cnt, num=1;
	cin>>n>>k;
	if(k < n)
	{
		ans[k] = num++;
	}
	else
	{
		cnt = k;
		nn = n-1;
		while(cnt > 0)
		{
			if(cnt >= nn)
			{
				ans[nn]=num++;
				cnt = cnt-nn;
				nn--;
			}
			else
			{
				ans[cnt]=num++;
				break;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(ans[i]==0)
		{
			ans[i]=num++;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}
