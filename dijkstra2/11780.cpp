//�÷��̵�2 ����� 
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
priority_queue <ci, vector<ci>, cmp> pq; //���ͽ�Ʈ��� ����� �켱���� ť 
vector <vector <ci> > v(101); //�Է°����� ������ ��ο� �� ������ �Ÿ��� ������ ���� 
vector <int> result; //�� (i,j)�� ��θ� ������ vector 
int ans[101][101]; //�ִܰ�ΰ� ������ �迭 
int d[101][101]; //�� ���� ��������� �迭 
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
	//���ͽ�Ʈ�� �˰������� �ִܰ�ΰ� ã�� 
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
					d[s][v[x][i].first] = x; //�ٷ� ���� ��� ���� 
					pq.push(ci(v[x][i].first,y+v[x][i].second));
				}
			}
		}
	}
	//�ִܰ�ΰ� ��� 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(ans[i][j]==-1) cout<<0<<' ';
			else cout<<ans[i][j]<<' ';
		}
		cout<<'\n';
	}
	//���ã�� 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			//�ڱ��ڽź��� �Ųٷ� Ž���ϸ� ��� ã�ư� 
			x=j;
			result.push_back(x);
			while(1)
			{
				x=d[i][x];
				if(x==0) break;
				result.push_back(x);
			}
			if(result.size()==1) cout<<"0\n"; //����� 1�̸� �ڱ��ڽŹۿ� �����Ƿ� 0 ��� 
			else //����� 1�� �ƴ� ��� ������ ���� ����ϰ� ��� ��� 
			{
				cout<<result.size()<<' ';
				for(int k=result.size()-1;k>=0;k--)
				{
					cout<<result[k]<<' ';
				}
				cout<<'\n';
			}
			result = vector<int>(); //result �ʱ�ȭ 
		}
	}
	return 0;
}
