#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
vector <int> vv;
stack <int> st;
int main()
{
	int n,x,y,ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		vv.push_back(y);
	}
	for(int i=0;i<=n;i++)
	{
		while(!st.empty() && st.top() > vv[i])
		{
			st.pop();
			ans++;
		}
		if(!st.empty() && st.top() == vv[i]) continue;
		st.push(vv[i]);
	}
	cout<<ans<<'\n';
	return 0;
}
