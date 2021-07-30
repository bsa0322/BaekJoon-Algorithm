#include<iostream>
#include<string>
#include<queue>
using namespace std;
typedef pair<string,int> ci;
queue <ci> q;
int stringToint(string n)
{
	int p=1, tot=0;
	for(int i=n.length()-1;i>=0;i--)
	{
		tot+=(p*(n[i]-48));
		p*=10;
	}
	return tot;
}
int main()
{
	ci t;
	string a,x;
	int cnt, xx, b, ans = -1;
	cin>>a>>b;
	q.push(ci(a,1));
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		x = t.first;
		cnt = t.second;
		xx = stringToint(x);
		if(xx == b)
		{
			ans = cnt;
			break;
		}
		if(xx*2 <= b)
		{
			q.push(ci(to_string(xx*2), cnt+1));
		}
		if(stringToint(x+"1") <= b)
		{
			q.push(ci((x+"1"),cnt+1));
		}
		
	}
	cout<<ans<<'\n';
	return 0;
}
