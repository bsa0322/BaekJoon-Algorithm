#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct graph
{
	int a,b,c;
}data1[30];
struct ansgraph
{
	int a,b;
}data2[30];
int cmp(graph x,graph y)
{
	if(x.c < y.c) return 1;
	else return 0;
}
int parent[11];
int bb[11];
int link[11];
int cnt;
int f(int x)
{
	if(parent[x]==x) return x;
	else return parent[x]=f(parent[x]);
}
void u(int x,int y,int z)
{
	x=f(x);
	y=f(y);
	if(x!=y)
	{
		parent[y]=x;
		if(link[data1[i].a]+1 <= bb[data1[i].a] && link[data1[i].b]+1 <= bb[data1[i].b])
		{
			link[x]++;
			link[y]++;
			data2[cnt].a = x;
			data2[cnt].b = y;
			cnt++;
		}
	}
}
int main()
{
	cin.tie(0);
	string answer="YES";
	int v,e,i,chk=0;
	cin>>v>>e;
	for(i=1;i<=v;i++) parent[i]=i;
	for(i=1;i<=v;i++) cin>>bb[i];
	for(i=0;i<e;i++)
	{
		cin>>data1[i].a>>data1[i].b>>data1[i].c;
	}
	sort(data1,data1+e,cmp);
	for(i=0;i<e;i++)
	{
		u(data1[i].a,data1[i].b,data1[i].c);
	}
	for(i=1;i<v;i++)
	{
		int x=f(i);
		int x2=f(i+1);
		if(x!=x2)
		{
			chk=1;
			break;
		}
	}
	if(chk) 
	{
		cout<<"NO\n";
	}
	else
	{
		cout<<answer<<'\n';
		for(int i=0;i<cnt;i++)
		{
			cout<<data2[i].a<<' '<<data2[i].b<<'\n';
		}
	}
	return 0;
}
