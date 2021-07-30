#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,int> ci;
priority_queue <int> q;
stack <int> s1,s2,s3;
vector <ci> result;
int main()
{
	cin.tie(0);
	ci t;
	int n,k=0,a,b,x,x1,x2,sw=1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		s1.push(x);
		q.push(x);
	}
	while(!s1.empty() || !s2.empty())
	{
		if(k > 12345) break;
		x1=x2=0;
		if(!s1.empty())
		{
			x1=s1.top();
		}
		else sw=-1;
		if(!s2.empty())
		{
			x2=s2.top();
		}
		else sw=1;	
		if(x1 == q.top())
		{
			s1.pop();
			q.pop();
			s3.push(x1);
			k++;
			result.push_back(ci(1,3));
		}
		else if(x2 == q.top())
		{
			s2.pop();
			q.pop();
			s3.push(x2);
			k++;
			result.push_back(ci(2,3));
		}
		else
		{
			if(x1!=0 && sw==1)
			{
				s1.pop();
				s2.push(x1);
				k++;
				result.push_back(ci(1,2));
			}
			else if(x2!=0 && sw==-1)
			{
				s2.pop();
				s1.push(x2);
				k++;
				result.push_back(ci(2,1));
			}
		}
	}
	if(k <= 12345)
	{
		cout<<k<<'\n';
		for(int i=0;i<result.size();i++)
		{
			t=result[i];
			cout<<t.first<<' '<<t.second<<'\n';
		}
	}
	return 0;
}
