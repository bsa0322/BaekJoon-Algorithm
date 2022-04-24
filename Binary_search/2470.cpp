//����� c++ 2470 
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long int liquid[100010];
int main()
{
	long long int n, l, r, sum, ans=10000000000, id1, id2;
	//ans���� �� ����� ���� �� 0�� �� ����� ���� ����� ������ �ϴ� �ƽøذ����� �ʱ�ȭ 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>liquid[i];
	}
	sort(liquid,liquid+n); //��� ������������ ���� 
	l = 0; 
	r = n-1;
	//����� �ּڰ��� �ִ밪���� �˻� 
	while(l < r) //l�� r���� �������ȸ� ���� 
	{
		sum = liquid[l] + liquid[r];
		if(abs(sum) < abs(ans)) //sum�� ans���� 0�� �� ������ ans ���� 
		{
			ans = sum;
			id1 = l; //����ϱ� ���� index ���� 
			id2 = r; //����ϱ� ���� index ���� 
		}
		
		if(sum < 0) l++; //sum�� 0���� �۴ٸ� 0�� �� �������� sum�� Ŀ���� �ϹǷ� l�� ���� 
		else r--; //sum�� 0���� ũ�ų����ٸ� 0�� �� �������� sum�� �۾����� �ϹǷ� r�� ���� 
	}
	cout<<liquid[id1]<<' '<<liquid[id2]<<'\n';
	return 0;
}
