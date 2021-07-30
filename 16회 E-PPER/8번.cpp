#include<iostream>
using namespace std;
int num[100000];
int main()
{
    freopen("input.txt","r",stdin);
	long long int n, ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
   	}
   	for(int i=1;i<n;i++)
   	{
    	for(int j=i-1;j>=0;j--)
      	{
         	if(num[j] > num[i])
         	{
            	ans++;
         	}
      	}
   	}
   	cout<<ans<<'\n';
   	return 0;
}
