#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector <int> tree(100001); 
queue <int> q;
int check[100001]; //트리값존재여부 체크배열 
int main()
{
	int i,j,a,k,h,node;
	cin>>k;
	h = (1<<k)-1; //완전이진트리노드수 
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
		//자식노드가 없거나 왼쪽 자식노드에 값이 있을 때 현재노드에 값 추가		
		if (check[node] == 0 && (node*2 > h || (node*2 <= h && check[node*2] == 1)))
		{
			check[node] = 1;
			tree[node] = q.front();
			q.pop();
		}
		//왼쪽  자식노드가 존재하는데 값이 없을 때 왼쪽 자식노드로 가기 
		else if (node*2 <= h && check[node*2] == 0)
		{
			node = node*2;
		}
		//현재노드에 값이 있고, 오른쪽 자식노드에 값이 없을 때 오른쪽 자식노드로 가기  
		else if (check[node] == 1 && node*2+1 <= h && check[node*2+1] == 0)
		{
			node = node*2+1;
		}
		//현재노드에 값이 있고, 왼쪽 오른쪽 자식 노드 모두에 값이 있을 때 부모노드로 가기 
		else if (check[node] == 1 && node*2+1 <= h && check[node*2] == 1 && check[node*2+1] == 1)
		{
			node = node/2;
		}
		//현재노드에 값이 있고, 자식노드가 존재하지 않을 때 부모노드로 가기 
		else if (check[node] == 1 && node*2 > h)
		{
			node = node/2;
		}
		
	}
	//트리 출력 
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
