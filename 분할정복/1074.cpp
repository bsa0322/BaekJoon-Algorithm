#include<iostream>
using namespace std;
int r, c; //��, �� 
int ans; //�� ��° �湮���� 
void f(int x, int y, int m, int st)
{
	//if(x > r || y > c) return;
	if(m==2)
	{
		ans=st;
		for(int i=x;i<x+m;i++)
		{
			for(int j=y;j<y+m;j++)
			{
				if(i==r && j==c)
				{
					cout<<ans<<'\n';
					exit(0); //�� ã���� �ٷ� ���� 
				}
				ans++;
			}
		}
		return;
	}
	//���� �߿�. ���� ū ���� 1������ ���ϰ� 4������ ���� �� ������, 4������ ���� �Ǹ� ���ư��� ���̹Ƿ� 1�������ϵ��� ���� ��ġ 
	if(x+m/2 <= r && y+m/2 <= c) f(x+m/2,y+m/2,m/2,st+(m/2)*(m/2)*3); //1��  
	else if(x+m/2 <= r && y <= c) f(x+m/2,y,m/2,st+(m/2)*(m/2)*2); //2�� 
	else if(x <= r && y+m/2 <= c) f(x,y+m/2,m/2,st+(m/2)*(m/2)); //3�� 
	else if(x <= r && y <= c) f(x,y,m/2,st); //4�� 
}
int main()
{
	int n, m;
	cin>>n>>r>>c;
	m = (1<<n); //�迭 ũ��
	f(0,0,m,0); 
	//cout<<ans<<'\n';
	return 0;
}
