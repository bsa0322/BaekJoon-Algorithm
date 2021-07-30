//17136 색종이붙이기 배수아 
#include<iostream>
#include<cmath>
using namespace std;
int color[10][10];
int c[5]={5,5,5,5,5}; //1부터 5크기 5장 씩 있으므로 
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
				if(x==10) //10*10모두 돌았을 때 배열값 전부0이면, 색종이 모두 배열끝난 것이므로 ans갱신 
				{
					ans=min(ans,sum);
					return;
				}
				y=0;
			}
		}
	}
	if(ans <= sum) return;
	for(int i=5;i>=1;i--) //색종이 크기 5부터 1까지 모두 시도 
	{
		if(x+i <= 10 && y+i <= 10 && c[i-1] > 0)
		{
			int chk = 1; //i*i크기 색종이 붙이는 것 가능한지 검사 
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
			if(chk) //가능하면 색종이 붙이기 
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
				//return 되었을 때 다시 값들 원상복귀 
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
