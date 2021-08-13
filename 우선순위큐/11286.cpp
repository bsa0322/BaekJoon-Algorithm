#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

typedef pair <int, int> ci;

priority_queue <ci, vector<ci>, greater<ci> > q;
int main()
{
	ci t;
	int i, n, x;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		if(x == 0)
		{
			if(q.empty()) cout<<"0\n";
			else{
				t = q.top();
				cout<<t.second<<'\n';
				q.pop();
			}
		}
		else q.push(make_pair(abs(x),x));
	}
	return 0;
}
