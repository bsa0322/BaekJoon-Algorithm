#include <iostream>
#include <queue>
#include <vector>
using namespace std;
priority_queue <double, vector <double>, less<double> > pq;
int main()
{
	int n;
	long long int ans=0;
	double x,a,aa,bb;
	cin>>n>>x;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a == x)
		{
			ans++;
			continue;
		}
		pq.push(a);
	}
	while(!pq.empty())
	{
		if(!pq.empty())
		{
			aa=pq.top();
			pq.pop();
		}
		if(!pq.empty())
		{
			bb=pq.top();
			pq.pop();
		}
		double mid = aa+bb+x/2;
		if(mid >= x)
		{
			ans++;
			continue;
		}
		pq.push(mid);
	}
	cout<<ans<<'\n';
	return 0;
}
