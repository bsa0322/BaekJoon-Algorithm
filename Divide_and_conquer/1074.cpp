#include<iostream>
using namespace std;
int r, c; //행, 열 
int ans; //몇 번째 방문인지 
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
					exit(0); //답 찾으면 바로 종료 
				}
				ans++;
			}
		}
		return;
	}
	//순서 중요. 가장 큰 값은 1번에도 속하고 4번에도 속할 수 있지만, 4번으로 가게 되면 돌아가는 길이므로 1번선택하도록 순서 배치 
	if(x+m/2 <= r && y+m/2 <= c) f(x+m/2,y+m/2,m/2,st+(m/2)*(m/2)*3); //1번  
	else if(x+m/2 <= r && y <= c) f(x+m/2,y,m/2,st+(m/2)*(m/2)*2); //2번 
	else if(x <= r && y+m/2 <= c) f(x,y+m/2,m/2,st+(m/2)*(m/2)); //3번 
	else if(x <= r && y <= c) f(x,y,m/2,st); //4번 
}
int main()
{
	int n, m;
	cin>>n>>r>>c;
	m = (1<<n); //배열 크기
	f(0,0,m,0); 
	//cout<<ans<<'\n';
	return 0;
}
