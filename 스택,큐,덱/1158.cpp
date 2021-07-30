#include<iostream>
#include<deque>
#include<vector>
using namespace std;
deque <int> q;
vector <int> v;
int main()
{
	int n,k,id=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		q.push_back(i);
	}
	while(!q.empty())
	{
		if(id+k-1 < q.size())
		{
			id = id+k-1;
		}
		else
		{
			id = id+k-1-q.size();
			while(id >= q.size())
			{
				id -= q.size();
			}
		}
		v.push_back(q[id]);
		q.erase(q.begin() + id);
		
	}
	cout<<'<';
	for(int i=0;i<v.size()-1;i++)
	{
		cout<<v[i]<<", ";
	}
	cout<<v[v.size()-1]<<'>'<<'\n';
	return 0;
}
