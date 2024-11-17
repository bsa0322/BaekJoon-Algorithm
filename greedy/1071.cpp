//1071-¼ÒÆ® 
#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef pair<int,int> ci;
map <int,int> num;
int main()
{
	int n, x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		num[x]++;
	}
	vector <ci> v(num.begin(),num.end());
	for(int i=0;i<v.size()-1;i++)
	{
		if(v[i+1].first-v[i].first == 1)
		{
			if(i+2 < v.size())
			{
				v.insert(v.begin()+i+1,ci(v[i+2].first, 1));
				v[i+3].second--;
				if(v[i+3].second == 0)
				{
					v.erase(v.begin()+i+3);
				}
			}
			else iter_swap(v.begin()+i,v.begin()+i+1);
		}
	}
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].second;j++)
			cout<<v[i].first<<' ';
	}
	cout<<'\n';
	return 0;
}
