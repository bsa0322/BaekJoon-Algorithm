#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> ci;
vector <ci> tree[10010];
int ans,x;
void solve(int w,int cur,int prev = -1)
{
	if(ans < w)
	{
		ans = w;
		x = cur;
	}
	for(int i=0;i<tree[cur].size();i++)
	{
		int next = tree[cur][i].first;
		int d=tree[cur][i].second;
		if(next == prev) continue;
		solve(w+d,next,cur);
	}
}
int main()
{
	//freopen("input.txt","r",stdin);
	int n,par,child,val;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		cin>>par>>child>>val;
		tree[par].push_back(ci(child,val));
		tree[child].push_back(ci(par,val));
	}
	solve(0,1);
	solve(0,x);
	cout<<ans<<'\n';
	return 0;
}
