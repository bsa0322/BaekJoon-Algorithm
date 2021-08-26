#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef pair<int,int> ci;
multimap <int, ci> mp;
vector <int> v;
int main()
{
	multimap<int, ci>::iterator iter;
	int n,a,sum,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		v.push_back(a);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			sum = v[i]+v[j];
			mp.insert(make_pair(sum,ci(i,j)));
		}
	}
	for(int i=0;i<n;i++)
	{
		while(1)
		{
			if(mp.empty()) break;
			iter = mp.find(v[i]);
			if(iter == mp.end()) break;
			if(iter->second.first != i && iter->second.second != i)
			{
				ans++;
				break;
			}
			mp.erase(iter);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
