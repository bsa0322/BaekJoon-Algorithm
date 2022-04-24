#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack <char> st;
int main()
{	
	string s;
	string ans = "yes";
	while(1)
	{
		st = stack <char>();
		ans = "yes";
		getline(cin,s);
		if(s[0] == '.')
		{
			break;
		}
		for(int i=0;i<s.length();i++)
		{
			if(s[i] == '(')
			{
				st.push('(');
			}
			else if(s[i] == '[')
			{
				st.push('[');
			}
			else if(s[i] == ')')
			{
				if(!st.empty() && st.top() == '(')
				{
					st.pop();
				}
				else
				{
					ans = "no";
					break;	
				}
			}
			else if(s[i] == ']')
			{
				if(!st.empty() && st.top() == '[')
				{
					st.pop();
				}
				else
				{
					ans = "no";
					break;
				}
			}
		}
		if(!st.empty()) ans = "no";
		cout<<ans<<'\n';
	}
	return 0;
} 
