#include<iostream>
#include<string>
#include<stack>
using namespace std;
stack <double> st;
string s;
int num[30];
int main()
{
	double a, b, ans = 0;
	int n;
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	for(int i=0;i<s.length();i++)
	{
		if(s[i] >= 65 && s[i] <= 91)
		{
			int id = (int)s[i] - 65;
			st.push((double)num[id]);
		}
		else if(s[i] == '+')
		{
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();
			st.push(a+b);
		}
		else if(s[i] == '-')
		{
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();
			st.push(b-a);
		}
		else if(s[i] == '*')
		{
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();
			st.push(a*b);
		}
		else if(s[i] == '/')
		{
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();
			st.push(b/a);
		}
	}
	ans = st.top();
	st.pop();
	cout << fixed;
	cout.precision(2);
	cout<<ans<<'\n';
	return 0;
}
