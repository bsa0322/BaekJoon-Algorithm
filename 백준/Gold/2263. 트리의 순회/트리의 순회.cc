#include <iostream>
using namespace std;
int inOrder[100001], postOrder[100001];
int idx[100001];
void preOrder(int inBegin, int inEnd, int postBegin, int postEnd)
{      
	if (inBegin > inEnd || postBegin > postEnd)
	{
		return;
	}
	int root = postOrder[postEnd];
    cout << root << " ";
	preOrder(inBegin, idx[root] - 1, postBegin, postBegin + (idx[root] - inBegin) - 1);
	preOrder(idx[root] + 1, inEnd, postBegin + (idx[root] - inBegin), postEnd - 1);
}
int main(void)
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);        
	int N;
    cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> inOrder[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> postOrder[i];
	}
	for (int i = 0; i < N; i++)
	{
		idx[inOrder[i]] = i;
	}
	preOrder(0, N - 1, 0, N - 1);
	cout << "\n";
	return 0;
}
