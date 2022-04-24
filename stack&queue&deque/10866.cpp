#include<iostream>
#include<string>
#include<deque>
using namespace std;
deque <int> dq;
string s;
int main()
{
	int num[200001] = {0,}; 
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		if(s == "push_front")
		{
			cin>>x;
			dq.push_front(x);
		}
		else if(s == "push_back")
		{
			cin>>x;
			dq.push_back(x);
		}
		else if(s == "pop_front")
		{
			if(!dq.empty())
			{
				x=dq[0];
				dq.pop_front();
				cout<<x<<'\n';
			}
			else
				cout<<"-1\n";
		}
		else if(s == "pop_back")
		{
			if(!dq.empty())
			{
				x=dq[dq.size()-1];
				dq.pop_back();
				cout<<x<<'\n';
			}
			else
				cout<<"-1\n";
		}
		else if(s == "size")
		{
			cout<<dq.size()<<'\n';
		}
		else if(s == "empty")
		{
			cout<<dq.empty()<<'\n';
		}
		else if(s == "front")
		{
			if(!dq.empty())
				cout<<dq[0]<<'\n';
			else
				cout<<"-1\n";		
		}
		else if(s == "back")
		{
			if(!dq.empty())
				cout<<dq[dq.size()-1]<<'\n';
			else
				cout<<"-1\n";
		}
	}
	return 0;
}
