#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> ci;
queue <ci> q;
int mp[100][100];
int main()
{
	ci t;
	int i,j,x,y,w,h,ans=0,tx,ty;
	int dx[8]={-1,1,0,0,-1,-1,1,1}, dy[8]={0,0,-1,1,-1,1,-1,1};
	while(1)
	{
		ans=0;
		cin>>w>>h;
		if(w==0 && h==0) break;
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				cin>>mp[i][j];
			}
		}
		q = queue <ci>();
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
			{
				if(mp[i][j]==1)
				{
					mp[i][j]=0;
					ans++;
					q.push(ci(i,j));
					while(!q.empty())
					{
						t=q.front();
						q.pop();
						x=t.first;
						y=t.second;
						for(int k=0;k<8;k++)
						{
							tx=x+dx[k];
							ty=y+dy[k];
							if(tx>=0 && tx<h && ty>=0 && ty<w && mp[tx][ty]==1)
							{
								mp[tx][ty]=0;
								q.push(ci(tx,ty));
							}
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
