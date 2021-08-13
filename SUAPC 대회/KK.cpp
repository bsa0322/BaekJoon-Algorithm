#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
vector <int> pm;
vector <long long> result;
int prime[1000001];
int chkHap;
int isnotprime(int x)
{
	int chk=0;
	if(x <= 1000000)
	{
		if(prime[x]!=x)
		{
			chk=1;
			int prevx=prime[x];
	    	int xx=x;
	    	int cnt=1;
	    	int tocnt=0;
	    	while(1)
	    	{
	    		xx=xx/prime[xx];
	    		if(prime[xx] != prevx)
	    		{
	    			if(cnt >= 2) tocnt+=(cnt/2);
	    			cnt=1;
				}
	    		if(prime[xx]==xx) break;
	    		cnt++;
	    		prevx=prime[xx];
			}
			if(tocnt < 2) chkHap=1;
		}
	}
    else
    {
    	for(int i=0;i<pm.size();i++)
		{
			if(x%pm[i]==0)
			{
				chk=1;
				break;	
			}	
		}	
	}
	return chk;
}
int main()
{
	long long tmp;
	long long n,chk=0;
	cin>>n;
	for(int i=2;i<=1000000;i++) prime[i]=i;
	for(long long i=2;i<=1000001;i++)
	{
		if(prime[i]==i)
		{
			pm.push_back(i);
			for(long long j=i*i;j<=1000001;j+=i)
			{
				if(prime[j]==j) prime[j]=i;
			}
		}
	}
	if(prime[n]==n){
		cout<<"-1\n";
		return 0;
	}
	while(1)
	{
		for(int i=4;i<=sqrt(n);i++)
		{
			if(prime[i]!=i && n%i==0)
			{
				result.push_back(i);
				tmp=n/i;
				chkHap=0;
				if(isnotprime(tmp))
				{
					chk=1;
					n=tmp;
					break;
				}
			}
		}
		if(chk==0) break;
		if(chkHap) 
		{
			result.push_back(n);
			break;
		}
	}
	if(chk==0) 
	{
		cout<<"-1\n";
		return 0;
	}
	for(int i=0;i<result.size();i++)
	{
		cout<<result[i]<<' ';
	}
	return 0;
}
