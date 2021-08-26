#include <iostream>
#include <string>
using namespace std;
int check[26];
string s;
int main()
{
	int n,ans=0,chk=1;
	cin>>n;
	while(n--)
	{
		chk=1;
		cin>>s;
		for(int i=0;i<s.length();i++)
		{
			if(check[s[i]-97] == 0) 
			{
				check[s[i]-97]=i+1;
				continue;
			}
			if(i - check[s[i]-97] == 0) 
			{
				check[s[i]-97]=i+1;
				continue;
			}
			chk=0;
			break;
		}
		for(int i=0;i<26;i++) check[i]=0;
		if(chk) ans++;
	}
	cout<<ans<<'\n';
	return 0;
} 
