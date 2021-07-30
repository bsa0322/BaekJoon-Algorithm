#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
stack <int> st;
vector <int> T;
vector <int> v[1010];
char lr[1000];
int n,m,k;
int check[1010];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int l,r,t,chk=0,idx,start,x,startidx,cnt;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>l>>r;
		v[i].push_back(l);
		v[i].push_back(r);
	}
	for(int i=0;i<m;i++)
	{
		cin>>lr[i];
	}
	st.push(1);
	for(int j=0;j<k;j++)
	{
		for(int i=0;i<m;i++)
		{
			t=st.top();
			st.pop();
			if(i==0)
			{
				if(check[t] == 1)
				{
					start = t;
					chk=1;
					break;
				}
				check[t]=1;
			}
			if(lr[i] == 'L')
			{
				st.push(v[t][0]);
				if(i==(m-1)) T.push_back(v[t][0]);
			}
			else
			{
				st.push(v[t][1]);
				if(i==(m-1)) T.push_back(v[t][1]);
			}
		}	
		if(chk == 1) break;
	}
	if(chk==1)
	{
		for(int i=0;i<T.size();i++)
		{
			if(T[i] == start)
			{
				startidx=i;
				break;
			}
		}
		cnt = T.size()-startidx;
		idx = k%(cnt);	
		if (idx == 0) idx = cnt;
		idx += startidx;
		cout<<T[idx-1]<<'\n';
	}
	else cout<<st.top()<<'\n';
	return 0;
}
