#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector <int> triangle;
int main()
{
	int n, a, ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		triangle.push_back(a);
	}
	sort(triangle.begin(),triangle.end());
	for(int i=n-1;i>1;i--)
	{
		if(triangle[i] < triangle[i-1]+triangle[i-2])
		{
			ans = triangle[i]+triangle[i-1]+triangle[i-2];
		}
		if(ans != 0) break;
	}
	if(ans == 0) ans=-1;
	cout<<ans<<'\n';
	return 0;
}
