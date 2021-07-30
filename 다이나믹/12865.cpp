//����� c++ 12865 
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
typedef pair<int,int> ci;
vector <ci> bak; //������ ���Կ� ��ġ�� �� ���� 
int table[100010]; //���԰� �ε����� �� ������ �� �ִ� ��ġ�� �� ���̳��� �迭 
int main()
{
	ci t;
	int n,k,w,v,ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>w>>v;
		bak.push_back(ci(w,v));
	}
	sort(bak.begin(),bak.end()); //���� ���� �ͺ��� ���� 
	for(int i=0;i<=k;i++) table[i] = -1; //�� ���Ը�ŭ ������ ���ϴ� ��쵵 �����Ƿ� �ϴ� -1�� �ʱ�ȭ 
	table[0] = 0; //���԰� 0�� ���� ��ġ�� 0���� �ʱ�ȭ 
	for(int i=0;i<n;i++)
	{
		t = bak[i]; //i��° ��ǰ 
		for(int j=k-1;j>=0;j--) //�Ųٷ� �˻��ϴ� ������ �ߺ��Ǵ� ��츦  �����ϱ� ���� 
		{
			//�� ���Ը� ����� ���� �ϴ� �����ϰ�, �ִ빫�� k���� �۰ų� ������� ���� 
			if(table[j] >= 0 && j+t.first <= k) 
			{
				table[j+t.first] = max(table[j+t.first], table[j]+t.second); 
				//���� j+t.first���Կ����� ��ġ�� j������ ��ġ�� i��° ��ǰ�� ��ġ�� ���� �� �� max���� ���� 
				ans = max(ans, table[j+t.first]);
				//ans �� ����� table[j+t.first] �� ū�� ���� 
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
