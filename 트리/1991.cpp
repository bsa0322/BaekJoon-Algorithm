#include<iostream>
using namespace std;
struct binaryTree{
	char par;
	char left_child, right_child;
}treeData[50];
void pre_order(char root)
{
	cout<<root;
	if(treeData[root-65].left_child != '.') pre_order(treeData[root-65].left_child);
	if(treeData[root-65].right_child != '.') pre_order(treeData[root-65].right_child);
}
void in_order(char root)
{
	if(treeData[root-65].left_child != '.') in_order(treeData[root-65].left_child);
	cout<<root;
	if(treeData[root-65].right_child != '.') in_order(treeData[root-65].right_child);
}
void post_order(char root)
{
	if(treeData[root-65].left_child != '.') post_order(treeData[root-65].left_child);
	if(treeData[root-65].right_child != '.') post_order(treeData[root-65].right_child);
	cout<<root;
}
int main()
{
	char N,L,R;
	int n, node;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>N>>L>>R;
		node = (N-65);
		treeData[node].left_child = L;
		treeData[node].right_child = R;
		if(L != '.') treeData[L-65].par = N;
		if(R != '.') treeData[R-65].par = N;
	}
	pre_order('A');
	cout<<'\n';
	in_order('A');
	cout<<'\n';
	post_order('A');
	cout<<'\n';
	return 0;
}
