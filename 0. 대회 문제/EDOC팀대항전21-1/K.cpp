#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> ci;
vector <ci> v;
int main()
{
	int n,a,x,y;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>x>>y;
		if(a == 1)
		{
			v.push_back(ci(x,y));
		}
		if(a==2)
		{
			x=x-1;
			y=y-1;
			
		}
	}
	return 0;
}
