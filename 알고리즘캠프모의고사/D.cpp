#include<iostream>
#include<deque>
using namespace std;
deque <int> dodo, dodo_g;
deque <int> suyeon, suyeon_g;
int main()
{
	//freopen("input.txt","r",stdin);
	cin.tie(0);
	string ans="";
	int n,m,d,s,chk=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>d>>s;
		dodo.push_back(d);
		suyeon.push_back(s);
	}
	for(int i=0;i<m;i++)
	{
		chk=0;
		if(i%2==0) //dodo's
		{
			d=dodo.back();
			dodo.pop_back();
			dodo_g.push_back(d);
			if(dodo.empty()) 
			{
				ans = "su";
				break;
			}
			if(d == 5) //dodo get
			{
				chk=1;
				while(!suyeon_g.empty())
				{
					s=suyeon_g.front();
					suyeon_g.pop_front();
					dodo.push_front(s);
				}
				while(!dodo_g.empty())
				{
					d=dodo_g.front();
					dodo_g.pop_front();
					dodo.push_front(d);
				}
			}
		}
		else //suyeon's
		{
			s=suyeon.back();
			suyeon.pop_back();
			suyeon_g.push_back(s);
			if(suyeon.empty()) 
			{
				ans = "do";
				break;
			}
			if(s == 5) //dodo get
			{
				chk=1;
				while(!suyeon_g.empty())
				{
					s=suyeon_g.front();
					suyeon_g.pop_front();
					dodo.push_front(s);
				}
				while(!dodo_g.empty())
				{
					d=dodo_g.front();
					dodo_g.pop_front();
					dodo.push_front(d);
				}
			}
		}
		if(chk==0 && !dodo_g.empty() && !suyeon_g.empty())
		{
			if(dodo_g.back() + suyeon_g.back() == 5) //suyeon get
			{
				while(!dodo_g.empty())
				{
					d=dodo_g.front();
					dodo_g.pop_front();
					suyeon.push_front(d);
				}
				while(!suyeon_g.empty())
				{
					s=suyeon_g.front();
					suyeon_g.pop_front();
					suyeon.push_front(s);
				}
			}
		}
	}
	if(ans=="")
	{
		if(dodo.size() > suyeon.size()) ans="do";
		else if(dodo.size() == suyeon.size()) ans="dosu";
		else ans="su";
	}
	cout<<ans<<'\n';
	return 0;
}
