#include<iostream>
#include<algorithm>
#include<deque>
#include<cmath>
using namespace std;
deque <int> dq[200001];
int num[200001];
int check[100001];
int main()
{
	int n,k,l=0,cnt=0,r,id,a,b, ans=0, ct;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
		check[num[i]]++;
		dq[num[i]].push_back(i);
	}
	r=n-1;
	while(l<=r)
	{
		cnt=0;
		for(int i=l;i<=r;i++)
		{
			if(cnt < check[num[i]]){
				cnt = check[num[i]];
				id=i;
			} 
		}
		if(cnt == k)
		{
			break;
		}
		else if(cnt > k)
		{
			ct=cnt-k;
			while(1)
			{
				if(dq[num[id]].front() < l) dq[num[id]].pop_front();
				else
				{
					a=dq[num[id]].front()-l;
					dq[num[id]].pop_front();
					ct--;
				}
				if(ct==0) break;
			}
			ct=cnt-k;
			while(1)
			{
				if(dq[num[id]].back() > r) dq[num[id]].pop_back();
				else
				{
					b=r-dq[num[id]].back();
					dq[num[id]].pop_back();
					ct--;
				}
				if(ct==0) break;
			}
			if(a < b)
			{
				for(int i=l;i<=l+a;i++)
					check[num[i]]--;
				l=l+a+1;
			}
			else 
			{
				for(int i=r;i>=r-b;i--)
					check[num[i]]--;
				r=r-b-1;
			}
		}
	}
	ans = r-l+1;
	cout<<ans<<'\n';
	return 0;
}
