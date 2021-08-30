#include <iostream>
#include <map>
#include <vector>

using namespace std;

map <string,int> m;

int main()
{
	//freopen("input.txt","r",stdin);
	string car;
	int n, ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>car;
		m[car]=i;
	}
	vector <string> v(n+1,"");
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(m[v[i]] > m[v[j]])
			{
				ans++;
				break;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
