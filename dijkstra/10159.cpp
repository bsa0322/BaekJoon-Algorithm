//저울 배수아 
#include<iostream>
using namespace std;
int ans[101][101]; //저울들 사이의 연결관계(연결되있으면 서로의 무게관계를 아는것) 
int answer[101]; //각 번호들이 관계를 모르는 번호의 개수,즉 문제의 정답을 저장할 배열 
int main()
{
	int n,m,a,b;
	cin>>n>>m;
	for(int i=1;i<=n;i++) answer[i]=n-1; //입력값이 들어오기 전엔  자기자신제외 다 모르므로 n-1로 초기화 
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		if(ans[a][b]==0) //동일한 간선 중복 안되게 처리 
		{
			answer[a]--; //입력받으면 각각 번호들이 서로 알게되므로 -1처리 
			answer[b]--;
		}
		ans[a][b]=1; //연결관계 1로 저장, 1이 연결되있다는 것 
	}
	for(int k=1;k<=n;k++) //플로이드 탐색 시작 
	{
		for(int i=1;i<=n;i++)
		{
			if(i==k) continue;
			for(int j=1;j<=n;j++)
			{
				if(i==j || j==k) continue;
				if(ans[i][k]==1 && ans[k][j]==1 && ans[i][j]==0) //첫 연결일 경우 
				{
					ans[i][j]=1;
					answer[i]--; //서로 번호들을 알게 된 것이므로 -1 처리 
					answer[j]--;
				}
			}
		}
	}
	for(int i=1;i<=n;i++) //정답출력 
	{
		cout<<answer[i]<<'\n';
	}
	return 0;
}
