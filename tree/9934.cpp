#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector <int> tree(100001); 
queue <int> q;
int check[100001]; //Ʈ�������翩�� üũ�迭 
int main()
{
	int i,j,a,k,h,node;
	cin>>k;
	h = (1<<k)-1; //��������Ʈ������ 
	for(i=0;i<h;i++)
	{
		cin>>a;
		q.push(a);
	}
	node = h/2+1;
	tree[node] = q.front();
	q.pop();
	check[node] = 1;
	while(!q.empty())
	{
		//�ڽĳ�尡 ���ų� ���� �ڽĳ�忡 ���� ���� �� �����忡 �� �߰�		
		if (check[node] == 0 && (node*2 > h || (node*2 <= h && check[node*2] == 1)))
		{
			check[node] = 1;
			tree[node] = q.front();
			q.pop();
		}
		//����  �ڽĳ�尡 �����ϴµ� ���� ���� �� ���� �ڽĳ��� ���� 
		else if (node*2 <= h && check[node*2] == 0)
		{
			node = node*2;
		}
		//�����忡 ���� �ְ�, ������ �ڽĳ�忡 ���� ���� �� ������ �ڽĳ��� ����  
		else if (check[node] == 1 && node*2+1 <= h && check[node*2+1] == 0)
		{
			node = node*2+1;
		}
		//�����忡 ���� �ְ�, ���� ������ �ڽ� ��� ��ο� ���� ���� �� �θ���� ���� 
		else if (check[node] == 1 && node*2+1 <= h && check[node*2] == 1 && check[node*2+1] == 1)
		{
			node = node/2;
		}
		//�����忡 ���� �ְ�, �ڽĳ�尡 �������� ���� �� �θ���� ���� 
		else if (check[node] == 1 && node*2 > h)
		{
			node = node/2;
		}
		
	}
	//Ʈ�� ��� 
	for(i=1;i<=(h/2+1);i*=2)
	{
		for(j=i;j<i*2;j++)
		{
			cout<<tree[j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
