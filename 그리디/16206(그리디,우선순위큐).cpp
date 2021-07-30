#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
priority_queue <int, vector<int>, greater<int> > pq10, pq;
int main()
{
	int i,j,n,m,A,ans=0,t;
//	while(1)
//	{
		ans=0;
		cin>>n>>m;
//		if(n==0) break;
		for(i=0;i<n;i++)
		{
			cin>>A;
			if(A == 10) ans++;
			else if(A % 10 == 0)
			{
				pq10.push(A);
			}
			else if(A > 10) pq.push(A);
		}
		while(m > 0 && !pq10.empty())
		{
			A = pq10.top();
			pq10.pop();
			t = A-10;
			ans++;
			m--;
			if (t == 10) ans++;
			else if(t == 20)
			{
				if(m <= 0) break;
				m--;
				ans += 2;
			}
			else pq10.push(t);
		}
		while(m > 0 && !pq.empty())
		{
			A = pq.top();
			pq.pop();
			t = A-10;
			ans++;
			m--;
			if (t == 10) ans++;
			else if (t > 10) pq.push(t);
		}
		cout<<ans<<'\n';	
//		pq = priority_queue <int, vector<int>, greater<int> >();
//	}
	
	return 0;
}
