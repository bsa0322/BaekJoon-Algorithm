#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> ci;
bool cmp(ci a,ci b)
{
	if(a.second != b.second) return a.second < b.second;
	else return a.first < b.first;
}
bool cmp2(ci a,ci b)
{
	if(a.first != b.first) return a.first < b.first;
	else return a.second < b.second;
}
int check_v[200001];
int check_bus[200001];
int main()
{
	int n,m,id,ans=0;
	cin>>n>>m;
	vector <ci> v(n,ci(0,0));
	vector <ci> bus(m,ci(0,0));
	for(int i=0;i<n;i++)
	{
		cin>>v[i].first>>v[i].second;
	}
	for(int i=0;i<m;i++)
	{
		cin>>bus[i].first>>bus[i].second;
	}
	sort(v.begin(),v.end(),cmp);
	sort(bus.begin(),bus.end(),cmp);
	id=0;
	for(int i=0;i<n;)
	{
		if(id == m) break;
		if(bus[id].second > v[i].second)
		{
			i++;
			continue;
		}
		if(bus[id].first >= v[i].first)
		{
			ans++;
			i++;
			check_v[i]=1;
			check_bus[id]=1;
		}
		id++;
	}
	id=0;
	for(int i=0;i<n;)
	{
		if(id == m) break;
		if(check_v[i] == 1)
		{
			i++;
			continue;
		}
		if(check_bus[id] == 1)
		{
			id++;
			continue;
		}
		if(bus[id].first < v[i].first)
		{
			id++;
			continue;
		}
		if(bus[id].second <= v[i].second)
		{
			ans++;
			id++;
		}
		i++;
	}
	cout<<ans<<'\n';
	return 0;
}
