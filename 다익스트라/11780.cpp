//플로이드2 배수아 
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> ci;
struct cmp{
	bool operator()(ci x,ci y)
	{
		if(x.second < y.second) return 0;
		return 1;
	}
};
priority_queue <ci, vector<ci>, cmp> pq; //다익스트라시 사용할 우선순위 큐 
vector <vector <ci> > v(101); //입력값으로 들어오는 경로와 그 각각의 거리를 저장할 벡터 
vector <int> result; //각 (i,j)의 경로를 저장할 vector 
int ans[101][101]; //최단경로값 저장할 배열 
int d[101][101]; //그 전의 경로저장할 배열 
int main()
{
	cin.tie(0);
	ci t;
	int n,m,a,b,c,x,y;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		v[a].push_back(ci(b,c));
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans[i][j]=-1;
		}
	}
	//다익스트라 알고리즘으로 최단경로값 찾기 
	for(int s=1;s<=n;s++)
	{
		pq.push(ci(s,0));
		ans[s][s]=0;
		while(!pq.empty())
		{
			t=pq.top();
			pq.pop();
			x=t.first;
			y=t.second;
			for(int i=0;i<v[x].size();i++)
			{
				if(ans[s][v[x][i].first]==-1 || ans[s][v[x][i].first] >= y+v[x][i].second)
				{
					ans[s][v[x][i].first] = y+v[x][i].second;
					d[s][v[x][i].first] = x; //바로 전의 경로 갱신 
					pq.push(ci(v[x][i].first,y+v[x][i].second));
				}
			}
		}
	}
	//최단경로값 출력 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(ans[i][j]==-1) cout<<0<<' ';
			else cout<<ans[i][j]<<' ';
		}
		cout<<'\n';
	}
	//경로찾기 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			//자기자신부터 거꾸로 탐색하며 경로 찾아감 
			x=j;
			result.push_back(x);
			while(1)
			{
				x=d[i][x];
				if(x==0) break;
				result.push_back(x);
			}
			if(result.size()==1) cout<<"0\n"; //사이즈가 1이면 자기자신밖에 없으므로 0 출력 
			else //사이즈가 1이 아닌 경우 사이즈 먼저 출력하고 경로 출력 
			{
				cout<<result.size()<<' ';
				for(int k=result.size()-1;k>=0;k--)
				{
					cout<<result[k]<<' ';
				}
				cout<<'\n';
			}
			result = vector<int>(); //result 초기화 
		}
	}
	return 0;
}
