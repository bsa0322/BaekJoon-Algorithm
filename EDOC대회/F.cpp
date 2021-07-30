#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s[151];
int revs[151];
int l[151];
int main()
{
	int t,n,chk=1,chk2;
	cin>>t;
	while(t--)
	{
		chk=1;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>s[i];	
			l[i]=s[i].length()-1;
		}
		s[n][0]='Z';
		while(1)
		{
			chk2=chk;
			if(chk==-1)
			{
				for(int i=n-1;i>=0;i--)
				{
					if(i==0)
					{
						if(s[i][0] <= s[i+1][0]) continue;
						else
						{
							if(revs[i]==0) revs[i]=1;
							else revs[i]=0;
							reverse(s[i].begin(),s[i].end());
							if(s[i+1][0] < s[i][0]) chk=1;
						}
					}
					else
					{
						if(s[i][0] >= s[i-1][0] && s[i][0] <= s[i+1][0]) continue;
						if(s[i][0] > s[i+1][0])
						{
							if(revs[i]==0) revs[i]=1;
							else revs[i]=0;
							reverse(s[i].begin(),s[i].end());
							if(s[i+1][0] < s[i][0]) chk=1;
						}	
					}
				}
			}
			else
			{
				for(int i=1;i<n;i++)
				{
					if(s[i][0] >= s[i-1][0] && s[i][0] <= s[i+1][0]) continue;
					if(s[i][0] < s[i-1][0])
					{
						if(revs[i]==0) revs[i]=1;
						else revs[i]=0;
						reverse(s[i].begin(),s[i].end());	
						if(s[i-1][0] > s[i][0]) chk=-1;
					}	
				}
			}
			if(chk == chk2) break;	
		}
		for(int i=0;i<n;i++)
		{
			cout<<revs[i];
			revs[i]=0;
		}
		cout<<'\n';
	}
	return 0;
}
