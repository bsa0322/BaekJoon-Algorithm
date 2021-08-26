#include<iostream>
#include<string>
using namespace std;
int mp[9][9];
int main()
{
	string king,doll,n,mv;
	cin>>king>>doll>>n;
	mp[8-(king[0]-65)][9-(king[1]-48)]=1;
	mp[8-(doll[0]-65)][9-(doll[1]-48)]=2;
	for(int i=0;i<n;i++)
	{
		cin>>mv;
		
	}
	return 0;
}
