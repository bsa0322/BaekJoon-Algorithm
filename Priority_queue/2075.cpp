#include<iostream>
#include<queue>
#include<vector>
using namespace std;
priority_queue <int, vector<int>, greater<int> > q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, i, a;
	cin>>n;
	for(i=0;i<n*n;i++)
	{
		cin>>a;
		if(q.size() < n)
		{
			q.push(a);
		}
		else if(q.size() == n)
		{
			if(q.top() < a)
			{
				q.pop();
				q.push(a);
			}
		}
	}
	cout<<q.top()<<'\n';
	return 0;
}
