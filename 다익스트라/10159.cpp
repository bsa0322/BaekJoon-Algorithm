//���� ����� 
#include<iostream>
using namespace std;
int ans[101][101]; //����� ������ �������(����������� ������ ���԰��踦 �ƴ°�) 
int answer[101]; //�� ��ȣ���� ���踦 �𸣴� ��ȣ�� ����,�� ������ ������ ������ �迭 
int main()
{
	int n,m,a,b;
	cin>>n>>m;
	for(int i=1;i<=n;i++) answer[i]=n-1; //�Է°��� ������ ����  �ڱ��ڽ����� �� �𸣹Ƿ� n-1�� �ʱ�ȭ 
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		if(ans[a][b]==0) //������ ���� �ߺ� �ȵǰ� ó�� 
		{
			answer[a]--; //�Է¹����� ���� ��ȣ���� ���� �˰ԵǹǷ� -1ó�� 
			answer[b]--;
		}
		ans[a][b]=1; //������� 1�� ����, 1�� ������ִٴ� �� 
	}
	for(int k=1;k<=n;k++) //�÷��̵� Ž�� ���� 
	{
		for(int i=1;i<=n;i++)
		{
			if(i==k) continue;
			for(int j=1;j<=n;j++)
			{
				if(i==j || j==k) continue;
				if(ans[i][k]==1 && ans[k][j]==1 && ans[i][j]==0) //ù ������ ��� 
				{
					ans[i][j]=1;
					answer[i]--; //���� ��ȣ���� �˰� �� ���̹Ƿ� -1 ó�� 
					answer[j]--;
				}
			}
		}
	}
	for(int i=1;i<=n;i++) //������� 
	{
		cout<<answer[i]<<'\n';
	}
	return 0;
}
