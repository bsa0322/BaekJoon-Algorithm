#include <iostream>
#include <set>

using namespace std;

set <int> s;
int main()
{
	set <int>::iterator iter;
	int n, x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		s.insert(x);
	}
	for(iter = s.begin();iter != s.end(); iter++)
	{
		cout<<*iter<<' ';
	}
	cout<<'\n';
	return 0;
}
