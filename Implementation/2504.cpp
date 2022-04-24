#include<iostream>
#include<string>
#include<stack>
using namespace std;
string s;
stack <char> bracket;
int main()
{
	bool right = true;
	int t = 1;
	int ans = 0;
	cin>>s;
	
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(')
		{
			bracket.push('(');
			t *= 2;
		}
		else if(s[i]=='[')
		{
			bracket.push('[');
			t *= 3;
		}
		else if(s[i]==')')
		{
			if(bracket.empty() || bracket.top() != '(')
			{
				right = false;
				break;
			}
			if(s[i-1] == '(') ans += t;
			t /= 2;
			bracket.pop();
		}
		else
		{
			if(bracket.empty() || bracket.top() != '[')
			{
				right = false;
				break;
			}
			if(s[i-1] == '[') ans += t;
			t /= 3;
			bracket.pop();
		}
	} 
	
	if(!right || !bracket.empty()) cout<<"0\n";
	else cout<<ans<<'\n';
	return 0;
 
} 
