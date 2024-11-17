#include<iostream>
#include<vector>
#include<queue>
using namespace std;
queue <int> q;
struct tree{
	int par;
	vector <int> child;
}treeData[55];
int main()
{
	int n, a, er, ans = 0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		treeData[i].par = a;
		if(a != -1) treeData[a].child.push_back(i);
	}
	for(int i=0;i<n;i++)
	{
		if(treeData[i].child.size() == 0) ans++;
	}
	cin>>er;
	if(treeData[treeData[er].par].child.size() == 1) ans++;
	q.push(er);
	while(!q.empty())
	{
		a = q.front();
		q.pop();
		if(treeData[a].child.size() == 0) ans--;
		else
		{
			for(int i=0;i<treeData[a].child.size();i++)
			{
				q.push(treeData[a].child[i]);
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
} 
