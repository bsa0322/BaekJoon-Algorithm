#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> ci;

int cntEmploy(int n, vector <ci> rank)
{
	//�����ɻ簡 1���� 0�� �ε��� ����� ������ �հ��̹Ƿ� 1������ �˻� 
	//���� �ε��� ����� �켱 �����ɻ�� �Ʒ� ����麸�� ������ ��
	//���� �� �� ����麸�� �����ɻ簡 ������ �հ� 
	int ans=1, mx=rank[0].second;
    for(int i=1;i<n;i++)
    {
    	//�� ��� �� ���� ���� ���� ������ ���� ��� �հ� 
    	if(mx > rank[i].second) 
    	{
    		//���� ���� �����ɻ� ��� �����ؼ� �ݺ��� 1ȸ�� ����
            mx=rank[i].second;
            ans++;
        }
    }
    return ans;
}

int main()
{
	int t, n, ans;
	vector <ci> rank;
    
    //�Է� 
    cin>>t;
    while(t--)
    {
        cin>>n;
        rank.assign(n, ci(0,0));
        for(int i = 0; i < n; i++)
            cin>>rank[i].first>>rank[i].second;
        
		//����
		//first���� �����ɻ� ���� �������� ����
		//���� �������� �����̹Ƿ� cmp�Լ� �ʿ� ����    
        sort(rank.begin(),rank.end());
        ans = cntEmploy(n, rank);
        
        //��� 
        cout<<ans<<'\n';
    }
    return 0;
}
