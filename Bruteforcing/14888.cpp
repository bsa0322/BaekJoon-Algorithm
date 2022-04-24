#include<iostream>
using namespace std;
int n,mx,mn;
int num[20];
int p[4];
void f(int cnt,int sum)
{
	int i;
	if(cnt==n-1) 
	{
		if(sum >= mx) mx=sum;
		if(sum <= mn) mn=sum;
        return;
	}
	for(i=0;i<4;i++)
	{
		if(p[i] > 0)
		{
			p[i]--;
			if(i==0)
				f(cnt+1,sum+num[cnt+1]);
			else if(i==1)
				f(cnt+1,sum-num[cnt+1]);
			else if(i==2)
				f(cnt+1,sum*num[cnt+1]);
			else 
			{
				if(sum < 0)
					f(cnt+1,(-1)*(sum*(-1)/num[cnt+1]));
				else
					f(cnt+1,sum/num[cnt+1]);
			}
			p[i]++;
		}
	}
}
int main()
{
	int i,j;
	cin>>n;
	for(i=0;i<n;i++) cin>>num[i];
	for(i=0;i<4;i++) cin>>p[i];
	mx=-1000000000;
	mn=1000000000;
	f(0,num[0]);
	cout<<mx<<'\n'<<mn<<'\n';
	return 0;
}
