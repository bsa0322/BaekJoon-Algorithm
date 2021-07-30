#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,int> ci;
priority_queue <int> pq;
queue <ci> q;
int main()
{
	ci tt;
	int t, n, m, ip, ans = 0;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		ans = 0;
		pq = priority_queue <int>();
		q = queue <ci>();
		for(int i=0;i<n;i++)
		{
			cin>>ip;
			q.push(ci(i, ip));
			pq.push(ip);
		}
		while(1)
		{
			tt = q.front();
			if(tt.second == pq.top())
			{
				ans++;
				pq.pop();
				q.pop();
				
				if (tt.first == m) break;
			}
			else
			{
				q.push(tt);
				q.pop();
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
