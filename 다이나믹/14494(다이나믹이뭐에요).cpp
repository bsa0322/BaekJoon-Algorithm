//����� c++ 14494 
#include<iostream>
using namespace std;
long long int table[1010][1010]; //���̳��� �迭 
int main()
{
	int n,m;
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
	{
		table[i][1] = 1; //1��° ���� ������ �������� ���ۿ� �����Ƿ� 1�� �ʱ�ȭ 
	}
	for(int i=1;i<=m;i++)
	{
		table[1][i] = 1; //1��° ���� ���ʿ��� ���� ���ۿ� �����Ƿ� 1�� �ʱ�ȭ 
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			table[i][j]=(table[i-1][j] + table[i][j-1] + table[i-1][j-1])%1000000007; 
			//����, ��, �밢������ ���� ���� ����� �� ��� ���ϱ� 
		}
	}
	cout<<table[n][m]<<'\n';
	return 0;
} 
