#include<iostream>
#include<string>
using namespace std;
int checkR[10];
int checkB[10];
int checkY[10];
string s;
int main()
{
	cin.tie(0);
	string ans="NOT CHEATER";
	int t,n,a;
	cin>>t;
	while(t--)
	{
		ans="NOT CHEATER";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			a=s[1]-48;
			if(s[0]=='R')
			{
				checkR[a]++;
			}
			else if(s[0]=='B')
			{
				checkB[a]++;
			}
			else if(s[0]=='Y')
			{
				checkY[a]++;
			}
		}
		for(int i=0;i<n;i++)
		{
			cin>>s;
			a=s[1]-48;
			if(s[0]=='R')
			{
				checkR[a]--;
				if(checkR[a] < 0) 
				{
					ans="CHEATER";
				}
			}
			else if(s[0]=='B')
			{
				checkB[a]--;
				if(checkB[a] < 0)
				{
					ans="CHEATER";
				}
			}
			else if(s[0]=='Y')
			{
				checkY[a]--;
				if(checkY[a] < 0)
				{
					ans="CHEATER";
				}
			}
		}
		cout<<ans<<'\n';
		for(int i=0;i<10;i++)
		{
			checkR[i]=checkB[i]=checkY[i]=0;
		}
	}
	return 0;
}
