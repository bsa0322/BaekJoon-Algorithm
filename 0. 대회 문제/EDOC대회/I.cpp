#include<iostream>
using namespace std;
int check[4][13];
int checkf[13];
int checkm[13];
int main()
{
	//freopen("input.txt","r",stdin);
	cin.tie(0);
	char s,ans;
	int a,b,c,d,e,f,g,h,id,cnt=0,chk=0,mdchk;
	for(int i=1;i<=3;i++)
	{
		cin>>a>>b>>c>>d>>s>>e>>f>>g>>h;
		if(s=='<')
		{
			check[i][a]--;
			check[i][b]--;
			check[i][c]--;
			check[i][d]--;
			check[i][e]++;
			check[i][f]++;
			check[i][g]++;
			check[i][h]++;
			checkf[a]--;
			checkf[b]--;
			checkf[c]--;
			checkf[d]--;
			checkf[e]++;
			checkf[f]++;
			checkf[g]++;
			checkf[h]++;
		}
		else if(s=='>')
		{
			check[i][a]++;
			check[i][b]++;
			check[i][c]++;
			check[i][d]++;
			check[i][e]--;
			check[i][f]--;
			check[i][g]--;
			check[i][h]--;
			checkf[a]++;
			checkf[b]++;
			checkf[c]++;
			checkf[d]++;
			checkf[e]--;
			checkf[f]--;
			checkf[g]--;
			checkf[h]--;
		}
	}
	for(int i=1;i<=3;i++)
	{
		for(int k=i-1;k>0;k--)
		{
			mdchk=0;
			for(int j=1;j<=12;j++)
			{
				checkm[j]=check[k][j] + check[i][j];
				if(check[k][j]!=0 && check[i][j]!=0 && checkm[j]==0) mdchk++;
			}
			if(mdchk >= 4)
			{
				chk=1;
				break;
			}
		}
		if(chk==1) break;
	}
	for(int i=1;i<=12;i++)
	{
		if(checkf[i]==3)
		{
			ans='+';
			id=i;
			cnt++;
		}
		else if(checkf[i]==-3)
		{
			ans='-';
			id=i;
			cnt++;
		}
	}
	if(chk)
	{
		cout<<"impossible\n";
	}
	else
	{
		if(cnt==0 || cnt > 1)
		{
			cout<<"indefinite\n";
		}
		else if(cnt == 1)
		{
			cout<<id<<ans<<'\n';
		}
	}
	return 0;
}
