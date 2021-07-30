//최대힙 배수아 
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
priority_queue <int> pq; //내림차순 우선순위큐 
int main()
{
	cin.tie(0);
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(x==0) //0이면 젤 큰 값 출력, 우선순위큐를 내림차순으로 썼으므로 top에 있는 값이 젤 큰값 
		{
			if(!pq.empty())
			{
				cout<<pq.top()<<'\n';
				pq.pop();
			}
			else cout<<"0\n";
		}
		else //0이 아니면 우선순위큐에 숫자값 push해주면 됨. 
		{
			pq.push(x);
		}
	}
	return 0;
}
