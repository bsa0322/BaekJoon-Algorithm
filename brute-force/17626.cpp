//17626 For Squares 배수아 
#include<iostream>
#include<cmath>
using namespace std;
int jaegup[224];
int table[50001];
int main()
{
	int n, st;
	cin>>n;
	//최대 50000이므로 50000보다 작은 제곱수 먼저 저장 
	for(int i=1;i<224;i++)
	{
		jaegup[i]=i*i;
	}
	table[1]=1;
	for(int i=2;i<=n;i++)
	{
		table[i] = 100;
		st = (int)sqrt(i);
		for(int j=st;j>=1;j--) //현재 수의 최대 제곱수부터 시작해서 dp 돌리기 
		{
			if(table[i] > table[i-j*j]+1)
			{
				table[i] = table[i-j*j]+1;
 			}
		}
	}
	cout<<table[n]<<'\n';
	return 0;
}
