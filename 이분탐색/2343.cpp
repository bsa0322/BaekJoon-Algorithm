//����� c++ 2343 
#include<iostream>
using namespace std;
long long int lesson[100010];
int main()
{
	long long int n,m,l=0,r=0,mid=0,cnt,sum,chk,ans;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>lesson[i];
		r+=lesson[i];
	}
	//��� ������ ���� ������ ������ �̺�Ž�� ����
	//�̺�Ž���� �� ���� ��緹���� ũ���� 
	while(l <= r)
	{	
		mid = (l+r)/2; // ���� ��緹���� ũ�� (l��r�� �߰���) 
		chk=0; // ��緹���� ũ�⺸�� �� ������ �뷮�� ū ��� �Ǵ��ϱ����� üũ���� 
		cnt=0; // ���� ��緹�̷� ��������� �׷� �� ī��Ʈ ���� 
		sum=0; // �׷� �� ������ ���� �׷� �� ���� �� ���� ���� 
		for(int i=0;i<n;i++)
		{
			if(lesson[i] > mid) 
			{
				chk = 1;
				break;
			}
			sum+=lesson[i];
			if(sum > mid)
			{
				sum = lesson[i];
				cnt++;
			}
		}
		if(sum <= mid) cnt++; 
		else cnt+=2;
		
		/*���� ��緹�̷� ��������� �׷��� �������� �䱸�ϴ� �׷�(m)���� ũ�ų�
		��緹���� ũ�⺸�� �� ������ �뷮�� ū ��� ���� �� ��緹���� ũ�⸦
		Ű���� �ϹǷ� l�� ����*/  
		if(cnt > m || chk == 1) 
		{
			l = mid+1;
		} 
		
		/*���� ��緹�̷� ��������� �׷��� m���� �۰ų� ���� ��� 
		��緹���� ũ�⸦ �ٿ��� �ϹǷ� r�� ����*/ 
		else
		{
			r = mid-1;
			ans = mid; //m�� ���� ��쵵 ���ԵǹǷ� ans���� ���⼭ ��� ���� 
		}
		
	}
	
	cout<<ans<<'\n';
	return 0;
}
