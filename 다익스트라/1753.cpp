//최단경로 배수아 
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,int> ci; //현재지점과 그 지점까지의 최소경로값 저장해야하므로 pair 만들기
struct cmp //우선순위 큐에서 최소경로값 기준 오름차순 정렬되도록 하는 함수 
{
	bool operator() (ci x,ci y)
	{
		if(x.second < y.second) return 0;
		return 1;
	}
};
vector <ci> mp[20010]; //경로와 그 거리저장할 맵 vector 
priority_queue <ci, vector<ci>, cmp> pq; //다익스트라알고리즘에 사용할 우선순위 큐 
int ans[20010]; //각 지점마다의 시작점으로부터의 최단경로 저장 
int main()
{
	ci t;
	int V,e,k,u,v,w,t1,t2;
	cin>>V>>e;
	cin>>k;
	for(int i=0;i<e;i++)
	{
		cin>>u>>v>>w;
		mp[u].push_back(ci(v,w));
	}
	for(int i=1;i<=V;i++) ans[i]=-1; //-1은 시작점으로부터 그 지점을 갈수없음을 뜻함. 미리 초기화. 
	ans[k]=0; //시작점이므로 최단경로값이 0 
	pq.push(ci(k,0));
	while(!pq.empty()) //다익스트라, 최단경로값으로 계속 이어진 경로 검색하며 각 지점의 최단값을 찾아냄. 
	{
		t=pq.top();
		pq.pop();
		t1=t.first;
		t2=t.second;
		for(int i=0;i<mp[t1].size();i++)
		{
			if(ans[mp[t1][i].first] == -1 || ans[mp[t1][i].first] > t2+mp[t1][i].second)
			{
				ans[mp[t1][i].first] = t2+mp[t1][i].second;
				pq.push(ci(mp[t1][i].first, t2+mp[t1][i].second));
			}
		}
	}
	for(int i=1;i<=V;i++) //정답출력 
	{
		if(ans[i] == -1) cout<<"INF\n";
		else cout<<ans[i]<<'\n';
	}
	return 0;
} 
