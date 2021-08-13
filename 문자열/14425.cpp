#include<iostream>
#include<set>
using namespace std;
set <string> s;
set<int>::iterator iter;
string ss;
int main()
{
	int i,n,m,ans=0;
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>ss;
		s.insert(ss);
	}
	for(i=0;i<m;i++)
	{
		cin>>ss;
		if (s.find(ss) != s.end()) ans++;
	}
	cout<<ans<<'\n';
	return 0;
} 
