#include<iostream>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
map <string,int> mp;
int main()
{
	//freopen("input.txt","r",stdin);
	map <string,int>::iterator it;
	string ss;
	int i;
	for(i=0;getline(cin,ss);i++)
	{
		it=mp.find(ss);
		if(it!=mp.end())
		{
			mp[ss]++;
		}
		else mp.insert(make_pair(ss,1));
	}
	for(it=mp.begin();it!=mp.end();it++)
	{
		cout<<it->first<<' ';
		printf("%.4lf\n", (double)(it->second*100) / (double)i);
	}
	return 0;
}
