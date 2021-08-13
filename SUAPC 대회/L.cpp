#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef pair<int,int> ci;
vector <ci> v,v2;
char mp[2001][2001];
int check[2001][2001];
int main()
{
//	freopen("input.txt","r",stdin);
	cin.tie(0);
	string s;
	int n,x,y;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		for(int j=0;j<n;j++)
		{
			mp[i][j]=s[j];
			if(mp[i][j]=='X')
			{
				v.push_back(ci(i,j));
			}
			else if(mp[i][j]=='O')
			{
				v2.push_back(ci(i,j));
			}
		}
	}
	for(int i=0;i<v2.size();i++)
	{
		x=v2[i].first;
		y=v2[i].second;
		for(int k=x-1;k>=0;k--)
		{
			if(mp[k][y]=='.')
			{
				check[k][y]=-1;
			}
			else break;
		}	
		for(int k=x+1;k<n;k++)
		{
			if(mp[k][y]=='.')
			{
				check[k][y]=-1;
			}
			else break;
		}
		for(int k=y-1;k>=0;k--)
		{
			if(mp[x][k]=='.')
			{
				check[x][k]=-1;
			}
			else break;	
		}
		for(int k=y+1;k<n;k++)
		{
			if(mp[x][k]=='.')
			{
				check[x][k]=-1;
			}
			else break;
		}
	}
	for(int i=0;i<v.size();i++)
	{
		x=v[i].first;
		y=v[i].second;
		for(int k=x-1;k>=0;k--)
		{
			if(mp[k][y]=='.')
			{
				if(check[k][y]==0)
				{
					check[k][y]=1;
					mp[k][y]='B';
				}
			}
			else break;
		}
		for(int k=x+1;k<n;k++)
		{
			if(mp[k][y]=='.')
			{
				if(check[k][y]==0)
				{
					check[k][y]=1;
					mp[k][y]='B';
				}
			}
			else break;
		}
		for(int k=y-1;k>=0;k--)
		{
			if(mp[x][k]=='.')
			{
				if(check[x][k]==0)
				{
					check[x][k]=1;
					mp[x][k]='B';
				}
			}
			else break;
		}
		for(int k=y+1;k<n;k++)
		{
			if(mp[x][k]=='.')
			{
				if(check[x][k]==0)
				{
					check[x][k]=1;
					mp[x][k]='B';
				}
			}
			else break;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<mp[i][j];
		}
		cout<<'\n';
	}
	return 0;
}
