//�ִܰ�� ����� 
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,int> ci; //���������� �� ���������� �ּҰ�ΰ� �����ؾ��ϹǷ� pair �����
struct cmp //�켱���� ť���� �ּҰ�ΰ� ���� �������� ���ĵǵ��� �ϴ� �Լ� 
{
	bool operator() (ci x,ci y)
	{
		if(x.second < y.second) return 0;
		return 1;
	}
};
vector <ci> mp[20010]; //��ο� �� �Ÿ������� �� vector 
priority_queue <ci, vector<ci>, cmp> pq; //���ͽ�Ʈ��˰��� ����� �켱���� ť 
int ans[20010]; //�� ���������� ���������κ����� �ִܰ�� ���� 
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
	for(int i=1;i<=V;i++) ans[i]=-1; //-1�� ���������κ��� �� ������ ���������� ����. �̸� �ʱ�ȭ. 
	ans[k]=0; //�������̹Ƿ� �ִܰ�ΰ��� 0 
	pq.push(ci(k,0));
	while(!pq.empty()) //���ͽ�Ʈ��, �ִܰ�ΰ����� ��� �̾��� ��� �˻��ϸ� �� ������ �ִܰ��� ã�Ƴ�. 
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
	for(int i=1;i<=V;i++) //������� 
	{
		if(ans[i] == -1) cout<<"INF\n";
		else cout<<ans[i]<<'\n';
	}
	return 0;
} 
