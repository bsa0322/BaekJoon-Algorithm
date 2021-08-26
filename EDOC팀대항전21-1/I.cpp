#include <iostream>
#include <cmath>
using namespace std;
int a[200010];
int b[200010];
long long int table[200010][2];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		table[i][0]=table[i][1]=-1;
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	table[0][0] = a[0];
	table[0][1] = b[0];
	for(int i=1;i<n;i++)
	{
		if(table[i][0] == -1 || table[i-1][0] + a[i] < table[i][0])
		{
			table[i][0] = table[i-1][0] + a[i];
		}
		if(table[i-1][1] + a[i] + k < table[i][0])
		{
			table[i][0] = table[i-1][1] + a[i] + k;
		}
		if(table[i][1] == -1 || table[i-1][0] + b[i] + k < table[i][1])
		{
			table[i][1] = table[i-1][0] + b[i] + k;
		}
		if(table[i-1][1] + b[i] < table[i][1]) table[i][1] = table[i-1][1] + b[i];
	}
	cout<<min(table[n-1][0],table[n-1][1])<<'\n';
	return 0;
}
