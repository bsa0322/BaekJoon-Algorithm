#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> ci;
vector <ci> mp[100010];
int leafnode[100010];
int n;

void f(int u)
{
	
}

int main()
{
	int i,a,b,c,st;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a>>b>>c;
		mp[a].push_back(ci(b,c));
		mp[b].push_back(ci(a,c));
	}
	for(i=n;i>=1;i--)
	{
		if(mp[i].size()==1)
		{
			leafnode[i]=1;
			st=i;
		}
	}
	f(st);
	return 0;
}
