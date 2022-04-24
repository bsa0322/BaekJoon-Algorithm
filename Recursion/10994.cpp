#include <iostream>
#include <vector>
using namespace std;
int n,h,w;
char mp[400][400];
int star(int hst,int wst)
{
	int i;
	for(i=hst;i>=hst-h;i--)
	{
		mp[i][wst]=mp[i][wst+w-1]='*';
	}
	for(i=wst;i<wst+w;i++)
	{
		mp[hst-h][i]='*';
	}
	for(i=hst+1;i<=hst+h;i++)
	{
		mp[i][wst]=mp[i][wst+w-1]='*';
	}
	for(i=wst;i<wst+w;i++)
	{
		mp[hst+h][i]='*';
	}
	return 0;
}
int main()
{
	int n, width;
	
	//ют╥б 
	cin>>n;
	
	oh=ow=w=h=4*n-3;
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			mp[i][j]=' ';
		}
	}
	hst=h/2;
	wst=0;
	h=h/2;
	while(1)
	{
		if(n==0) break;
		f(hst,wst);
		wst+=2;
		h=h-2;
		w=w-4;
		n--;
	}
	for(i=0;i<oh;i++)
	{
		for(j=0;j<ow;j++)
		{
			cout<<mp[i][j];
		}
		cout<<'\n';
	}
	return 0;
}
