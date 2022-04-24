//4889-안정적인 문자열 
#include<iostream>
#include<string>
using namespace std;
string s;
int main()
{
	int n=1, top=0, ans=0;
	while(1)
	{
		top=ans=0;
		cin>>s;
		if(s[0]=='-') break;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='{')
			{
				top++;
			}
			else
			{
				top--;
				if(top < 0)
				{
					ans++;
					top+=2;
				}
			}
		}
		if(top > 0) ans+=(top/2);
		cout<<n<<". "<<ans<<'\n';
		n++;
	}
	return 0;
}
