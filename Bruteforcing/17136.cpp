//17136 �����̺��̱� ����� 
#include<iostream>
#include<cmath>
using namespace std;
int color[10][10];
int c[5]={5,5,5,5,5}; //1���� 5ũ�� 5�� �� �����Ƿ� 
int ans;
void f(int x, int y, int sum)
{
	while(1)
	{
		if(color[x][y]==1) break;
		if(y < 10)
		{
			y++;
			if(y == 10)
			{
				x++;
				if(x==10) //10*10��� ������ �� �迭�� ����0�̸�, ������ ��� �迭���� ���̹Ƿ� ans���� 
				{
					ans=min(ans,sum);
					return;
				}
				y=0;
			}
		}
	}
	if(ans <= sum) return;
	for(int i=5;i>=1;i--) //������ ũ�� 5���� 1���� ��� �õ� 
	{
		if(x+i <= 10 && y+i <= 10 && c[i-1] > 0)
		{
			int chk = 1; //i*iũ�� ������ ���̴� �� �������� �˻� 
			for(int a=x;a<x+i;a++)
			{
				for(int b=y;b<y+i;b++)
				{
					if(color[a][b]==0) 
					{
						chk=0;
						break;
					}
				}
			}
			if(chk) //�����ϸ� ������ ���̱� 
			{
				c[i-1]--;
				for(int a=x;a<x+i;a++)
				{
					for(int b=y;b<y+i;b++)
					{
						color[a][b]=0;
					}
				}
				f(x, y, sum+1);
				//return �Ǿ��� �� �ٽ� ���� ���󺹱� 
				c[i-1]++;
				for(int a=x;a<x+i;a++)
				{
					for(int b=y;b<y+i;b++)
					{
						color[a][b]=1;
					}
				}
			}
		}
	}
}
int main()
{
	//freopen("input.txt","r",stdin);
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cin>>color[i][j];
		}
	}
	ans=1000000000;
	f(0,0,0);
	if(ans == 1000000000) ans=-1;
	cout<<ans<<'\n';
	return 0;
}
