#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
vector <int> pm;
vector <int> result;
int prime[1000001];
int chk;
void totans(int x)
{
	//x=n;
	long long a,b;
	while(1)
	{
		a=prime[x];
		x=x/prime[x];
		if(prime[x]==-1)
		{
			if(result.size() < 2) chk=0;
			else
			{
				result[result.size()-1]*=a;
				chk=1;	
			}
			break;
		}
		b=prime[x];
		x=x/prime[x];
		result.push_back(a*b);
		if(prime[x]==-1)
		{
			chk=1;
			break;
		}
	}
}
int main()
{
	long long n;
	cin>>n;
	prime[0]=prime[1]=-1;
	for(int i=2;i<=1000000;i++) prime[i]=i;
	for(int i=2;i<=1000000;i++)
	{
		if(prime[i]==i)
		{
			pm.push_back(i);
			if(i > 1000) continue;
			for(int j=i*i;j<=1000000;j+=i)
			{
				if(prime[j]==j) prime[j]=i;
			}
		}
	}
	if(prime[n]==n)
	{
		cout<<"-1\n";
		return 0;
	}
	if(n <= 1000000) totans(n);
	else
	{
		
	}
	if(chk)
	{
		for(int i=0;i<result.size();i++)
		{
			cout<<result[i]<<' ';
		}
	}
	else cout<<"-1\n";
	return 0;
}
