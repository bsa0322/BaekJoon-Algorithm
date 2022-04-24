#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	priority_queue <int, vector<int>, greater<int> > qw;
	priority_queue <int, vector<int>, greater<int> > qh;
	
	int w,h,n,a,b,i,mw=0,mh=0;
	cin>>w>>h;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a>>b;
		if(a==0) qw.push(b);
		else qh.push(b);
	}
	qw.push(h);
	qh.push(w);
	mw=a=qw.top();
	qw.pop();
	while(!qw.empty())
	{
		b=qw.top();
		qw.pop();
		if(b-a > mw) mw=b-a;
		a=b;
	}
	mh=a=qh.top();
	qh.pop();
	while(!qh.empty())
	{
		b=qh.top();
		qh.pop();
		if(b-a > mh) mh=b-a;
		a=b;
	}
	cout<<mw*mh<<'\n';
	return 0;
}
