#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int i, j, k, l, n, m, ans=0;
	int A[51][51] = { 0, };
	int B[51][51] = { 0, };
	cin >> n >> m;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) scanf("%1d", &A[i][j]);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) scanf("%1d", &B[i][j]);
	for (i = 0; i <= n - 3; i++)
	{
		for (j = 0; j <= m - 3; j++)
		{
			if (A[i][j] != B[i][j])
			{
				ans++;
				for (k = i; k < i + 3; k++)
				{
					for (l = j; l < j + 3; l++)
					{
						if (A[k][l] == 1) A[k][l] = 0;
						else A[k][l] = 1;
					}
				}
			}
		}
	}
	for (i = n - 3; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (A[i][j] != B[i][j])
			{
				ans = -1;
				break;
			}
		}
		if (ans == -1) break;
	}
	cout << ans << '\n';
	return 0;
}
