#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
struct cmp{
	bool operator()(int a,int b)
	{
		if(abs(a) == abs(b)) return a > b;
		else return abs(a) > abs(b);
	}
};
priority_queue <int, vector<int>, cmp> pq;
int main()
{
	int n,a;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a==0)
		{
			if(!pq.empty())
			{
				cout<<pq.top()<<'\n';
				pq.pop();
			}
			else cout<<"0\n";
		}
		else
		{
			pq.push(a);
		}
	}
	return 0;
}
