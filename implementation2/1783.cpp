#include<iostream>
using namespace std;
long long n,m,answer;
int main()
{

	cin>>n>>m;
	if(n==1) answer=1;
	else if(n==2)
	{
		if(m <= 2) answer=1;
		else if(m <= 4) answer=2;
		else if(m <= 6) answer=3;
		else answer=4;
	}
	else
	{
		if(m >= 7) answer=m-2;
		else if(m==1) answer=1;
		else if(m==2) answer=2;
		else if(m==3) answer=3;
		else answer=4;
	}
	cout<<answer<<'\n';
	return 0;
}
