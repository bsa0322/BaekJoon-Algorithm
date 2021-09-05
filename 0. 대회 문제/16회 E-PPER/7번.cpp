#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector <string> ans;
string s;
int main()
{
	string str="";
	char st;
	int sw=1,l;
	cin>>s;
	st = s[0];
	l=s.length();
	for(int i=1;i<l;i++)
	{
		if(s[i] != st)
		{
			if(sw==1)
				str+=st;
			else if(sw==-1)
			{
				str+=s[i];
				sw=0;
			}
			else sw=1;
			st=s[i];
		}
		else
		{
			if(sw==1)
				ans.push_back(str);
			str="";
			sw=-1;
		}	
	}
	if(s[l-1] != s[l-2] && str[str.length()-1] != s[l-1])
	{
		str+=s[l-1];
	}
	ans.push_back(str);
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}
