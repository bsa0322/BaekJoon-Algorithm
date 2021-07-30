#include<iostream>
#include<cmath>
#include<deque>
#include<queue>
using namespace std;
deque <int> dq;
int main()
{
	int n,m,a,ans=0,st,ed,id;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		dq.push_back(i+1);
	}
	for(int i=0;i<m;i++)
	{ 
		cin>>a;
		if(a != dq.front())
		{
			while(1)
			{
				st = dq.front();
				ed = dq.back();
				
				if (a == st)
				{
					dq.pop_front();
					break;
				}	
				
				for(int i=0;i<dq.size();i++)
				{
					if(dq[i] == a) 
					{
						id = i;
						break;
					}
				}
				
				if(id < dq.size()-id)
				{
					dq.push_back(st);
					dq.pop_front();
					ans++;
				}
				else
				{
					dq.push_front(ed);
					dq.pop_back();
					ans++;
				}
			}
		}
		else dq.pop_front();
		
	}
	cout<<ans<<'\n';
	return 0;
}
