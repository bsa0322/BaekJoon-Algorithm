#include<iostream>
#include<vector>
using namespace std;
vector <int> v[13];
int ans;
int main()
{
	int x,y;
	int check1, check2;
	for(int i=0;i<12;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=12;i++)
	{
		//먼저 간선이 3개인 노드 중에 정답이 있음 
		if(v[i].size() == 3)
		{
			//check1은 연결된 노드의 간선수가 1
			//check2는 연결된 노드의 간선수가 2 
			check1 = check2 = 0;
			for(int j=0;j<v[i].size();j++)
			{
				if(v[v[i][j]].size() == 1)
				{
					check1 = 1;
				}
				if(v[v[i][j]].size() == 2)
				{
					check2 = 1;
				}
			}
			//가장 빛나는 별은 check1과 check2가 모두 해당되어야 함 
			if(check1 && check2)
			{
				ans = i;
				break;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
