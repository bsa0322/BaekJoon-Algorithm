#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> ci;
vector <int> people[200001];
queue <ci> q; //인덱스와 시간 저장 
int ans[200001];
int check[200001];
int link[200001]; //몇명 믿는지 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ci t;
	int n,m,a,x,cnt,chk=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ans[i]=-1;
		while(1)
		{
			cin>>a;
			if(a==0) break;
			people[i].push_back(a);	
		}
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a;
		q.push(ci(a,0));
		check[a]=1;
		ans[a]=0;
		chk++;
	}
	while(!q.empty())
	{
		chk = 0;
		t = q.front();
		q.pop();
		x = t.first;
		cnt = t.second;
		link[x]++; 
		if((people[x].size()+1)/2 <= link[x] && check[x]==0)
		{
			check[x]=1;
			ans[x]=cnt;
			chk=1;
		}
		if(chk == 1 || cnt == 0)
		{
			for(int i=0;i<people[x].size();i++)
			{
				if(check[people[x][i]] == 0)
				{
					q.push(ci(people[x][i],cnt+1));
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}
