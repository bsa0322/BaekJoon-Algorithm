#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
vector <int> v[21]; //���� �̸� ���̸� ��Ÿ�� 
int main()
{
	long long int ans=0;
	string name;
	int n,k,st;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>name;
		v[name.length()].push_back(i+1); //�� �̸� ���̿� ���� ���� 
	}
	for(int i=1;i<=20;i++)
	{
		if(!v[i].empty())
		{
			st=0;
			for(int j=1;j<v[i].size();)
			{
				if(v[i][j]-v[i][st] <= k)
				{
					int temp = j-st;
					ans += temp;
					j++;
				}
				else
				{
					st++;
				}
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
