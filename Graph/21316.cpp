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
		//���� ������ 3���� ��� �߿� ������ ���� 
		if(v[i].size() == 3)
		{
			//check1�� ����� ����� �������� 1
			//check2�� ����� ����� �������� 2 
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
			//���� ������ ���� check1�� check2�� ��� �ش�Ǿ�� �� 
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
