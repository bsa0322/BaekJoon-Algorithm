#include<iostream>
using namespace std;
int main()
{
	int n, ans;
	cin>>n;
	ans = (n/3600)+(n%3600/60)+(n%3600%60);
	cout<<ans<<'\n';
	return 0;
} 
