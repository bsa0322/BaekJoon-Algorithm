#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
vector <string> result;
int num[3];
string s;
int n;
void f(int cnt,int t)
{
	if(cnt==2)
	{
		num[2]=n-1;
		int start=0;
		string st="";
		for(int i=0;i<3;i++)
		{
			for(int j=num[i];j>=start;j--)
			{
				st+=s[j];
			}
			start=num[i]+1;
		}
		result.push_back(st);
		return;
	}
	for(int i=t;i<n-1;i++)
	{
		num[cnt]=i;
		f(cnt+1,i+1);
	}
}
int main()
{
	cin>>s;
	n=s.length();
	f(0,0);
	sort(result.begin(),result.end());
	cout<<result[0]<<'\n';
	return 0;
}
