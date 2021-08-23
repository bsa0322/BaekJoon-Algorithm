#include<iostream>
using namespace std;
int GCD(int a,int b)
{
	if(b == 0) return a;
	else return GCD(b,a%b);
}
int main()
{
	int a,b,g,l;
	cin>>a>>b;
	g = GCD(min(a,b),max(a,b));
	l = a*b/g;
	cout<<g<<'\n'<<l<<'\n';
	return 0;
}
