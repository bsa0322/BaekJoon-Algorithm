//�ִ��� ����� 
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
priority_queue <int> pq; //�������� �켱����ť 
int main()
{
	cin.tie(0);
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(x==0) //0�̸� �� ū �� ���, �켱����ť�� ������������ �����Ƿ� top�� �ִ� ���� �� ū�� 
		{
			if(!pq.empty())
			{
				cout<<pq.top()<<'\n';
				pq.pop();
			}
			else cout<<"0\n";
		}
		else //0�� �ƴϸ� �켱����ť�� ���ڰ� push���ָ� ��. 
		{
			pq.push(x);
		}
	}
	return 0;
}
