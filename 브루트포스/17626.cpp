//17626 For Squares ����� 
#include<iostream>
#include<cmath>
using namespace std;
int jaegup[224];
int table[50001];
int main()
{
	int n, st;
	cin>>n;
	//�ִ� 50000�̹Ƿ� 50000���� ���� ������ ���� ���� 
	for(int i=1;i<224;i++)
	{
		jaegup[i]=i*i;
	}
	table[1]=1;
	for(int i=2;i<=n;i++)
	{
		table[i] = 100;
		st = (int)sqrt(i);
		for(int j=st;j>=1;j--) //���� ���� �ִ� ���������� �����ؼ� dp ������ 
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
