#include<iostream>
#include<string>
using namespace std;
string s;
int main()
{
	int n;
	long long int m;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		int cnt = (s[i]-97) + m;
		if(cnt > 26) cnt = cnt-26;
	}
	return 0;
}
