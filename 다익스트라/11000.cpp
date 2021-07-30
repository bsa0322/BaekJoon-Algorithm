#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> ci;
struct cmp{
	bool operator()(ci x,ci y)
	{
		if(x.second < y.second) return 0;
		return 1;
	}
};
vector <ci> v;
priority_queue <ci, vector<ci>, cmp> pq;
int main()
{
	cin.tie(0);
	ci tt;
	int n,s,t,ans=0,x,y;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s>>t;
		v.push_back(ci(s,t));
	}
	sort(v.begin(),v.end());
	pq.push(v[0]);
	ans++;
	for(int i=1;i<n;i++)
	{
		tt = pq.top();
		if(v[i].first >= tt.second)
		{
			pq.pop();
			pq.push(v[i]);
		}
		else
		{
			ans++;
			pq.push(v[i]);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
