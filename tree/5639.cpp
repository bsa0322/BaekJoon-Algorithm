#include<iostream>
using namespace std;
struct binaryTree{
	int keyValue;
	int left_child,right_child;
}treeData[100010];
void insertTree(int node, int idx, int key)
{
	if(treeData[node].keyValue > key)
	{
		if(treeData[node].left_child == 0)
		{
			treeData[node].left_child = idx;
		}
		else insertTree(treeData[node].left_child, idx, key);
	}
	else
	{
		if(treeData[node].right_child == 0)
		{
			treeData[node].right_child = idx;
		}
		else insertTree(treeData[node].right_child, idx, key);
	}
}
void post_order(int root)
{
	if(treeData[root].left_child != 0) post_order(treeData[root].left_child);
	if(treeData[root].right_child != 0) post_order(treeData[root].right_child);
	cout<<treeData[root].keyValue<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n=1,key=0;
	while(cin>>key)
	{
		treeData[n].keyValue = key;
		if(n > 1) insertTree(1,n,key);
		n++;
	} 
	post_order(1);
	return 0;
}
